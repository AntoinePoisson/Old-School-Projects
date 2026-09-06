const Device = require('../models/device.model')
const User = require('../models/user.model')
const Data = require('../models/data.model')
const router = require('express').Router()

router.route('/device').post((req, res) => {
    const newData = new Data({ ...req.body, time: new Date().toISOString() })

    if (!req.body || !req.body.code || !req.body.data) {
        res.json("Error! mauvais body").status(400)
        return
    }

    Device.findOne({ code: req.body.code }, (err, result) => {
        if (err || !result || !result.code) {
            res.json("Error! " + err).status(400)
            return
        } else {
            if (result && result.code != "") {
                newData.save()
                    .then(_ => res.status(200).send())
                    .catch(err => res.json("Error! " + err).status(400))
            } else {
                res.json("Error! device code not find").status(400)
                return
            }
        }
    })
})

router.route('/get').post((req, res) => {
    if (!req || !req.body || !req.body.bearer) {
        res.json("Error! bad body request (missing bearer field)").status(400)
        return
    }

    User.findOne({ bearer: req.body.bearer }, (err, result) => {
        if (err || !result || !result.code) {
            res.json("Error! " + err).status(400)
            return
        } else {
            Data.find({ code: result.code }, (err, resul) => {
                if (err) {
                    res.json("Error! " + err).status(400)
                    return
                } else {
                    res.json(resul.map((e) => ({ close: parseInt(e.data, 10), date: e.time })).sort((a, b) => { return new Date(b.date) - new Date(a.date) })).status(200)
                }
            })
        }
    })

})

module.exports = router
