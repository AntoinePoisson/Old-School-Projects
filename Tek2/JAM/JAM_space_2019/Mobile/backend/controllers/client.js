const mClient = require('../models/mClient');
const mWaiting = require('../models/mWaiting');
const mGame = require('../models/mGame');
const mQuestion = require('../models/mQuestion');
const request = require("request");
const moment = require("moment");
const Sequelize = require('sequelize');
const Op = Sequelize.Op;
const nodemailer = require("nodemailer");
const randomstring = require("randomstring");
var AES = require("crypto-js/aes");
var SHA256 = require("crypto-js/sha256");
const bcrypt = require('bcrypt');

function sleep(ms) {
  return new Promise((resolve) => {
    setTimeout(resolve, ms);
  });
}

class Client {

  async createClient(body) {
    let res;
    try {
      const client = await mClient.create({
        name: body.name
      });
      res = {
        success: true,
        id: client.dataValues.id,
        name: client.dataValues.name
      }
    } catch (err) {
      console.error('error', err);
      res = {
        success: false,
        error: err
      };
    }
    return (res);
  }

  async queueCoolDown(id) {
    console.log('Queue filled');
    let i = 15;
    while (i > 0) {
      await sleep(1000);
      let queue = await mWaiting.findOne({where: {id: id}});
      i -= 1;
      await queue.update({launch: i});
    }
    let players = [];
    let queue = await mWaiting.findOne({where: {id: id}});
    players = JSON.parse(queue.dataValues.players);
    console.log('Game with', players);
    await queue.update({launched: true});
  }

  async getWaitingData(body) {
    let res;
    try {
      let queue = await mWaiting.findOne({where: {id: body.id}});
      res = {
        success: true,
        queue: queue.dataValues
      }
    } catch (error) {
      console.error(error);
      res = {
        success: false,
        error: error
      }
    }
    return (res);
  }

  async getGameStat(body) {
    try {
      let game = await mGame.findOne({where: {id: body.id}});
      let data = game.dataValues;
      data.questions = JSON.parse(data.questions);
      return ({success: true, data: data});
    } catch (error) {
      console.log(error);
      return ({success: false, error: error});
    }
  }

  async createGame(data) {
    let game = await mGame.findOne({where: {id: data.id}});
    let questions = await mQuestion.findAll();
    let selectedQuestions = [];
    let i = 0;
    while (i < 4) {
      let question;
      let isSingle = true;
      do {
        question = questions[Math.floor(Math.random() * questions.length)];
        for (let ask of selectedQuestions) {
          if (ask.id == question.dataValues.id)
            isSingle = false;
        }
      } while (isSingle == false)
      selectedQuestions.push(question.dataValues);
      i += 1;
    }
    console.log(selectedQuestions);
    await game.update({questions: JSON.stringify(selectedQuestions)});
  }

  async addClientToQueue(body) {
    let res;
    try {
      let players = [];
      let queue = await mWaiting.findOne({where: {launched: false}});
      if (queue == undefined) {
        players.push(body.id);
        queue = await mWaiting.create(
        {
          players: JSON.stringify(players),
          launch: 15,
          launched: false
        });
      } else {
        players = JSON.parse(queue.dataValues.players);
        players.push(body.id);
        if (players.length == 2) {
          let game = await mGame.create(
          {
            participants: JSON.stringify(players)
          });
          this.createGame(game.dataValues);
          this.queueCoolDown(queue.dataValues.id);
          await queue.update({gameId: game.dataValues.id});
        } else {
          let game = await mGame.findOne({where: {id: queue.dataValues.gameId}});
          await game.update({participants: JSON.stringify(players)});
        }
        await queue.update({players: JSON.stringify(players)});
      }
      res = {
        queue: queue.dataValues
      }
    } catch (err) {
      console.error('error', err);
      res = {
        success: false,
        error: err
      };
    }
    return (res);
  }

}

module.exports = Client;