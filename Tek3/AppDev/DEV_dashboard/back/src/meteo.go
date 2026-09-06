package dashboardapi

import (
	"io/ioutil"
	"net/http"
)

type requestGetMeteo struct {
	Request string `json:"request"`
}

func meteoPage(w http.ResponseWriter, r *http.Request) {
	var request requestGetMeteo

	if !checkRequestParameter(w, r, &request) {
		return
	}
	resp, err := http.Get(request.Request)
	if err != nil {
		sendError(w, 501, "Failed to get meteo")
		return
	}
	body, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		sendError(w, 501, "Failed to get meteo")
		return
	}
	w.Write(body)
}
