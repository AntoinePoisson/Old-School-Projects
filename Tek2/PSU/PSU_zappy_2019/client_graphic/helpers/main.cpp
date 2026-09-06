/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** main
*/

#include "Server.hpp"
#include "Controller.hpp"
#include "Exception.hpp"

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sstream>

unsigned short getPortNumber(int ac, const char **av)
{
    if (ac != 2) {
        throw ControllerException("2 arguments expected");
    }
    std::string portNumber = av[1];
    for (auto it = portNumber.begin(); it != portNumber.end(); it++)
        if (!std::isdigit(*it))
            throw ControllerException("second argument must be a port number");
    return static_cast<unsigned short>(std::stoi(portNumber));
}



std::vector<struct cell_s> factory(int x, int y)
{
    cell_player_t player = {"izi", "saperlipopette", Up};

    struct cell_s cell;
    bzero(&cell, sizeof(struct cell_s));
    cell.x = 0;
    cell.y = 0;
    cell.food = 1;
    cell.phiras = 1;
    cell.players[0] = player;

    std::vector<struct cell_s> cells;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            cell.x = j;
            cell.y = i;
            cells.push_back(cell);
            // std::cout << "x =" <<  cells.rbegin()->x << std::endl; 
        }
    }
    return cells;
}

void communicate(int x, int y, Server &server)
{
    
    int fd = server.checkIncommingConnection();
    std::vector<struct cell_s> cells = factory(x, y);

    //protocol
    server.sendStrRequest(fd, "WELCOME");
    std::cout << "fd = " << fd << std::endl;
    // std::cout << "here2" << std::endl;
    while (server.checkClientRequest() == -1);
    std::string type = server.readClientRequestStr(fd);
    if (type.compare("GRAPHIC") == 0)
        std::cout << "ok client graphic" << std::endl;
    else
        std::cout << "no client graphic" << std::endl;
    //sendClient Number
    server.sendStrRequest(fd, "442");
    //send X Y\n
    std::stringstream ss ;
    ss << std::to_string(x) << " " << std::to_string(y);
    // std::cout << "Send: "<< ss.str() << std::endl;
    server.sendStrRequest(fd, ss.str());
    //message
    // std::cout << cells.size() << std::endl;
    server.sendRequest<int>(fd, (int) cells.size());
    while (server.checkClientRequest() == -1);
    server.readClientRequestStr(fd);
    int size = (int) cells.size();
    for (int i = 0; i < size; i++) {
        // usleep(1000);
        // std::cout << "x = " << cells[i].x << std::endl;
        server.sendRequest<struct cell_s>(fd, cells[i]);
    }
    
    return ;
}

std::pair<int, int> getMapDimensions(Interpreter &_interpreter)
{
    // read Welcome
    while (_interpreter.serverIsWriting() == false);
    std::cout << _interpreter.listenToServerStr() << std::endl;
    //send GRAPHIC
    _interpreter.sendStrRequest("GRAPHIC");
    //readClientNum
    while (_interpreter.serverIsWriting() == false);
    _interpreter.listenToServerStr();
    // std::cout << "here" << _interpreter.listenToServerStr() << std::endl;
    // std::cout << "end" << std::endl;
    //readCoordinates
    while (_interpreter.serverIsWriting() == false);
    std::string str = _interpreter.listenToServerStr();
    // std::cout << "received " << str << std::endl;
    std::istringstream iss(str);
    std::vector<std::string> results(std::istream_iterator<std::string>{iss},
                                 std::istream_iterator<std::string>());  
    // std::cout << "getting coo" << std::endl;
    _interpreter.sendStrRequest("DONE");
    return {std::stoi(results[0]), std::stoi(results[1])};
}
int main()
{
    unsigned short portNumber = 60046;

    Server s(portNumber);
    int x = 10;
    int y = 10;
    pid_t pid;

    try {
        if ((pid = fork()) == 0) {
            communicate(x, y, s);
            std::cout << "server quit" << std::endl;
        } else {
            Interpreter _interpreter(portNumber);
            std::pair<int, int> coo = getMapDimensions(_interpreter);
            std::cout << "ctrl" << std::endl;
            Controller ctrl(coo.first, coo.second, _interpreter);
            std::cout << "looop" << std::endl; 
            ctrl.loop();
            exit(0);
        }
        while (waitpid(pid, NULL, 0) == -1);
        std::cout << "not wait" << std::endl;
    } catch (const CliGraphException &e) {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}