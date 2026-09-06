package dashboardapi

import (
	"io/ioutil"
	"net/http"
)

type responseAboutSave struct {
	Dashboard string `json:"dashboard"`
}

func aboutSavePage(w http.ResponseWriter, r *http.Request) {
	var request responseAboutSave

	if !checkRequestParameter(w, r, &request) {
		return
	}
	_ = ioutil.WriteFile("about.json", []byte(request.Dashboard), 0644)
	sendReponse(w, 200, responseAboutSave{""})
}
