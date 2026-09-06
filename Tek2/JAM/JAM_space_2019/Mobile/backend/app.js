require('dotenv').config();

var fs = require('fs');
var http = require('http');
var https = require('https');
var privateKey  = fs.readFileSync('key.pem', 'utf8');
var certificate = fs.readFileSync('cert.pem', 'utf8');

var credentials = {key: privateKey, cert: certificate};
const express = require('express');
const bodyParser = require('body-parser');
const app = express();
const db = require('./controllers/sequelize').dbcongfig;
const port = process.env.PORT || 3000;
const jwt = require('jsonwebtoken');
const cors = require('cors');
var CronJob = require('cron').CronJob;

var httpServer = http.createServer(app);
var httpsServer = https.createServer(credentials, app);

httpServer.listen(3000);
httpsServer.listen(3001);

// https.createServer({
//     key: fs.readFileSync('key.pem'),
//     cert: fs.readFileSync('cert.pem')
// }, app).listen(port);

app.use(bodyParser.json()); // to support JSON-encoded bodies
app.use(bodyParser.urlencoded({ // to support URL-encoded bodies
    extended: true
}));

// app.use(cors());
// app.use(function(req, res, next) {
//     res.header('Access-Control-Allow-Origin', '*'); // update to match the domain you will make the request from
//     res.header('Access-Control-Allow-Headers', 'Origin, X-Requested-With, Content-Type, Accept');
//     next();
// });

console.log("running on port: ", port);

app.use(function(req, res, next) {
    res.header("Access-Control-Allow-Origin", "*"); // update to match the domain you will make the request from
    res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
    next();
});

app.use(require('./routes/opened/routes.js'));

// Handle 404
app.use(function (req, res) {
    res.status(404).send({success: false, error: '404: Page not Found!'});
});

// Handle 500
app.use(function (error, req, res, next) {
    res.status(500).send({success: false, error: '500: Internal Server Error'});
});

// app.listen(port, async () => {
//     console.log(`Server listening on: ${port}.`);
//     try {
//         await db.authenticate();
//     } catch (error) {
//         console.error('Unable to connect to the database:', error);
//     }
// });
