import { Component, OnInit } from '@angular/core';
import { GameService } from '../../services/game.service';
import { from } from 'rxjs';
import { NavController } from '@ionic/angular';
import { NetworkService } from '../../services/network.service';
import { NativeStorage } from '@ionic-native/native-storage/ngx';

@Component({
  selector: 'app-game',
  templateUrl: './game.page.html',
  styleUrls: ['./game.page.scss'],
})
export class GamePage implements OnInit {

  data = undefined;
  question = "";
  indexQuestion = 0;
  answers = [];
  answersKeys = [];
  solution = "";
  answered = null;

  constructor(
    private networkService: NetworkService,
    private nativeStorage: NativeStorage,
    private gameService: GameService,
    private navCtrl: NavController
  ) {
    this.startGame();
  }

  async sleep(ms) {
    return new Promise((resolve) => {
      setTimeout(resolve, ms);
    });
  }

  async answer(answer) {
    if (this.answered == null) {
      let red = undefined;
      this.answered = answer;
      if (this.answered != this.solution) {
        red = document.getElementById(this.answered);
        red.classList.add("wrong");
      }
      let green = document.getElementById(this.solution);
      green.classList.add("win");
      await this.sleep(2000);
      this.question = "";
      this.answers = [];
      this.answersKeys = [];
      this.solution = "";
      this.answered = null;
      if (red != undefined)
        red.classList.remove("wrong");
      green.classList.remove("win");
      if (this.indexQuestion + 1 < this.data.questions.length) {
        this.indexQuestion += 1;
      this.question = this.data.questions[this.indexQuestion].question;
      this.answers = JSON.parse(this.data.questions[this.indexQuestion].answers);
      for (let k in this.answers) {
        this.answersKeys.push(k);
      }
      this.solution = this.data.questions[this.indexQuestion].solution;
      } else {
        this.navCtrl.navigateRoot('home').then(() => {
          ;
        }).catch((error) => {
          console.error(error);
        });
      }
    }
  }

  async startGame() {
    await this.networkService.getGameStat({id: this.gameService.gameId}).then((data: any) => {
      console.log(data);
      this.data = data.data;
    }).catch((error) => {
      console.error(error);
    });
    this.question = this.data.questions[this.indexQuestion].question;
    this.answers = JSON.parse(this.data.questions[this.indexQuestion].answers);
    for (let k in this.answers) {
      this.answersKeys.push(k);
    }
    this.solution = this.data.questions[this.indexQuestion].solution;
  }

  ngOnInit() {
  }

}