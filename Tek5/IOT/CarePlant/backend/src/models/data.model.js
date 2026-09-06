const mongoose = require('mongoose')
const Schema = mongoose.Schema

const dataSchema = new Schema({
    code: { type: String },
    time: { type: String },
    data: { type: Number },
})

const Data = mongoose.model('Data', dataSchema)
module.exports = Data