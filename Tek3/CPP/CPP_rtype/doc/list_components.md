Here lies the list of all the existing components:
---

| BitIndex  | Component Names               | Entity                        | Description Breve (Pas obligatoire)              |
| :---      | ---:                          | ---:                          | ---:                                            |
|     0     | Position                      |  Bullet                       |                                                 |
|     1     | Destination                   |  Bullet                       |                                                 |
|     2     | NextPosition                  |  Player                       |                                                 |
|     3     | Direction                     |  Player                       |                                                 |
|     4     | StatingTime                   |  Bullet                       |                                                 |
|     5     | Speed                         |  Bullet                       |                                                 |
|     6     | Surface                       |                               |                                                 |
|     7     | Collision                     |                               |                                                 |
|     8     | Collided                      |                               |                                                 |
|     9     | ConceidedDamage               |                               |                                                 |
|    10     | Damage                        |  Bullet                       |                                                 |
|    11     | Life                          |                               |                                                 |
|    12     | Sprite                        |  any needing to be displayed  |   sf::sprite to display                         |
|    13     | SpriteSheet                   |  any needing to be displayed  |   suplement to sprite needed for sprite sheet   |
|    14     | Text                          |  any needing text to displayed|   sf::text to display                           |
|    15     | Sound                         |  any needing to play sound    |   sf::sound to play                             |
|    16     | StartCriteria                 |  Bullet                       |                                                 |
|    17     | KeyboardEvent                 |  Event                        |   stock list of key pressed                     |
|    18     | IOService                     |  Network                      |   stock io service                              |
|    19     | Socket                        |  Network                      |   stock my socket                               |
|    20     | MyNetworkInfo                 |  Network                      |   stock my ip and port                          |
|    21     | OpponentNetworkInfo           |  Network                      |   stock send to ip and port                     |
|    22     | QueueMessageReceive           |  Network                      |   Store Message Receive From Someone            |
|    23     | QueueMessageSend              |  Network                      |   Store Message Send To Someone                 |
|    24     | ListClientNetwork             |  Network                      |   store list client                             |
|    25     | ListAction                    |  Event                        |   list equivalent sfml KeyboardEventType        |
|    26     | SFMLEvent                     |  Event                        |   sf::event                                     |
|    27     | SFMLWindow                    |  Window                       |   sf::window                                    |
|    28     | Music                         |  any needing to play music    |   sf::music                                     |
|    29     | DisplayOrder                  |  any needing to be displayed  |   order for displaying entities                 |
|    30     | Type                          |  entities sent to the client  |   type of entities                              |
|    31     | Scene                         |  Scene                        |                                                 |
|    32     | SocketTCP                     |  TCP                          |   used to join to ask to join a game            |
|    33     | QueueMessageSendClient        |  TCP/UDP                      |   handle send message                           |
|    34     | QueueMessageRecvClient        |  TCP/UDP                      |   handle received message                       |
|    35     | ServerEnpoints                |  TCP/UDP                      |  contains udp and tcp endpoints                 |
|    36     | MouseEvent                    |  Event                        |  list position of mouse click                   |
|    37     | ButtonAction                  |  any button                   |  action of the button                           |
|    38     | ItsServer                     |  Only for server entity       |   difference betwin server and other entities   |
|    39     | Unremovable                   |  Unremovable entities         |   contains list of unremovable entities         |
|    40     | ItsPlayer                     |  Only for player entity       |   difference betwin player and other entities   |
|    41     | ItsBullet                     |  Only for Bullet entity       |   difference betwin Bullet and other entities   |
|    42     | ItsMob                        |  Only for Mob entity          |   difference betwin Mob and other entities      |
|    43     | ListMethodeMob                |  Only for Mob entity          |   difference betwin Mob and other entities      |
|    44     | NbrMob                        |  Number of Mob in Map         |                                                 |
|    45     | Level                         |  Only for Player entity       |   Level of the player                           |
|    46     | DeletOrPrint                  |  Only for Bullet entity       |   If bullet should be print or deleted          |
|    47     | GlobalVolume                  |  GlobalVolume                 |   GlobalVolume for music and sound              |



Here is the list of the temp components:
---
| BitIndex  | Component Names               | Entity                        | Description Bref (Pas obligatoire)              |
| :---      | ---:                          | ---:                          | ---:                                            |
|     0     | NetworkRead                   |                               |                                                 |
|     1     | NetworkAddSomeWrite           |                               |                                                 |
|     2     | NetworkInterpret              |                               |                                                 |
|     3     | OpenAsyncRead                 |                               |                                                 |