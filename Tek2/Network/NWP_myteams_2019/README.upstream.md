# myTeams
## Purpose:
It's 2nd year project of Epitech.<br/>
The goal of this project is to create a **server** and a **CLI client** in C.<br/>
The network communication will be achieved through the use of TCP sockets.<br/>

<p align="center">
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/c9/Microsoft_Office_Teams_%282018%E2%80%93present%29.svg/1200px-Microsoft_Office_Teams_%282018%E2%80%93present%29.svg.png" alt="" height="202" width="226" />
</p>

Your server is able to manage a collaborative communication application like the well known Microsoft Teams.<br/>
A collaborative communication application is a service able to manage severall communication teams, where discussion are organised like following:<br/>
• threads (initial post and additional comments) in a specific channel<br/>
• discussion (personnal messages)<br/>

## Features:
• Creating/Joining/Leaving a team<br/>
• Creating a user<br/>
• Creating a channel in a team<br/>
• Creating a thread in a channel<br/>
• Creating a comment in a thread<br/>
• Saving & restoring users, teams, channels, threads & associated comments<br/>
• Personnal discussion (from a user to an other)<br/>
• Saving & restoring personnal discussion<br/>

## Usage:

- To build:
```
$ make
```

 - Usage server:
```
$ ./myteams_server port
port is the port number on which the server socket listens.
```

 - Usage client:
```
$  ./myteams_cli ip port
ip is the server ip address on which the server socket listens
port is the port number on which the server socket listens
```

 - The client can handle the following command from the standard input:
```
  /help : show help
  /login [“username”] : set the username used by client
  /logout : disconnect the client from the server
  /users : get the list of all users that exist on the domain
  /user [“user_uuid”] : get information about a user
  /send [“user_uuid”] [“message_body”] : send a message to a user
  /messages [“user_uuid”] : list all messages exchange with an user
  /subscribe [“team_uuid”] : subscribe to the event of a team and its sub directories (enable reception of all events from a team)
  /subscribed ?[“team_uuid”] : list all subscribed teams or list all users subscribed to a team
  /unsubscribe [“team_uuid”] : unsubscribe from a team
  /use ?[“team_uuid”] ?[“channel_uuid”] ?[“thread_uuid”] : use specify a context team/channel/thread
  /create : based on what is being used create the sub resource (see below)
  /list : based on what is being used list all the sub resources (see below)
  /info : based on what is being used list the current (see below)
```

## Note:
Grade A<br/>
Result moulinette Epitech: 95%
