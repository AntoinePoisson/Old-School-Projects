# Tech doc

## Back endpoint

#### /login
Route for the login
```
{
    "user": "Usernaem",
    "password": "Password"
}
```

#### /register
Register route
```
{
    "user": "Usernaem",
    "email": "Email",
    "password": "Password"
}
```
#### /check_code
```
{
    "email": "email",
    "code": 123
}
```
#### /dashboard/get
```
{
    "email": "email",
    "code": 123
}
```

#### /dashboard/save
#### /meteo
```
{
    "city": "city"
}
```
#### /token/get
#### /token/save
#### /about.json