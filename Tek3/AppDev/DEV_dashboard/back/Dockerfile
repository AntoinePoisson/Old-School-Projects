FROM golang:latest as builder

WORKDIR /go/app
COPY . .
RUN go get -d -v ./...
RUN go build -o dashboard-server main.go
EXPOSE 8080


FROM golang:latest
COPY --from=builder /go/app/dashboard-server .
COPY --from=builder /go/app/setting.json .
COPY --from=builder /go/app/about.json .
CMD ["./dashboard-server"]