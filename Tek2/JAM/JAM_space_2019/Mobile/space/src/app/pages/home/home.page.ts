import { Component } from '@angular/core';
import { FormControl } from '@angular/forms';
import { FormGroup } from '@angular/forms';
import { NetworkService } from '../../services/network.service';
import { NativeStorage } from '@ionic-native/native-storage/ngx';
import { GameService } from '../../services/game.service';
import { from } from 'rxjs';
import { NavController } from '@ionic/angular';

@Component({
  selector: 'app-home',
  templateUrl: 'home.page.html',
  styleUrls: ['home.page.scss'],
})

export class HomePage {

  name = new FormControl();
  registered: Boolean = false;
  data;
  id;
  cooldown = 15;
  load: Boolean = false;

  constructor(
    private networkService: NetworkService,
    private nativeStorage: NativeStorage,
    private gameService: GameService,
    private navCtrl: NavController
  ) {
    this.nativeStorage.getItem('client').then((data) => {
      console.log(data);
      this.data = data.name;
      this.id = data.id;
      this.registered = true;
    }).catch((error) => {
      console.error(error);
      this.data = "TEST_REMOVE"; // A ENLEVER
      this.id = 1; // A ENLEVER
      this.registered = true // A ENLEVER
    });
  }

  async sleep(ms) {
    return new Promise((resolve) => {
      setTimeout(resolve, ms);
    });
  }

  async launchGame(gameId) {
    this.gameService.playerId = this.id;
    this.gameService.gameId = gameId;
    this.navCtrl.navigateRoot('game').then(() => {
      ;
    }).catch((error) => {
      console.error(error);
    })
  }

  async getGameData(id) {
    let gameId = 0;
    do {
      await this.networkService.getQueueData({id: id}).then((data: any) => {
        console.log(data);
        this.cooldown = data.queue.launch;
        gameId = data.queue.gameId;
        if (this.cooldown < 15)
          this.load = false;
      }).catch((error) => {
        console.error(error);
      });
      if (this.cooldown == 15)
          await this.sleep(1000);
    } while (this.cooldown == 15)
    while (this.cooldown > 0) {
      await this.sleep(1000);
      this.cooldown -= 1;
    }
    this.launchGame(gameId);
  }

  async findGame() {
    if (this.load == true || this.cooldown < 15)
      return;
    this.load = true;
    await this.networkService.subscribeToQueue({id: this.id}).then((data: any) => {
      this.getGameData(data.queue.id);
    }).catch((error) => {
      console.error(error);
    });
    this.networkService.subscribeToQueue({id: this.id + 1}).then((data: any) => { // A ENLEVER
      ; // A ENLEVER
    }).catch((error) => { // A ENLEVER
      console.error(error); // A ENLEVER
    }); // A ENLEVER
  }

  async register() {
    if (this.name.value == undefined || this.name.value.length < 1)
      return;
    console.log(this.name.value, this.name);
    this.networkService.register({name: this.name.value}).then((data: any) => {
      if (data.success) {
        this.nativeStorage.setItem('client', {name: data.name, id: data.id}).then(() => {
          console.log('Client saved!');
          this.data = data.name;
          this.id = data.id;
          this.registered = true;
        }).catch((error) => {
          console.error(error);
          this.data = "TEST_REMOVE"; // A ENLEVER
          this.id = 1; // A ENLEVER
          this.registered = true // A ENLEVER
        });
      }
      console.log(data);
    }).catch((error) => {
      console.error(error);
    });
  }

}
