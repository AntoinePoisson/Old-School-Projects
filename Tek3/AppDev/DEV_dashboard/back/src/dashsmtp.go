package dashboardapi

import (
	"log"
	"net/smtp"
)

type dashsmtp struct {
	auth     smtp.Auth
	smtpHost string
	smtpPort string
	user     string
}

func newSMTP(stmpHost string, smtpPort string, username string, password string) *dashsmtp {
	tmp := dashsmtp{
		auth:     smtp.PlainAuth("", username, password, stmpHost),
		smtpHost: stmpHost,
		smtpPort: smtpPort,
		user:     username,
	}
	return &tmp
}

func (d *dashsmtp) sendEmail(dest string, message string) {
	log.Println(d.smtpHost + ":" + d.smtpPort)
	log.Println(message)
	msg := []byte(message)
	err := smtp.SendMail(d.smtpHost+":"+d.smtpPort, d.auth, d.user, []string{dest}, msg)
	if err != nil {
		log.Print("Failed to send email: ")
		log.Println(err)
		return
	}
}
