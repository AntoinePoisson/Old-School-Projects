package dashboardapi

import (
	"database/sql"
	"math/rand"
)

func getUserID(db *sql.DB, email string) (id int, err error) {
	res, err := db.Query("SELECT `id` FROM `user` WHERE email = ?;", email)
	if err != nil {
		return
	}
	for res.Next() {
		err = res.Scan(&id)
	}
	return
}

func getUserIDFromToken(db *sql.DB, token string) (id int, err error) {
	res, err := db.Query("SELECT `user_id` FROM `auto_login` WHERE token = ?;", token)
	if err != nil {
		return
	}
	for res.Next() {
		err = res.Scan(&id)
	}
	return
}

func createVerifCode(length int) string {
	charset := "0123456789"
	b := make([]byte, length)
	for i := range b {
		b[i] = charset[rand.Intn(len(charset))]
	}
	return string(b)
}
