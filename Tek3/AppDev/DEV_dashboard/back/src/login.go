package dashboardapi

import (
	"log"
	"net/http"

	"golang.org/x/crypto/bcrypt"
)

type requestLogin struct {
	Email    string `json:"email"`
	Password string `json:"password"`
}

type loginResponse struct {
	Token string `json:"token"`
}

func comparePasswords(hashedPwd string, plainPwd string) bool {
	byteHash := []byte(hashedPwd)
	err := bcrypt.CompareHashAndPassword(byteHash, []byte(plainPwd))
	if err != nil {
		log.Println(err)
		return false
	}
	return true
}

func loginPage(w http.ResponseWriter, r *http.Request) {
	var request requestLogin

	if !checkRequestParameter(w, r, &request) {
		return
	}
	db := connectToDB()
	id, err := getUserID(db, request.Email)
	if err != nil {
		log.Println(err)
		sendError(w, 407, "Invalid email or password")
		return
	}
	res, err := db.Query("SELECT `password` FROM `user` WHERE id = ?", id)
	if checkErrorSQL(w, err) {
		return
	}
	var hashPass string
	res.Next()
	res.Scan(&hashPass)
	if !comparePasswords(hashPass, request.Password) {
		sendError(w, 407, "Invalid email or password")
		return
	}
	res, err = db.Query("SELECT `token` FROM `auto_login` WHERE user_id = ?", id)
	if checkErrorSQL(w, err) {
		return
	}
	var uuid string
	res.Next()
	res.Scan(&uuid)
	sendReponse(w, 200, loginResponse{uuid})
}
