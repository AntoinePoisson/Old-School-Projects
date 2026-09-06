package dashboardapi

import (
	"net/http"
)

type Route struct {
	Name        string
	Method      string
	Pattern     string
	HandlerFunc http.HandlerFunc
}

type Routes []Route

var srvRoutes = Routes{
	Route{Name: "Home", Method: "POST", Pattern: "/", HandlerFunc: homePage},
	Route{Name: "Login", Method: "POST", Pattern: "/login", HandlerFunc: loginPage},
	Route{Name: "Register", Method: "POST", Pattern: "/register", HandlerFunc: registerPage},
	Route{Name: "Check code", Method: "POST", Pattern: "/check-code", HandlerFunc: checkCodePage},
	Route{Name: "Dashboard get", Method: "POST", Pattern: "/dashboard/get", HandlerFunc: dashboardGetPage},
	Route{Name: "Dashboard save", Method: "POST", Pattern: "/dashboard/save", HandlerFunc: dashboardSavePage},
	Route{Name: "Meteo", Method: "POST", Pattern: "/meteo", HandlerFunc: meteoPage},
	Route{Name: "Token get", Method: "POST", Pattern: "/token/get", HandlerFunc: tokenGetPage},
	Route{Name: "Token save", Method: "POST", Pattern: "/token/save", HandlerFunc: tokenSavePage},
	Route{Name: "About.json get", Method: "GET", Pattern: "/about/get", HandlerFunc: aboutGetPage},
	Route{Name: "About.json get", Method: "GET", Pattern: "/about.json", HandlerFunc: aboutGetPageNOResult},
	Route{Name: "About.json save", Method: "POST", Pattern: "/about/save", HandlerFunc: aboutSavePage},
	Route{Name: "ytb", Method: "POST", Pattern: "/ytb", HandlerFunc: ytbPage},
	Route{Name: "twitch", Method: "POST", Pattern: "/twitch/tricks", HandlerFunc: twitchPage},
}
