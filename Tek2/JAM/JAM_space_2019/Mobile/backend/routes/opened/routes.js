const express = require('express');
const router = express.Router();
const Client = require('../../controllers/client');
var randomstring = require("randomstring");
var path = require('path');
var cors = require('cors');
var corsOptions = {
    origin: '*'
}

router.post("/game/getStat", /*cors(corsOptions),*/ async (req, res) => {
    const c = new Client();
    console.log(req.body);
    try {
        const value = await c.getGameStat(req.body);
        res.json(value);
    } catch (err) {
        console.error("error: ", err);
        res.json({success: false, error: err});
    }
});

router.post("/client/register", /*cors(corsOptions),*/ async (req, res) => {
    const c = new Client();
    console.log(req.body);
    try {
        const value = await c.createClient(req.body);
        res.json(value);
    } catch (err) {
        console.error("error: ", err);
        res.json({success: false, error: err});
    }
});

router.post("/waiting/getData", /*cors(corsOptions),*/ async (req, res) => {
    const c = new Client();
    console.log(req.body);
    try {
        const value = await c.getWaitingData(req.body);
        res.json(value);
    } catch (err) {
        console.error("error: ", err);
        res.json({success: false, error: err});
    }
});

router.post("/client/subscribeToQueue", /*cors(corsOptions),*/ async (req, res) => {
    const c = new Client();
    console.log(req.body);
    try {
        const value = await c.addClientToQueue(req.body);
        res.json(value);
    } catch (err) {
        console.error("error: ", err);
        res.json({success: false, error: err});
    }
});

module.exports = router;