/*
** EPITECH PROJECT, 2020
** CPP_plazza_2019
** File description:
** Shell
*/

#include "shell/Shell.hpp"

    // Public
Plazza::Shell::Shell::Shell(std::string const &prompt, std::shared_ptr<Plazza::IGraphics> graph)
    : promptShell(prompt), stopShell(false)
{
    ncurse = (graph);
}

void Plazza::Shell::Shell::startShell(std::unique_ptr<Plazza::Reception::Reception> &recep)
{
    std::cout << "(  ___ \\ |\\     /|(  ____ \\  (  ___ \\ |\\     /|(  ____ \\  ( )" << std::endl;
    std::cout << "| (   ) )( \\   / )| (    \\/  | (   ) )( \\   / )| (    \\/  | |" << std::endl;
    std::cout << "| (__/ /  \\ (_) / | (__      | (__/ /  \\ (_) / | (__      | |" << std::endl;
    std::cout << "|  __ (    \\   /  |  __)     |  __ (    \\   /  |  __)     | |" << std::endl;
    std::cout << "| (  \\ \\    ) (   | (        | (  \\ \\    ) (   | (        (_)" << std::endl;
    std::cout << "| )___) )   | |   | (____/\\  | )___) )   | |   | (____/\\   _ " << std::endl;
    std::cout << "|/ \\___/    \\_/   (_______/  |/ \\___/    \\_/   (_______/  (_)" << std::endl;

    stopShell = false;
    counter = 0;
    reception = std::move(recep);
    ncurse->displayLine("Plazza -> How can I help you ?\n", true);
    reception->clearReception();
    commandCurrent.clear();
    commandCurrent.push_back("useless");
    while (!stopShell) {
        if (getCommand() == false) {
            reception->checker();
            continue;
        }
        if (leaveCommand())
            return (leaveReception());
        if (correctSyntaxCommand()) {
            executeCommand();
            reception->checker();
        }
    }
}


    // Private
bool Plazza::Shell::Shell::getCommand()
{
    std::string buff("");
    std::string tmp("");
    struct timeval timeout = {0, 100};
    fd_set readfds;

    if (commandCurrent.size() != 0 || counter > 0) {
        commandCurrent.clear();
        fflush(stdout);
        if (counter > 0)
            counter--;
    }
    ncurse->refreshWin();
    buff = ncurse->getInputCommand();
    if (buff.size() == 0 || buff == "")
        return (true);
    if (buff == "N")
        return (false);
    if (buff.size() == 0) {
        commandCurrent.push_back("NULL");
        return (false);
    }
    for (int i = 0; i < buff.size(); i++) {
        if (std::strncmp(&buff[i], "status", 6) == 0) {
            buff.replace(i, 6, "status " + PizzaSize[0].name + " x2 ");
            i += 11;
        }
    }
    for (int i = 0; i < buff.size(); i++) {
        if (buff[i] == ';')
            tmp += " ; ";
        else
            tmp += buff[i];
    }
    buff = tmp;
    std::stringstream ssInput(buff);
    for (int i = 1; ssInput >> tmp; i++) {
        if (!((i == 3) || (tmp == ";")))
            std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower); 
        else
            i = 0;
        commandCurrent.push_back(tmp);
    }
    return (true);
}

bool Plazza::Shell::Shell::correctSyntaxCommand()
{
    int type = CMD_TYPE;

    if (commandCurrent.size() < 3) {
        ncurse->displayLine("Plazza -> I need more Informations, to do your Pizza (Type, Size, Number)\n", true);
        return (false);
    }
    for (int i = 0; i < commandCurrent.size(); i++, type++) {
        if (type == CMD_TYPE && !checkCommandType(commandCurrent[i], i, &type))
            return (false);
        if (type == CMD_SIZE && !checkCommandSize(commandCurrent[i]))
            return (false);
        if (type == CMD_NBR && !checkCommandNbr(commandCurrent[i]))
            return (false);
        if (type == CMD_NBR)
            type = -1;
    }
    return (true);
}

