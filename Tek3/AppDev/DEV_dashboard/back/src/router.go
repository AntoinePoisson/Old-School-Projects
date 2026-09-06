package dashboardapi

import (
	"log"
	"net/http"
	"time"

	"github.com/gorilla/mux"
)

func logger(inner http.Handler, name string) http.Handler {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		start := time.Now()

		inner.ServeHTTP(w, r)

		log.Printf(
			"%s\t%s\t%s\t%s\n",
			r.Method,
			r.RequestURI,
			name,
			time.Since(start),
		)
	})
}

func middleware(next http.Handler) http.Handler {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		w.Header().Set("Content-Type", "application/json")
		w.Header().Set("Access-Control-Allow-Origin", "*")
		w.Header().Set("Access-Control-Allow-Methods", "POST, GET, OPTIONS, PUT, DELETE")
		w.Header().Set("Access-Control-Allow-Headers", "Accept, Content-Type, Content-Length, Accept-Encoding, X-CSRF-Token, Authorization")
		if r.Method != "OPTIONS" {
			next.ServeHTTP(w, r)
		} else {
			log.Printf(
				"%s\t%s\n",
				r.Method,
				r.RequestURI,
			)
		}
	})
}

func registerEndpoints(router *mux.Router) {
	router.Use(middleware)
	for _, elem := range srvRoutes {
		var handler http.Handler = elem.HandlerFunc
		handler = logger(handler, elem.Name)
		router.Methods(elem.Method, "OPTIONS").Path(elem.Pattern).Name(elem.Name).Handler(handler)
	}
}
