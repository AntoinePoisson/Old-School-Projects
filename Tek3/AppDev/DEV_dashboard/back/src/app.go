package dashboardapi

import (
	"context"
	"encoding/json"
	"io/ioutil"
	"log"
	"net/http"
	"os"
	"os/signal"
	"strconv"
	"time"

	"github.com/gorilla/mux"
)

type response struct {
	Status int         `json:"status"`
	Data   interface{} `json:"result,omitempty"`
	Error  interface{} `json:"error,omitempty"`
}

type configFile struct {
	SMTPHost     string `json:"smtp_host"`
	SMTPPort     string `json:"smtp_port"`
	SMTPUser     string `json:"smtp_user"`
	SMTPPassword string `json:"smtp_password"`
}

var smtpData *dashsmtp

func homePage(w http.ResponseWriter, r *http.Request) {
	// fmt.Fprintf(w, "slt")
	// r.ParseForm()
}

func loadConfig(path string) configFile {
	data, err := ioutil.ReadFile(path)
	if err != nil {
		log.Panic(err)
	}
	var config configFile
	err = json.Unmarshal(data, &config)
	if err != nil {
		log.Panic(err)
	}
	return config
}

// StartAPI start the listener for the api
func StartAPI(port int) {
	var wait time.Duration
	var router *mux.Router = mux.NewRouter()
	config := loadConfig("setting.json")
	smtpData = newSMTP(config.SMTPHost, config.SMTPPort, config.SMTPUser, config.SMTPPassword)
	srv := &http.Server{
		Addr:         ":" + strconv.Itoa(port),
		WriteTimeout: time.Second * 15,
		ReadTimeout:  time.Second * 15,
		IdleTimeout:  time.Second * 60,
		Handler:      router,
	}
	registerEndpoints(router)
	connectToDB()

	log.Println("Starting dashboard api " + strconv.Itoa(port))

	go func() {
		if err := srv.ListenAndServe(); err != nil {
			log.Println(err)
		}
	}()

	c := make(chan os.Signal, 1)
	signal.Notify(c, os.Interrupt)
	<-c

	ctx, cancel := context.WithTimeout(context.Background(), wait)
	defer cancel()
	srv.Shutdown(ctx)
	log.Println("Shutting down dashboardapi")
}
