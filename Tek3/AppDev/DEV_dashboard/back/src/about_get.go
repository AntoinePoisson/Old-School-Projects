package dashboardapi

import (
	"encoding/json"
	"io/ioutil"
	"log"
	"net/http"
	"strings"
	"time"
)

type responseAboutGet struct {
	Dashboard string `json:"dashboard"`
}

type aboutCustomer struct {
	Host string `json:"host"`
}

type aboutParam struct {
	Name string `json:"name"`
	Type string `json:"type"`
}

type aboutParams []aboutParam

type aboutWidget struct {
	Name        string      `json:"name"`
	Description string      `json:"description"`
	NeedServer  string      `json:"need_server"`
	Params      aboutParams `json:"params"`
}

type aboutWidgets []aboutWidget

type aboutService struct {
	Name      string       `json:"name"`
	NeedToken string       `json:"need_token"`
	Size      int          `json:"size"`
	Widgets   aboutWidgets `json:"widgets"`
}

type aboutServices []aboutService

type aboutServer struct {
	CurrentTime int64         `json:"current_time"`
	Services    aboutServices `json:"services"`
}

type aboutJSON struct {
	Customer aboutCustomer `json:"customer"`
	Server   aboutServer   `json:"server"`
}

func aboutGetPage(w http.ResponseWriter, r *http.Request) {

	file, _ := ioutil.ReadFile("about.json")
	var aboutjs aboutJSON
	err := json.Unmarshal(file, &aboutjs)
	if err != nil {
		log.Println(err)
	}
	aboutjs.Server.CurrentTime = time.Now().Unix()
	aboutjs.Customer.Host = strings.Split(r.RemoteAddr, ":")[0]
	sendReponse(w, 200, aboutjs)
}

func aboutGetPageNOResult(w http.ResponseWriter, r *http.Request) {

	file, _ := ioutil.ReadFile("about.json")
	var aboutjs aboutJSON
	err := json.Unmarshal(file, &aboutjs)
	if err != nil {
		log.Println(err)
	}
	aboutjs.Server.CurrentTime = time.Now().Unix()
	aboutjs.Customer.Host = strings.Split(r.RemoteAddr, ":")[0]
	json.NewEncoder(w).Encode(aboutjs)
}
