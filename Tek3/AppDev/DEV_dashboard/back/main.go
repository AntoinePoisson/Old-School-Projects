package main

import (
	"fmt"
	"os"

	dashboardapi "./src"
	"github.com/DavidGamba/go-getoptions"
)

func main() {
	opt := getoptions.New()

	port := opt.Int("port", 8080, opt.Description("API port"))
	_, err := opt.Parse(os.Args[1:])
	if opt.Called("help") {
		fmt.Fprintf(os.Stderr, opt.Help())
		os.Exit(1)
	}
	if err != nil {
		fmt.Fprintf(os.Stderr, "ERROR: %s\n\n", err)
		fmt.Fprintf(os.Stderr, opt.Help(getoptions.HelpSynopsis))
		os.Exit(1)
	}
	dashboardapi.StartAPI(*port)
}
