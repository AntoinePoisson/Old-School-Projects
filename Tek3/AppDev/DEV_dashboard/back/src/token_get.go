package dashboardapi

import (
	"net/http"
)

type responseTokenGet struct {
	Tokens string `json:"tokens"`
}

func tokenGetPage(w http.ResponseWriter, r *http.Request) {
	var request requestDashboardGet

	if !checkRequestParameter(w, r, &request) {
		return
	}
	db := connectToDB()
	id, err := getUserIDFromToken(db, request.Token)
	if checkErrorSQL(w, err) {
		return
	}
	res, err := db.Query("SELECT `tokens` FROM `tokens` WHERE user_id = ?", id)
	if err != nil {
		sendReponse(w, 200, responseTokenGet{""})
		return
	}
	if res.Next() {
		var config string
		res.Scan(&config)
		sendReponse(w, 200, responseTokenGet{config})
	} else {
		sendReponse(w, 200, responseTokenGet{""})
	}
}
