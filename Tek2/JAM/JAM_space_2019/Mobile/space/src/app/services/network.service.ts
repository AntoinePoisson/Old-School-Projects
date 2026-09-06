import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { SERVERIP } from '../../environments/environment';

@Injectable({
  providedIn: 'root'
})
export class NetworkService {

  constructor(private httpClient: HttpClient) { }

  async register(body) {
    console.log(body);
    return await this.httpClient.post(`${SERVERIP}/client/register`, body).toPromise();
  }

  async subscribeToQueue(body) {
    console.log(body);
    return await this.httpClient.post(`${SERVERIP}/client/subscribeToQueue`, body).toPromise();
  }

  async getQueueData(body) {
    console.log(body);
    return await this.httpClient.post(`${SERVERIP}/waiting/getData`, body).toPromise();
  }

  async getGameStat(body) {
    console.log(body);
    return await this.httpClient.post(`${SERVERIP}/game/getStat`, body).toPromise();
  }

}
