package dashboardapi

import (
	"io/ioutil"
	"net/http"
)

type requestGetYtb struct {
	Request string `json:"request"`
	Bearer  string `json:"bearer"`
}

func ytbPage(w http.ResponseWriter, r *http.Request) {
	var request requestGetYtb

	if !checkRequestParameter(w, r, &request) {
		return
	}
	req, err := http.NewRequest("GET", request.Request, nil)
	if err != nil {
		sendError(w, 501, "Failed to get ytb")
		return
	}
	req.Header.Set("Authorization", "Bearer "+request.Bearer)
	client := &http.Client{}
	resp, err := client.Do(req)
	if err != nil {
		sendError(w, 501, "Failed to get ytb")
		return
	}
	body, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		sendError(w, 501, "Failed to get ytb")
		return
	}
	w.Write(body)
}
