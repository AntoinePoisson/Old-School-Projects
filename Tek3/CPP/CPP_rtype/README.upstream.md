# Rtype

## Purpose:

The goal of this project is to reproduice Rtype-Game, with multi-thread and multi-player thought Internet.
This project was made in **CPP**.

<p align="center">
<img height="500" src="https://cdn03.nintendo-europe.com/media/images/10_share_images/games_15/virtual_console_wii_u_7/H2x1_WiiUVC_RType_image1600w.jpg" alt="look"/><br/>
</p>

## Server

The server is written in C++ and use TCP/IP and UDP connection protocol using `Boost/Asio` and `Queue` along with `Standard C++` libraries.

Each packet received from the client by the server is always answered with a binary network protocol.

  

* Usage:

```

∼/Rtype> ./r-type_server –h

USAGE: ./r-type_server [Ip] [Port]
This command will execute the server side of the R-Type project.
The server is able to handle multiple games in a row. With it you could run several games.
R-Type is an iconic side-scrolling shoot\'em up video game
```

i.e.

`./r-type_server 127.0.0.1 4201`

## Client

  
The client is written in C++ and use `SFML`, `Boost/Asio` libraries along with the standard C++ libraries.

It is made to connect to the providen server using TCP/IP and UDP connection protocol.


* Usage:

```

∼/Rtype> ./r-type_client –h

USAGE: ./r-type_client IP_Server Port_Server
This command will execute the client side of the R-Type project.
```

i.e.

`./r-type_client 127.0.0.1 4201`

## How to compile Rtype?

1. Switch to repository's root

2. Compile every binaries at once using the command `mkdir build && cd build && conan install .. && cmake .. -G "Unix Makefiles" && cmake –build .`

3. Start the server using the above written help message

4. Connect several clients and enjoy!

