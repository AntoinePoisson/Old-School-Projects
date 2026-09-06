package dashboardapi

import (
	"database/sql"
	"log"

	// Import mysql driver
	_ "github.com/go-sql-driver/mysql"
)

func connectToDB() (db *sql.DB) {
	db, err := sql.Open("mysql", "user:password@tcp(db:3306)/db")
	if err != nil {
		log.Panic(err)
	}
	return
}
