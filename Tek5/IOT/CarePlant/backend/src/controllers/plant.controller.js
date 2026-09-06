const Plant = require('../models/plant.model')
const router = require('express').Router()
const User = require('../models/user.model')
const auth = require('../helpers/authentification')

function capitalizeFirstLetter(string) {
    return string.charAt(0).toUpperCase() + string.slice(1);
}

router.route('/new').post((req, res) => {
    const newPlant = new Plant({ ...req.body, name: capitalizeFirstLetter(req.body.name) })

    if (!req.body || !req.body.name || !req.body.min || !req.body.max) {
        res.json("Error! mauvais body").status(400)
        return
    }

    User.findOne({ bearer: req.body.bearer }, (err, result) => {
        if (err) {
            res.json("Error! " + err).status(400)
            return
        } else {
            if (result && result.bearer != "") {
                Plant.findOne({ name: capitalizeFirstLetter(req.body.name) }, (err, resul) => {
                    if (err || resul) {
                        res.json("Error! plant already existing").status(400)
                        return
                    }
                    newPlant.save()
                        .then(plant => res.status(200).send())
                        .catch(err => res.status(400).json("Error! " + err))
                })
            } else {
                res.json("Error! user not find").status(400)
                return
            }
        }
    })
})

router.route('/list').post((req, res) => {
    if (!req || !req.body || !req.body.bearer) {
        res.json("Error! bad body request (missing bearer field)").status(400)
        return
    }

    User.findOne({ bearer: req.body.bearer }, (err, resulta) => {
        if (err) {
            res.json("Error! " + err).status(400)
            return
        } else {
            if (resulta && resulta.bearer != "") {
                Plant.find({}, (err, result) => {
                    if (err) {
                        res.status(400).json("Error! " + err)
                    } else {
                        res.json(result.map((e, i) => {
                            if (String(e.name).toLowerCase() === String(resulta.plant).toLowerCase()) {
                                return ({ name: e.name, max: e.max, min: e.min, default: true })
                            }
                            return ({ name: e.name, max: e.max, min: e.min, default: false })
                        })).status(200)
                    }
                })
            } else {
                res.json("Error! user not find").status(400)
                return
            }
        }
    })
})

router.route('/set').post((req, res) => {
    if (!req || !req.body || !req.body.bearer || !req.body.name) {
        res.json("Error! bad body request (missing fields)").status(400)
        return
    }

    User.findOne({ bearer: req.body.bearer }, (err, result) => {
        if (err) {
            res.json("Error! " + err).status(400)
            return
        } else {
            if (result && result.bearer != "") {
                Plant.findOne({ name: capitalizeFirstLetter(req.body.name) }, (err, resul) => {
                    if (err || !resul) {
                        res.json("Error! plant don't existing").status(400)
                        return
                    } else {
                        User.updateOne({ bearer: req.body.bearer }, { plant: capitalizeFirstLetter(req.body.name) })
                            .then(plant => res.status(200).send())
                            .catch(err => res.status(400).json("Error! " + err))
                    }
                })
            } else {
                res.json("Error! user not find").status(400)
                return
            }
        }
    })
})

router.route('/get').post((req, res) => {
    if (!req || !req.body || !req.body.bearer) {
        res.json("Error! bad body request (missing fields)").status(400)
        return
    }

    User.findOne({ bearer: req.body.bearer }, (err, result) => {
        if (err || !result || !result.plant) {
            res.json("Error! " + err).status(400)
            return
        } else {
            Plant.findOne({ name: capitalizeFirstLetter(result.plant) }, (err, resul) => {
                if (err || !resul) {
                    res.json("Error! plant don't existing").status(400)
                    return
                } else {
                    res.json({ plant: capitalizeFirstLetter(result.plant), min: resul.min, max: resul.max }).status(200)
                }
            })
        }
    })
})


module.exports = router
