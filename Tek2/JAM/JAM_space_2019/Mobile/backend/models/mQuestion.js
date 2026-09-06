const Sequelize = require('sequelize');
const db = require('../controllers/sequelize').dbcongfig;

const mQuestion = db.define('Question', {
  id: {
    autoIncrement: true,
    primaryKey: true,
    type: Sequelize.INTEGER
  },
  question: Sequelize.TEXT,
  answers: Sequelize.TEXT,
  solution: Sequelize.TEXT
});

module.exports = mQuestion;