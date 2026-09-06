import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class GameService {

  public gameId = 0;
  public playerId = 0;

  constructor() { }
}
