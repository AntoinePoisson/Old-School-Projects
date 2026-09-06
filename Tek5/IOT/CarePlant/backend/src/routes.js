const express = require('express');
const user = require('./controllers/user.controller')
const data = require('./controllers/data.controller')
const plant = require('./controllers/plant.controller')

const rooter = express.Router();

const routes = [
    rooter.use('/user/', user),
    rooter.use('/data/', data),
    rooter.use('/plant/', plant),
];

module.exports = routes
