# Liste des routes

## Register un User

### POST /api/user/register

```json
{
    "email": "antoine123@gmail.com",
    "password": "Password123",
    "code": "A1234"
}
```

Il y a 2 code de device mis en brute dans le DB par défaut:

* A1234
* B1234

Return un Bearer

---

## Login un User

### POST /api/user/login

```json
{
    "email": "antoine123@gmail.com",
    "password": "Password123",
}
```

Return un Bearer

---

## Device Push Data vers la DB

### POST /api/data/device

```json
{
    "code": "A1234", // device code (voir below)
    "time": "2008-02-07T08:00:00.000Z", // time doit avoir ce format: 'YYYY-MM-DDTHH:MM:SSZ'  //! TRES IMPORTANT FAIT AVANCER LES JOURS ET PAS L'HEURE !!!! (sinon ça fait péter l'affichage dans le web) (genre chaque donnée prends +1 jour au lieu de prendre le time actuelle)
    "data": 55 // Un nombre/float entre 0 et 100 (il s'agit normalement d'un pourcentage)
}
```

Il y a 2 code de device mis en brute dans le DB par défaut:

* A1234
* B1234

En cas de success, return un statusCode "200 OK", sans body

---

## Retrieve la liste des "profiles" de plant

### POST /api/plant/list

```json
{
    "bearer": "8d40514355dbe75fdefc419681dd0382", // device code (voir below)
}
```

Return la liste de plan existant dans la DB avec une indication de celle set par l'user.

---

## Create a new plant profile

### POST /api/plant/new

```json
{
    "bearer": "8d40514355dbe75fdefc419681dd0382", // device code
    "name": "Eucalyptus", // name plant
    "max": 66, // 0> && <100
    "min": 25, // 0> && <100
}
```

En cas de success, return un statusCode "200 OK", sans body

---

## Set a plant profile for a user

### POST /api/plant/set

```json
{
    "bearer": "8d40514355dbe75fdefc419681dd0382", // device code
    "name": "Eucalyptus", // name plant
}
```

En cas de success, return un statusCode "200 OK", sans body

---

## Get plant profile for a user

### POST /api/plant/get

```json
{
    "bearer": "8d40514355dbe75fdefc419681dd0382", // device code
}
```

En cas de success, return un obj { plant: "Tulipe" }

---

## Get data pour les plants

### POST /api/data/get

```json
{
    "bearer": "8d40514355dbe75fdefc419681dd0382", // device code
}
```

En cas de success, return un array [{ close: data, time: "Tulipe" }]
