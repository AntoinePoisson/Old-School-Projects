package dashboardapi

import (
	"log"
	"net/http"

	"github.com/google/uuid"
)

type requestCheckCode struct {
	Email string `json:"email"`
	Code  string `json:"code"`
}

func checkCodePage(w http.ResponseWriter, r *http.Request) {
	var request requestCheckCode

	if !checkRequestParameter(w, r, &request) {
		return
	}
	db := connectToDB()
	id, err := getUserID(db, request.Email)
	if checkErrorSQL(w, err) {
		return
	}
	res, err := db.Query("SELECT `code` FROM `verif_code` WHERE user_id = ?", id)
	if checkErrorSQL(w, err) {
		return
	}
	var code string
	if !res.Next() {
		sendError(w, 406, "Account already verified")
		return
	}
	err = res.Scan(&code)
	if checkErrorSQL(w, err) {
		return
	}
	if code == request.Code {
		_, err = db.Query("DELETE FROM `verif_code` WHERE user_id = ?", id)
		if checkErrorSQL(w, err) {
			return
		}
		userID := uuid.New()
		log.Println(len(userID.String()))
		_, err = db.Query("INSERT INTO `auto_login` (`user_id`, `token`) VALUES (?, ?)", id, userID.String())
		if checkErrorSQL(w, err) {
			return
		}
		sendReponse(w, 200, loginResponse{userID.String()})
	} else {
		sendError(w, 405, "Invalid code")
	}
}
