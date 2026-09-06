package dashboardapi

import (
	"encoding/json"
	"io/ioutil"
	"log"
	"net/http"
)

type errorResponse struct {
	Description string `json:"description"`
}

func sendError(w http.ResponseWriter, code int, msg string) {
	resp := response{
		Status: code,
		Error:  errorResponse{msg},
	}
	json.NewEncoder(w).Encode(resp)
}

func sendReponse(w http.ResponseWriter, code int, data interface{}) {
	resp := response{
		Status: code,
		Data:   data,
	}
	json.NewEncoder(w).Encode(resp)
}

func checkErrorSQL(w http.ResponseWriter, err error) bool {
	if err != nil {
		log.Println(err)
		sendError(w, 500, "Internal server error")
		return true
	}
	return false
}

func checkRequestParameter(w http.ResponseWriter, r *http.Request, data interface{}) bool {
	rdata, err := ioutil.ReadAll(r.Body)
	if err != nil {
		sendError(w, 501, "Failed to get request")
		return false
	}
	err = json.Unmarshal(rdata, data)
	if err != nil {
		sendError(w, 400, err.Error())
		return false
	}
	return true
}
