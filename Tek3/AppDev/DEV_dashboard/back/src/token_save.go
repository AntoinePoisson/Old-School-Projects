package dashboardapi

import (
	"encoding/json"
	"net/http"
)

type requestTokenSave struct {
	Token  string `json:"token"`
	Tokens string `json:"tokens"`
}

func tokenSavePage(w http.ResponseWriter, r *http.Request) {
	var request requestTokenSave
	response := response{Status: 200}

	if !checkRequestParameter(w, r, &request) {
		return
	}
	db := connectToDB()
	id, err := getUserIDFromToken(db, request.Token)
	if checkErrorSQL(w, err) {
		return
	}
	_, err = db.Query("INSERT INTO tokens (user_id, tokens) VALUES(?, ?) ON DUPLICATE KEY UPDATE tokens = ?", id, request.Tokens, request.Tokens)
	if checkErrorSQL(w, err) {
		return
	}
	json.NewEncoder(w).Encode(response)
}
