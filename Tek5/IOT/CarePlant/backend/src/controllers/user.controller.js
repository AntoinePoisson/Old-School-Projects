const User = require('../models/user.model')
const Device = require('../models/device.model')
const router = require('express').Router()
const auth = require('../helpers/authentification')

router.route('/register').post((req, res) => {

    if (!req.body || req.body.code == "") {
        res.status(400).json("Error! code can't be empty")
        return
    }
    Device.findOne({ code: req.body.code }, (err, result) => {
        if (err) {
            res.json("Error! " + err).status(400)
            return
        } else {
            if (result && result.code != "") {
                const bearer = auth.Bearer(req.body.email + req.body.password)
                const newUser = new User({...req.body, bearer: bearer, plant: "Cactus"})
                User.findOne({ bearer: bearer }, (err, resu) => {
                    if (err || resu) {
                        res.json("Error! user already exist").status(400)
                    } else {
                        newUser.save()
                            .then(user => res.json({ bearer: bearer }).status(200))
                            .catch(err => res.json("Error! " + err).status(400))
                    }
                })
            } else {
                res.json("Error! device code not find").status(400)
                return
            }
        }
    })
})

router.route('/login').post((req, res) => {
    if (!req.body || !req.body.email || !req.body.password) {
        res.status(400).json("Error! email and password can't be empty")
        return
    }
    User.findOne({ email: req.body.email, password: req.body.password }, (err, result) => {
        if (err) {
            res.json("Error! " + err).status(400)
            return
        } else {
            if (result && result.email != "") {
                res.json({ bearer: auth.Bearer(req.body.email + req.body.password) }).status(200)
            } else {
                res.json("Error! user not find").status(400)
                return
            }
        }
    })
})

module.exports = router
