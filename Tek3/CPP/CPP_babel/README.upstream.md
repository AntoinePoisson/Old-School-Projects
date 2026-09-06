
# Babel

  


Babel is a multi-client, VOIP-SIP software.

  

## Server

  

The server is written in C++ and use TCP/IP connection protocol (RFC 793) using `Boost/Asio` and `Queue` along with `Standard C++` libraries.

Each wrong packet received, got answered by an error response.
Each packet received from the client by the server is always answered with a binary network protocol.

  

* Usage:

```

∼/Babel> ./babel_server –h

USAGE: ./babel_server [Ip] [Port]

ip is the internet protocol anchor from the distant server

port is the port number used by the network

```

i.e.

`./babel_server 127.0.0.1 4201`

  

## Client

  

The client is written in C++ and use `QT5`, `PortAudio` and `Opus` libraries along with the standard C++ libraries.

It is made to connect to the providen server using TCP/IP connection protocol (RFC 793).


* Usage:

```

∼/Babel> ./babel_client –h

USAGE: ./babel_client

```

i.e.

`./babel_client 127.0.0.1 4201`

  

## How to compile Babel?

  

1. Switch to repository's root

2. Compile every binaries at once using the command `mkdir build && cd build && conan install .. && cmake .. -G “Unix Makefiles” && cmake –build .`

3. Start the server using the above written help message

4. Connect several clients and enjoy!
  
  
## Technical documentation

The server uses TCP/IP network protocol (RFC 793) to communicate to each clients, using our in-house made encryption method to properly secure the connection.

The clients uses UDP network protocol (RFC 768) to communicate with each others.

The audio packets are compressed using the audio codec `Opus`, the audio packets are transmitted from the input, in instance this is the microphone, up to the network module using `PortAudio`

The communication between the server and the client is achieved with a header which contains the `size` of the entire network packet (which is binary), the body of the packet contains the pieces of information sent along with the main code to determine which type of information we are receiving.

