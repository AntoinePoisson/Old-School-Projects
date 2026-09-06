package dashboardapi

import (
	"io/ioutil"
	"net/http"
)

type requestGettwitch struct {
	Request string `json:"request"`
	OAuth   string `json:"oauth"`
	Client  string `json:"client"`
}

func twitchPage(w http.ResponseWriter, r *http.Request) {
	var request requestGettwitch

	if !checkRequestParameter(w, r, &request) {
		return
	}
	req, err := http.NewRequest("GET", request.Request, nil)
	if err != nil {
		sendError(w, 501, "Failed to get twitch")
		return
	}
	req.Header.Set("Authorization", "Bearer "+request.OAuth)
	req.Header.Set("client-id", request.Client)
	req.Header.Set("Accept", "*/*")
	client := &http.Client{}
	resp, err := client.Do(req)
	if err != nil {
		sendError(w, 501, "Failed to get twitch")
		return
	}
	body, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		sendError(w, 501, "Failed to get twitch")
		return
	}
	w.Write(body)
}
