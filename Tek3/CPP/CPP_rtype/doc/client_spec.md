//https://drive.google.com/file/d/12QxPJ-EtfC_vdE91IFsjL1OC8WwRO8Ro/view


## Scene

Menu scene:
----

- system calling order: NetworkTCPReader, Window, Audio

- Mediator subsytem: EventHandler, Interpreter, NetworkTCPWriter

Game scene:
---

- system calling order: NetworkTCPReader, NetworkUDPReader, Window, Audio, Prediction

- Mediator subsytem: EventHandler, Interpreter, NetworkUDPWriter, NetworkTCPWriter

Unremovable entities
---

UnRemovableClientComponent: map of entities ids

- list: window, event, ServerEndpoints, Socket, SocketTCP

Menu entities:
---

list: Background, boutton(PLAY(1, 2, 3, 4), QUIT)

Game entities:
---

list: background, boutton(QUITJEU, VOL, QUIT)

## Networking:

Component
---

The Socket component will be used for udp communication.
The SocketTCP component will used for tcp communication.
socket udp will be created (choosing a random port) once the client is running.

Description:
---
- For TCP: ReaderNetworkTCP, WriterNetworkTCP(used as sub system)

At the begining of the menu, the socket is created, but not connected.
ReaderNetworkTCP will check at each cycle if the socket has something to read.
Actually the only way for the TCP socket to be opened, is by clicking on the playbutton, so it's the ButtonSystem that enables the socket opening.

- For UDP: ReaderNetworkUDP, WriterNetworkUDP(used as sub system)

Idem that socket will be created when the menu starts in order to send its endpoint to the server during tcp connection.

Notice
---

Those sockets are not removed as long as the client doesn't make ctrl + c or quit.
When the client go into a game, the tcp socket is only closed, but still remains within the entities.
To handle the switching connection between tcp and udp, a ServerEndpoint component is used to saved the server's udp and tcp endpoint.

Queue
---

To send and receive a message, the client will use , QueueMessageSendClient, QueueMessageReceivedClient, and will be used either by networkSystems TCP & UDP.

## Mediator

What I think is:

It wont be a use of a temporary bitset like the server does.
mediate method will take an entity as parameter and according to its signature, the mediator call the right system.
A list of the bitset associated with the sub system is listed bellow.

List SubSystem in the Menu:
---

| Signature  | Component                                      | SubSystem       |
| ---------  | ---------                                      | ---------       |
|            | QueueMessageSendClient,SocketTCP(used as param)| WriterNetwork   |
|            | MouseEvent                                     | EventHandler    |
|            | QueueMessageRecvClient                         | MenuInterpreter |
|            |                                                |                 |

//audio system will be called at each cycle of the loop.


List SubSystem in the Game:
---

| Signature  | Component                                     | SubSystem       |
| ---------  | ---------                                     | ---------       |
|            | QueueMessageSendClient, Socket(used as param) | WriterNetwork   |
|            | KeyboardEvent                                 | EventHandler    |
|            | QueueMessageRecvClient                        | GameInterpreter |
|            |                                               |                 |


When to call mediator ?:
---

| System/Subsytem   | parameterEntity        | Subsystem       |
| ------            | ---------------        | -----------     |
| Window            | Event                  | EventHandler    |
| NetworkTCPReader  | QueueMessageRecvClient | Interpreter     |
| NetworkUDPReader  | QueueMessageRecvClient | Interpreter     |
| EventHandler      | SocketTCP              | NetworkTCPWriter|
| EventHandler      | Socket                 | NetworkUDPWriter|
|                   |                        |                 |

## NetworkReaders and Interpreters

Description
---

At each time the *NetworkReader* will be called, it will parse all the message received, and put it on the *QueueMessageRecvClient*, before calling the mediator so that the *Interpreter* can handle that.

## Interpreters

GameInterpreter
---

handle sprite creation/deletion
handle entity creation/deletion

handle endGame message, endDisplay if the player has won.

MenuInterpreter
---

Retrieve server's endpointMessage

## Buttons

ButtonMenu
---

connect TCP socket once the button play is triggered.
handle volume
handleScene (Quit Button), so have to change the scene Entity and close send a quit message to server if the connection has been opened.

ButtonGame
---

handle Quit game
handle Volume

//button entity, have to list its components: ButtonType, surface, sprite etc...

component list within Button entity:
Sprite, (SpriteSheet), Text, (Sound), Surface, StartingTime, ButtonAction, DisplayOrder, Position

Button Action
----

new component : ButtonAction
enable the interpreter to do what he have to do for button in the display

| actions | value |
| ------- | ----- |
| PLAY1   |  1    |
| PLAY2   |  2    |
| PLAY3   |  3    |
| PLAY4   |  4    |
| QUITGAME|  5    |
| QUIT    |  6    |
| VOLPLUS |  7    |
| VOLMIN  |  8    |