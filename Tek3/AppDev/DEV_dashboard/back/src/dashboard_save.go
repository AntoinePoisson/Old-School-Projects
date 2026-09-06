package dashboardapi

import (
	"encoding/json"
	"net/http"
)

type requestDashboardSave struct {
	Token  string `json:"token"`
	Config string `json:"config"`
}

func dashboardSavePage(w http.ResponseWriter, r *http.Request) {
	var request requestDashboardSave
	response := response{Status: 200}

	if !checkRequestParameter(w, r, &request) {
		return
	}
	db := connectToDB()
	id, err := getUserIDFromToken(db, request.Token)
	if checkErrorSQL(w, err) {
		return
	}
	_, err = db.Query("INSERT INTO dashboard (user_id, dashboard) VALUES(?, ?) ON DUPLICATE KEY UPDATE dashboard = ?", id, request.Config, request.Config)
	if checkErrorSQL(w, err) {
		return
	}
	json.NewEncoder(w).Encode(response)
}
