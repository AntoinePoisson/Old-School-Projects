const mongoose = require('mongoose')
const Schema = mongoose.Schema

const deviceSchema = new Schema({
    code: { type: String },
})

const Device = mongoose.model('Device', deviceSchema)
module.exports = Device