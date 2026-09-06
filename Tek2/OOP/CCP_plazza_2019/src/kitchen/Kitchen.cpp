/*
** EPITECH PROJECT, 2020
** CPP_plazza_2019
** File description:
** Kitchen
*/

#include "kitchen/Kitchen.hpp"

    // Public
Plazza::Kitchen::Kitchen(std::unique_ptr<Plazza::IIPC> &newIPC)
    : IPC(newIPC)
{
    Plazza::stockage.getLogFile() << "Create New kitchen id: " << std::to_string(IPC->getCanalListen()) << std::endl;
    signal(SIGQUIT, destroyKitchen);
    timeStart = std::chrono::system_clock::now();
    freeCook = Plazza::stockage.getNbrCookPerKitchen();
    for (int i = freeCook;i > 0; i--) {
        addCook();
    }
    nbrPizza = 0;
    busyCook = 0;
    timeOut = 0;
}

void Plazza::Kitchen::destroyKitchen(int useless)
{
    if (useless) {
    }
    Plazza::stockage.getLogFile() << "Destroy kitchen by Signal" << std::endl;
    exit(0);
}

void Plazza::Kitchen::loop()
{
    for (bool first = true;; first = false) {
        busyCook = Plazza::stockage.getNbrCookPerKitchen() - (nbrPizza - (_orderQueue.size() + _pizzaCooked.size()));
        freeCook = Plazza::stockage.getNbrCookPerKitchen() - busyCook;
        if (first)
            IPC->sendMessage("Kitchen (" + std::to_string(IPC->getCanalListen()) + ") is Open");
        if (checkTimeOutActivity())
            IPC->sendMessage("Close");
        if (IPC->nbrMessage() > 0) {
            std::string message = IPC->getMessage();
            if (message != "") {
                Plazza::stockage.getLogFile() << "Kitchen (" + std::to_string(IPC->getCanalListen()) << ") receive : '"<< message << "'" <<std::endl;
                handleReceiveNewMessage(message);
            }
        }
        if (_pizzaCooked.size() > 0)
            sendPizza();
    }
}


    // Private
bool Plazza::Kitchen::checkTimeOutActivity()
{
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    int elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(now - timeStart).count();
    if (timeOut >= 3) {
        destroyKitchen(0);
    }
    if (elapsed_seconds >= TIMEOUT && nbrPizza == 0) {
        timeStart = std::chrono::system_clock::now();
        timeOut += 1;
        return (true);
    }
    return (false);
}

void Plazza::Kitchen::handleReceiveNewMessage(std::string message)
{
    if (message == "status") {
        IPC->sendMessage("status " + std::to_string(IPC->getCanalListen()) + " " + std::to_string(freeCook) + " " + std::to_string(nbrPizza));
        timeStart = std::chrono::system_clock::now();
        return;
    }
    if (message == "getInfo") {
        IPC->sendMessage("getInfo " + std::to_string(IPC->getCanalListen()) + " " + std::to_string(freeCook) + " " + std::to_string(nbrPizza));
        timeStart = std::chrono::system_clock::now();        
        return;
    }
    std::vector<std::string> parse = IPC->getMessageParse(message);
    if (parse.size() == 4 && parse[0] == "pizza" &&
        (std::regex_match(parse[1], std::regex("\\d+"))) &&
        (std::regex_match(parse[2], std::regex("\\d+"))) &&
        (std::regex_match(parse[3], std::regex("\\d+")))) {
        timeStart = std::chrono::system_clock::now();
        ///////////////////////////////////////////////////////
        /////  Function Pour Gerr l'ajout d'une pizza     /////
        ///////////////////////////////////////////////////////

        /*
            -> Check que les parametres soit correcte
            -> Check qu'il y a bien assez de place dans la kitchen pour gerer des pizza en plus
            -> Mettre a jour ne nbr de cook use, cook free & le nbr de pizza
            -> Parametre:
                parse[1] = Type Pizza
                parse[2] = Size Pizza
                parse[3] = nbr Pizza
        */
        nbrPizza += std::stoi(parse[3]);
        if (nbrPizza > ((busyCook + freeCook) * 2)) {
            Plazza::stockage.getLogFile() << "order " + std::to_string(IPC->getCanalListen()) + " " + parse[1] + " " + parse[2] + " " + parse[3] + " Isn't possible";
            nbrPizza -= std::stoi(parse[3]);
        } else {
            for (int i = std::stoi(parse[3]);i > 0;i--) {
                addOrder(parse[1], parse[2]);
            }
            Plazza::stockage.getLogFile() << "Kitchen (" + std::to_string(IPC->getCanalListen()) << ") has new pizza (nbr:" << parse[3] <<")" <<std::endl;
        }
        // if la commande est prete:
        //IPC->sendMessage("order " + std::to_string(IPC->getCanalListen()) + " " + parse[1] + " " + parse[2] + " " + parse[3]);
    }
}

void Plazza::Kitchen::addCook()
{
    Plazza::Cooker *c = new Plazza::Cooker(_orderQueue, _pizzaCooked);

    _cooks.push_back(c);
}

void Plazza::Kitchen::addOrder(std::string type, std::string size)
{
    Plazza::Order ordr(std::stoi(type), std::stoi(size));

    _orderQueue.push(ordr);
}

void Plazza::Kitchen::sendPizza()
{
    for (int i = (_pizzaCooked.size() - 1);i >= 0;i--) {
        Plazza::stockage.getLogFile() << "Kitchen (" << std::to_string(IPC->getCanalListen()) << "): send pizza " << _pizzaCooked[i].getType().value<< " " << _pizzaCooked[i].getSize().value << " 1" << std::endl;
        IPC->sendMessage("order " + std::to_string(IPC->getCanalListen()) + " " + std::to_string(_pizzaCooked[i].getType().value) + " " + std::to_string(_pizzaCooked[i].getSize().value) + " " + "1");
        _pizzaCooked.pop_back();
        nbrPizza--;
    }
}