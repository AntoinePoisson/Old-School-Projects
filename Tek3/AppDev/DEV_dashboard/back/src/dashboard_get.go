package dashboardapi

import (
	"net/http"
)

type responseDashboardGet struct {
	Dashboard string `json:"dashboard"`
}

type requestDashboardGet struct {
	Token string `json:"token"`
}

func dashboardGetPage(w http.ResponseWriter, r *http.Request) {
	var request requestDashboardGet

	if !checkRequestParameter(w, r, &request) {
		return
	}
	db := connectToDB()
	id, err := getUserIDFromToken(db, request.Token)
	if checkErrorSQL(w, err) {
		return
	}
	res, err := db.Query("SELECT `dashboard` FROM `dashboard` WHERE user_id = ?", id)
	if err != nil {
		sendReponse(w, 200, responseDashboardGet{""})
		return
	}
	if res.Next() {
		var config string
		res.Scan(&config)
		sendReponse(w, 200, responseDashboardGet{config})
	} else {
		sendReponse(w, 200, responseDashboardGet{""})
	}
}
