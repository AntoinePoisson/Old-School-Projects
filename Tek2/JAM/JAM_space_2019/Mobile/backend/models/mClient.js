const Sequelize = require('sequelize');
const db = require('../controllers/sequelize').dbcongfig;

const mClient = db.define('Client', {
  id: {
    autoIncrement: true,
    primaryKey: true,
    type: Sequelize.INTEGER
  },
  name: Sequelize.TEXT
});

module.exports = mClient;