bool Plazza::Shell::Shell::checkCommandType(std::string const &param, int i, int *type)
{
    if (param == ";") {
        *type = -1;
        if ((i == 0) || ((i + 3) >= commandCurrent.size())) {
            ncurse->displayLine("Plazza -> I don't understand, your next pizza");
            return (false);
        }
        return (true);
    }
    if (param == "status")
        return (true);
    for (int index = 0; PizzaType[index].value; index++) {
        if (PizzaType[index].name == param)
            return (true);
    }
    ncurse->displayLine("Plazza -> We don't have this Pizza: " + commandCurrent[i]);
    return (false);
}

bool Plazza::Shell::Shell::checkCommandSize(std::string const &param)
{
    for (int i = 0; PizzaSize[i].value; i++) {
        if (PizzaSize[i].name == param)
            return (true);
    }
    ncurse->displayLine("Plazza -> We don't have this Pizza's size: " + param);
    return (false);
}

bool Plazza::Shell::Shell::checkCommandNbr(std::string const &param)
{
    if ((param.size() == 1) || (param[0] != 'x') || (param.size() > 3)) {
        ncurse->displayLine("Plazza -> I don't understand. How many pizza you want ?");
        return (false);
    }
    if ((param.size() == 2 && param[1] == '0') ||
        (param.size() == 3 && param[1] == '0' && param[2] == '0')) {
        ncurse->displayLine("Plazza -> HAHA !!! Nice joke, your really want 0 Pizza ?");
        return (false);
    }
    if ((!('0' <= param[1] && '9' >= param[1])) ||
        (param.size() == 3 && !('0' <= param[2] && '9' >= param[2]))) {
        ncurse->displayLine("Plazza -> I don't understand. How many pizza you want ?");
        return (false);
    }
    return (true);
}

bool Plazza::Shell::Shell::leaveCommand()
{
    if ((commandCurrent.empty())) {
        ncurse->displayLine("Plazza -> See you, next time !");
        return (true);
    }
    if ((commandCurrent.at(0).compare("exit") == 0)
        || (commandCurrent.at(0).compare("leave") == 0)
        || (commandCurrent.at(0).compare("salut") == 0)) {
        ncurse->displayLine("Plazza -> See you, next time !");
        return (true);
    }
    return (false);
}

void Plazza::Shell::Shell::leaveReception()
{
    reception->clearReception();
    ncurse->destroy();
}

int Plazza::Shell::Shell::getCommandType(std::string const &param)
{
    for (int index = 0; PizzaType[index].value; index++) {
        if (PizzaType[index].name == param)
            return (PizzaType[index].value);
    }
    return (-1);
}

int Plazza::Shell::Shell::getCommandSize(std::string const &param)
{
    for (int i = 0; PizzaSize[i].value; i++) {
        if (PizzaSize[i].name == param)
            return (PizzaSize[i].value);
    }
    return (-1);
}

int Plazza::Shell::Shell::getCommandNbr(std::string const &param)
{
    int res = 0;

    try {
        res = std::stoi(&param[1]);
    } catch (...) {
        return (-1);
    }
    return (res);
}

void Plazza::Shell::Shell::executeCommand()
{
    int type = -1;
    int size = -1;
    int nbr = -1;

    for (int i = 0; i < commandCurrent.size(); i += 3) {
        if (commandCurrent[i] == ";") {
            i -= 2;
            continue;
        }
        if (commandCurrent[i] == "status") {
            reception->handleStatusCommand();
            counter += 10;
            continue;
        }
        ncurse->displayLine("Plazza -> Your Commande: " + commandCurrent[i] + ", " + commandCurrent[i + 1] + ", " + commandCurrent[i + 2] + " is on preparation.");
        type = getCommandType(commandCurrent[i]);
        size = getCommandSize(commandCurrent[i + 1]);
        nbr = getCommandNbr(commandCurrent[i + 2]);
        if (!(static_cast<enum Plazza::PizzaType> (type)) ||
            !(static_cast<enum Plazza::PizzaSize> (size)) || nbr == -1) {
            ncurse->displayLine("Plazza -> Sorry, I meet few Problemes. I can't do your Order :/");
            continue;
        }
        reception->handleNewCommand(static_cast<enum Plazza::PizzaType> (type),
            static_cast<enum Plazza::PizzaSize> (size), nbr);
    }
}

