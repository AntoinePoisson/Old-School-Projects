# Zappy

Zappy is a multi-players, single process, single thread game.

## Server

The server is written in C and use TCP/IP connection protocol (RFC 793) using `Sys/Socket`, `Sys/Select`, `Arpa/Inet`, `Sys/Queue` and `Netinet/In` along with `Standard C` libraries.
Each command even if a wrong one is received, got answered by a string response delimited by a new-line character.

* Usage:
```
∼/B-PSU-403> ./zappy_server –help
USAGE: ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq
	port		is the port number
	width		is the width of the world
	height		is the height of the world
	nameX		is the name of the team X
	clientsNb	is the number of authorized clients per team
	freq		is the reciprocal of time unit for execution of actions
```
i.e.
`./zappy_server -p 4201 -x 10 -y 10 -n name1 -c 2 -f 30`

## Client

The client is written in Python (3) and use `Socket`, `Queue` and `Select` libraries.
It is made to connect to the providen server using TCP/IP connection protocol (RFC 793).
The client is an AI to autonomously play the game.

* Usage:
```
∼/B-PSU-403> ./zappy_ai –help
USAGE: ./zappy_ai -p port -n name -h machine
	port	is the port number
	name	is the name of the team
	machine	is the name of the machine; localhost by default
```
i.e.
`./zappy_ai -p 4201 -n name1 -h "local"`

## How to compile Zappy?

1. Switch to repository's root
2. Compile every binaries at once using the command `make`
3. Start the server using the above written help message
4. Connect several clients and make sure the `clientsNb` argument of the server is higher than `1` if you want many players inside the same team.
5. Enjoy!

## Game mechanics

### Rules

* Each client starts on level 1.
* Each client start with 10 piece of food and 0 stones.
* Trantorians can see as far as his/her levels alllow.
* A single food is allow the player to live 126 units of time.
* Players can starve, see the above rule.
* The egg-laying time is equal to 42 units of time.
* Time between egg-laying and hatching is equal to 600 units of time.

### Commands

| action | command | time limit | response |
|:-:|:-:|:-:|:-:|
| move up one tile | Forward | 7/f | ok |
| turn 90° right | Right | 7/f | ok |
| turn 90° left | Left | 7/f | ok |
| look around | Look | 7/f | [tile1, tile2, ...] |
| inventory | Inventory | 1/f | [linemate n, sibur n, ...] |
| broadcast text | Broadcast <text> | 7/f | ok |
| number of team unused slots | Connect_nbr | - | value |
| fork a player | Fork | 42/f | ok |
| eject players from this tile | Eject | 7/f | ok/ko |
| death of a player | - | - | dead |
| take object | Take <object> | 7/f | ok/ko |
| set object down | Set <object> | 7/f | ok/ko |
| start incantation | Incantation | 300/f | Elevation underway Current level: k/ko |

### Incantation

To be able to win, you and your team members have to get to 8th level by collecting stones and starting an incantation ritual.
These stones have six distinct kinds: linemate, deramere, sibur, mendiane, phiras and thystame.
Each game level has differents ritual requirements:

| Level | Number of players | Linemate | Deraumere | Sibur | Mendiane | Phiras | Thystame |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| 1-2 | 1 | 1 | 0 | 0 | 0 | 0 | 0 |
| 2-3 | 2 | 1 | 1 | 1 | 0 | 0 | 0 |
| 3-4 | 2 | 2 | 0 | 1 | 0 | 2 | 0 |
| 4-5 | 4 | 1 | 1 | 2 | 0 | 1 | 0 |
| 5-6 | 4 | 1 | 2 | 1 | 3 | 0 | 0 |
| 6-7 | 6 | 1 | 2 | 3 | 0 | 1 | 0 |
| 7-8 | 6 | 2 | 2 | 2 | 2 | 2 | 1 |

## Technical documentation for the graphical client

### Intro

On server connection, the graphical client requests every cells of the map.
On server refresh, the client requests all changes since the last request, which means that each players movements and food update are refreshed.

### Technical part

The client use `select` function to know when exactly there is data to read from the stream.

On data presence in the stream,l the client read by the size of the bellow structure (cell_t) into a pointer of the structure type.

```C
typedef enum look_direction_e {
    None,
    Up,
    Down,
    Left,
    Right,
} look_direction_t;

typedef struct cell_player_s
{
    char id[SIZE_ID_UUID];
    char player_team[DEFAULT_TEAM_NAME_LENGTH];
    look_direction_t look;
} cell_player_t;

typedef struct cell_s
{
    int x;
    int y;
    unsigned int food;
    unsigned int linemate;
    unsigned int deraumere;
    unsigned int sibur;
    unsigned int mendiane;
    unsigned int phiras;
    unsigned int thystame;
    cell_player_t players[MAX_PLAYER_SAME_POSITION];
} cell_t;
```

The above code sample is self explanatory.

### Graphical part

The client store and manage each cell into a vector of type cell,
When the refresh rate time is hit, a draw function is called and it interpret the structure (cell_t) to draw a precise texture into the x and y coordinates

#### To add a new texture

To add a new type of object into a cell, you need to add your object name into these enum and struct with the most generic name as possible.

```C++
static std::map<std::string, std::string> mapAssets = {
    {"cell", "cell.png"},
    {"player_up", "player_up.png"},
    {"player_down", "player_down.png"},
    {"player_left", "player_left.png"},
    {"player_right", "player_right.png"},
    {"food", "food.png"},
    {"linemate", "linemate.png"},
    {"deraumere", "deraumere.png"},
    {"sibur", "sibur.png"},
    {"mendiane", "mendiane.png"},
    {"phiras", "phiras.png"},
    {"thystame", "thystame.png"},
    {"egg", "egg.png"}
};
```

The first key of the pair is the generic name requested above, and the second one is the path to the texture

```C++
enum Element {
    NOTHING = -1,
    PLAYER_UP = -2,
    PLAYER_DOWN = -3,
    PLAYER_LEFT = -4,
    PLAYER_RIGHT = -5,
    FOOD = 0,
    LINEMATE = 1,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    EGG
};
```

The above enum is usefull to create a fast defined shortcut, it is mandatory.

```C++
static std::map<enum Element, std::string> mapEnumKey = {
    {PLAYER_UP, "player_up"},
    {PLAYER_DOWN, "player_down"},
    {PLAYER_LEFT, "player_left"},
    {PLAYER_RIGHT, "player_right"},
    {FOOD, "food"},
    {LINEMATE, "linemate"},
    {DERAUMERE, "deraumere"},
    {SIBUR, "sibur"},
    {MENDIANE, "mediane"},
    {PHIRAS, "phiras"}, 
    {THYSTAME, "thystame"},
    {EGG, "egg"}
};
```

The previous map is used to link the enum to the string id, this is a mandatory need to link data stream to the GUI

## Preview

Visit our website to learn more: http://51.77.202.145:5626/

## Authors

Aurèle
Eliot
Pierre-Mickael
Antoine Poisson (antoine.poisson@epitech.eu)