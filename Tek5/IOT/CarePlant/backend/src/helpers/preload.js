const Device = require('../models/device.model')
const Plant = require('../models/plant.model')
const Data = require('../models/data.model')
const User = require('../models/user.model')

exports.preloadDevice = (obj) => {
    if (!obj || !obj.code) {
        return
    }
    Device.findOne({ code: obj.code }, (err, result) => {
        if (err || !result || result.code == "") {
            new Device(obj).save()
        } else {
        }
    })
}

exports.preloadPlant = (obj) => {
    if (!obj || !obj.name || !obj.max || !obj.min) {
        return
    }
    Plant.findOne({ name: obj.name }, (err, result) => {
        if (err || !result || result.name == "") {
            new Plant(obj).save()
        } else {
        }
    })
}

exports.preloadData = (obj) => {
    if (!obj || !obj.code || !obj.data || !obj.time) {
        return
    }
    Data.findOne({ code: obj.code, time: obj.time }, (err, result) => {
        if (err || !result || result.code == "" && result.time == "") {
            new Data(obj).save()
        } else {
        }
    })
}

exports.preloadUser = (obj) => {
    if (!obj || !obj.email || !obj.password || !obj.bearer) {
        return
    }
    User.findOne({ email: obj.email }, (err, result) => {
        if (err || !result || result.email == "") {
            new User(obj).save()
        } else {
        }
    })
}