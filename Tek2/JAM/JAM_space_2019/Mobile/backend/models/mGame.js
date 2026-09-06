const Sequelize = require('sequelize');
const db = require('../controllers/sequelize').dbcongfig;

const mGame = db.define('Game', {
  id: {
    autoIncrement: true,
    primaryKey: true,
    type: Sequelize.INTEGER
  },
  questions: Sequelize.TEXT,
  participants: Sequelize.TEXT
});

module.exports = mGame;