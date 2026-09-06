const express = require('express')
const cors = require('cors')
const app = express()
const mongoose = require('mongoose')
const apiResponse = require('./helpers/apiResponse');
const apiRoutes = require('./routes');
const { preloadDevice, preloadUser, preloadPlant, preloadData } = require('./helpers/preload');
require('dotenv').config()

const source = process.env.MONGODB_URI_CONNECTION
const port = process.env.PORT || 5000

app.use(express.urlencoded({ extended: true }));
app.use(cors())
app.use(express.json())

mongoose.connect(source, {
    useNewUrlParser: true,
    useUnifiedTopology: true
})

const connection = mongoose.connection

connection.once('open', () => {
    console.log("DB connected.");
})

app.get('/status', (_, res) => {
    res.send('API running');
});

app.use('/api/', apiRoutes);

app.all('*', (req, res) => apiResponse.notFoundResponse(res, 'Not found'));


app.listen(port, () => {
    console.log(`Successfully served on port: ${port}`);
})

// preload data into the DB
function preloadIntoDB() {
    preloadDevice({ code: "A1234" })
    preloadDevice({ code: "B1234" })
    preloadDevice({ code: "C1234" })
    preloadData({ code: "C1234", data: 35, time: "2022-11-19T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 36, time: "2022-11-20T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 48, time: "2022-11-21T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 50, time: "2022-11-22T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 55, time: "2022-11-23T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 56, time: "2022-11-24T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 57, time: "2022-11-25T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 64, time: "2022-11-26T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 62, time: "2022-11-27T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 60, time: "2022-11-28T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 48, time: "2022-11-29T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 44, time: "2022-12-01T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 43, time: "2022-12-02T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 42, time: "2022-12-03T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 41, time: "2022-12-04T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 40, time: "2022-12-05T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 39, time: "2022-12-06T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 38, time: "2022-12-07T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 37, time: "2022-12-08T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 36, time: "2022-12-09T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 35, time: "2022-12-10T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 38, time: "2022-12-11T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 45, time: "2022-12-12T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 45, time: "2022-12-13T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 49, time: "2022-12-14T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 52, time: "2022-12-15T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 55, time: "2022-12-16T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 56, time: "2022-12-17T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 59, time: "2022-12-18T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 70, time: "2022-12-19T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 76, time: "2022-12-20T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 80, time: "2022-12-21T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 85, time: "2022-12-22T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 87, time: "2022-12-23T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 90, time: "2022-12-24T11:00:00.000Z" })
    preloadData({ code: "C1234", data: 91, time: "2022-12-25T11:00:00.000Z" })
    preloadPlant({name: "Cactus", max: 45 ,min: 30  })
    preloadPlant({name: "Eucalyptus", max: 66 ,min: 25  })
    preloadPlant({name: "Passiflora", max: 45 ,min: 35  })
    preloadPlant({name: "Tulipe", max: 55 ,min: 40  })
    preloadPlant({name: "Crocus", max: 99 ,min: 1  })
    preloadPlant({name: "Vigne", max: 51 ,min: 49  })
    preloadUser({email: "test@test.com", password: "test", bearer: "63ebfad23159920b61aae29ce1f6759b", code: "C1234", plant: "Cactus" })
}
preloadIntoDB()