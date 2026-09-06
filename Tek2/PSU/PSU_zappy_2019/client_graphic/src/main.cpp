/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** main
*/

#include "Controller.hpp"
#include "Exception.hpp"

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
    //readCoordinates
    while (_interpreter.serverIsWriting() == false);
    std::string str = _interpreter.listenToServerStr();
    std::istringstream iss(str);
    std::vector<std::string> results(std::istream_iterator<std::string>{iss},
                                 std::istream_iterator<std::string>());  
    return {std::stoi(results[0]), std::stoi(results[1])};
}

int main(int ac, const char **av)
{
    try {
        unsigned short portNumber = getPortNumber(ac, av);
        Interpreter _interpreter(portNumber);
        std::pair<int, int> coo = getMapDimensions(_interpreter);

        Controller ctrl(coo.first, coo.second, _interpreter);
        ctrl.loop();
    } catch (const CliGraphException &e) {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}