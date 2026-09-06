const Sequelize = require('sequelize');
const db = require('../controllers/sequelize').dbcongfig;

const mWaiting = db.define('Waiting', {
  id: {
    autoIncrement: true,
    primaryKey: true,
    type: Sequelize.INTEGER
  },
  players: Sequelize.TEXT,
  launch: Sequelize.INTEGER,
  launched: Sequelize.BOOLEAN,
  gameId: Sequelize.INTEGER
});

module.exports = mWaiting;