package dashboardapi

import (
	"database/sql"
	"encoding/json"
	"log"
	"net/http"

	"github.com/google/uuid"
	"golang.org/x/crypto/bcrypt"
)

type requestRegister struct {
	Username string `json:"username"`
	Email    string `json:"email"`
	Password string `json:"password"`
	Code     bool   `json:"code"`
}

func checkEmail(w http.ResponseWriter, db *sql.DB, email string) bool {
	if email == "" {
		sendError(w, 401, "Empty email")
		return true
	}
	res, err := db.Query("SELECT * FROM user WHERE email = ?", email)
	defer res.Close()
	if checkErrorSQL(w, err) {
		return true
	}
	if res.Next() {
		sendError(w, 401, "Email "+email+" already use with an account")
		return true
	}
	return false
}

func checkEmailTwo(w http.ResponseWriter, db *sql.DB, email string) bool {
	if email == "" {
		sendError(w, 401, "Empty email")
		return true
	}
	res, err := db.Query("SELECT * FROM user WHERE email = ?", email)
	defer res.Close()
	if checkErrorSQL(w, err) {
		return true
	}
	if res.Next() {
		return true
	}
	return false
}

func checkUsername(w http.ResponseWriter, name string) bool {
	if name == "" {
		sendError(w, 402, "Empty username")
		return true
	}
	return false
}

func checkPassword(w http.ResponseWriter, password string) bool {
	if password == "" {
		sendError(w, 403, "Empty password")
		return true
	}
	return false
}

func generatePassword(password string) string {
	hash, err := bcrypt.GenerateFromPassword([]byte(password), bcrypt.DefaultCost)
	if err != nil {
		log.Println(err)
	}
	return string(hash)
}

func registerPage(w http.ResponseWriter, r *http.Request) {
	var request requestRegister
	response := response{Status: 200}

	if !checkRequestParameter(w, r, &request) {
		return
	}
	db := connectToDB()
	if request.Code {
		userID := uuid.New()
		stringID := userID.String()
		log.Println(len(userID.String()))
		if checkEmailTwo(w, db, request.Email) {
			id, err := getUserID(db, request.Email)
			res, err := db.Query("SELECT `token` FROM `auto_login` WHERE user_id = ?", id)
			if checkErrorSQL(w, err) {
				return
			}
			res.Next()
			res.Scan(&stringID)
		} else {
			_, err := db.Query("INSERT INTO `user` (`name`, `email`, `password`) VALUES (?, ?, ?);", request.Username, request.Email, generatePassword(request.Password))
			if checkErrorSQL(w, err) {
				return
			}
			id, err := getUserID(db, request.Email)
			if checkErrorSQL(w, err) {
				return
			}
			id, err = getUserID(db, request.Email)
			if checkErrorSQL(w, err) {
				return
			}
			_, err = db.Query("INSERT INTO `auto_login` (`user_id`, `token`) VALUES (?, ?)", id, stringID)
			if checkErrorSQL(w, err) {
				return
			}
		}
		sendReponse(w, 200, loginResponse{stringID})
	} else {
		if checkEmail(w, db, request.Email) {
			return
		}
		if checkUsername(w, request.Username) {
			return
		}
		if checkPassword(w, request.Password) {
			return
		}
		_, err := db.Query("INSERT INTO `user` (`name`, `email`, `password`) VALUES (?, ?, ?);", request.Username, request.Email, generatePassword(request.Password))
		if checkErrorSQL(w, err) {
			return
		}
		id, err := getUserID(db, request.Email)
		if checkErrorSQL(w, err) {
			return
		}
		code := createVerifCode(6)
		_, err = db.Query("INSERT INTO `verif_code` (`user_id`, `code`) VALUES (?, ?);", id, code)
		if checkErrorSQL(w, err) {
			return
		}
		smtpData.sendEmail(request.Email, "Your confirmation code for dashboard "+code)
		json.NewEncoder(w).Encode(response)
	}
}
