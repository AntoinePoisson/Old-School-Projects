/*
** EPITECH PROJECT, 2020
** CPP_plazza_2019
** File description:
** Reception
*/

#include "reception/Reception.hpp"

    // Public
Plazza::Reception::Reception::Reception(std::shared_ptr<Plazza::IGraphics> graph)
    : indexKitchen(1)
{
    getStatus = false;
    ncurse = graph;
    Plazza::QueueMessage IPC("clear", 1, RECEP, RECEP);
}

void Plazza::Reception::Reception::clearReception()
{
    destroyAllKitchen();
}

void Plazza::Reception::Reception::handleNewCommand(enum Plazza::PizzaType type, enum Plazza::PizzaSize size, uint32_t nbr)
{
    getInfosKitchen();
    repartitionPizza(nbr);
    for (int i = 0; i < listKitchenInfo.size(); i++) {
        if (listKitchenInfo[i].nbrPizza != 0) {
            sendOrderToKitchen(type, size, listKitchenInfo[i].nbrPizza, listKitchenInfo[i].index);
        }
    }
    listKitchenInfo.clear();
}

void Plazza::Reception::Reception::checker()
{
    std::string message("");

    for (int i = 0; i < listKitchen.size(); i++) {
        if (listKitchen[i].IPC->nbrMessage() > 0) {
            message = listKitchen[i].IPC->getMessage();
            if (message != "")
                managementMessageKitchen(message, i);
        }
    }
    for (int i = 0; i < listDoneOrder.size(); i++)
        ncurse->displayLine(listDoneOrder[i], false);
    listDoneOrder.clear();
}

void Plazza::Reception::Reception::handleStatusCommand()
{
    if (listKitchen.size() == 0) {
        ncurse->displayLine("Currently, There is no Kitchen open", false);
        return;
    }
    listKitchenStatus.clear();
    getStatus = true;
    for (int i = 0; i < listKitchen.size(); i++)
        listKitchen[i].IPC->sendMessage("status");
}


    // Private
void Plazza::Reception::Reception::destroyAllKitchen()
{
    for (int i = 0; i < listKitchen.size(); i++) {
        kill(listKitchen[i].pid, SIGQUIT);
        delete listKitchen[i].IPC;
    }
    listKitchen.clear();
}

bool Plazza::Reception::Reception::addNewKitchen()
{
    pid_t pid = fork();

    indexKitchen++;
    if (pid == -1) {
        perror("fork");
        return (false);
    }
    if (pid == 0) {
        try {
            std::unique_ptr<Plazza::IIPC> base;
            base = std::make_unique<Plazza::QueueMessage>("keyChildren_" + std::to_string(indexKitchen), indexKitchen * 8, indexKitchen, RECEP);
            Plazza::Kitchen kitchen(base);
            kitchen.loop();
            kitchen.destroyKitchen(0);
            exit(0);
        } catch (Plazza::Throw::QueueMessage const & queue) {
            std::cerr << queue.what() << std::endl;
            exit(84);
        }
    }
    kitchen_t newElement;
    newElement.pid = pid;
    newElement.index = indexKitchen;
    try {
        newElement.IPC = new Plazza::QueueMessage("keyParent_" + std::to_string(indexKitchen), indexKitchen * 9, RECEP, indexKitchen);
    } catch (Plazza::Throw::QueueMessage const & queue) {
        std::cerr << queue.what() << std::endl;
        return (false);
    }
    listKitchen.push_back(newElement);
    return (false);
}

void Plazza::Reception::Reception::destroyKitchen(int index)
{
    if (index > listKitchen.size() || index < 0)
        return;
    kill(listKitchen[index].pid, SIGQUIT);
    listKitchen.erase(listKitchen.begin() + index);
}

void Plazza::Reception::Reception::managementMessageKitchen(std::string message, int index)
{
    std::vector<std::string> parse;

    if (message == "Close") {
        Plazza::stockage.getLogFile() << "Reception receive : 'Close' (it's confirmation Kitchen (" << listKitchen[index].IPC->getCanalSend() << ") is close)" << std::endl;
        for (int i = 0; i < listKitchenInfo.size(); i++)
            if (listKitchen[index].index == listKitchenInfo[i].index)
                listKitchenInfo.erase(listKitchenInfo.begin() + i);
        destroyKitchen(index);
        return;
    }
    Plazza::stockage.getLogFile() << "Reception receive : '" << message << "' (for kitchen (" << listKitchen[index].IPC->getCanalSend() << "))" << std::endl;
    parse = listKitchen[index].IPC->getMessageParse(message);
    if (parse[0] == "status" && getStatus == true)
        getStatusKitchen(parse);
    if (parse[0] == "order" && parse.size() == 5)
        addOrderFinish(parse);
}

bool Plazza::Reception::Reception::sendOrderToKitchen(enum Plazza::PizzaType type, enum Plazza::PizzaSize size, uint32_t nbr, int indexKitch)
{
    int index = -1;
    std::string message("");

    if (indexKitch == -1) {
        indexKitch = indexKitchen;
    }
    for (int i = 0; index == -1 && i < listKitchen.size(); i++)
        if (listKitchen[i].index == indexKitch)
            index = i;
    if ((index < 0))
        return (false);
    message = "pizza " + std::to_string(type) + " " + std::to_string(size) + " " + std::to_string(nbr);
    listKitchen[index].IPC->sendMessage(message);
    return (true);
}

void Plazza::Reception::Reception::getStatusKitchen(std::vector<std::string> element)
{
    kitchenInfo_t newElement;

    if ((element.size() != 4) ||
        (!std::regex_match(element[1], std::regex("\\d+"))) ||
        (!std::regex_match(element[2], std::regex("\\d+"))) ||
        (!std::regex_match(element[3], std::regex("\\d+"))))
        return;
    newElement.index = std::stoi(element[1]);
    newElement.freeCook = std::stoi(element[2]);
    newElement.nbrPreparationPizza = std::stoi(element[3]);
    listKitchenStatus.push_back(newElement);
    if (listKitchenStatus.size() >= listKitchen.size()) {
        for (int i = 0; i < listKitchenStatus.size(); i++) {
            ncurse->displayLine("n°" + std::to_string(i + 1) + " Kitchen (id: " + std::to_string(listKitchenStatus[i].index) + ") has " +
                std::to_string(listKitchenStatus[i].freeCook) + "/" + std::to_string(Plazza::stockage.getNbrCookPerKitchen()) + " cook free and " + std::to_string(listKitchenStatus[i].nbrPreparationPizza) +
                " pizza in preparation.", false);
        }
        fflush(stdout);
        getStatus = false;
        listKitchenStatus.clear();
    }
}

void Plazza::Reception::Reception::getInfosKitchen()
{
    std::string message;
    std::vector<std::string> listMessage;
    kitchenInfo_t newElement;

    listKitchenInfo.clear();
    for (int i = 0; i < listKitchen.size(); i++)
        listKitchen[i].IPC->sendMessage("getInfo");
    for (int time = 0; time < 300 && listKitchen.size() > listKitchenInfo.size(); time++) {
        for (int i = 0; i < listKitchen.size(); i++) {
            if (listKitchen[i].IPC->nbrMessage() > 0) {
                message = listKitchen[i].IPC->getMessage();
                if (message == "")
                    continue;
                listMessage = listKitchen[i].IPC->getMessageParse(message);
                if (listMessage.size() == 4 && listMessage[0] == "getInfo") {
                    newElement.index = std::stoi(listMessage[1]);
                    newElement.freeCook = std::stoi(listMessage[2]);
                    newElement.nbrPreparationPizza = std::stoi(listMessage[3]);
                    newElement.nbrPizza = 0;
                    listKitchenInfo.push_back(newElement);
                }
                managementMessageKitchen(message, i);
            }
        }
    }
}

void Plazza::Reception::Reception::repartitionPizza(int nbrPizza)
{
    int totalSize = 0;
    int totalPizza = 0;
    kitchenInfo_t newElement;

    for (int i = 0; i < listKitchenInfo.size(); i++) {
        totalSize += listKitchenInfo[i].freeCook;
        totalPizza += listKitchenInfo[i].nbrPreparationPizza;
    }
    totalSize = (totalSize * 2);
    while (totalPizza + nbrPizza > totalSize) {
        addNewKitchen();
        newElement.index = indexKitchen;
        newElement.freeCook = Plazza::stockage.getNbrCookPerKitchen();
        newElement.nbrPreparationPizza = 0;
        newElement.nbrPizza = 0;
        listKitchenInfo.push_back(newElement);
        totalSize += (newElement.freeCook * 2);
    }
    for (int indexElement = 0; nbrPizza > 0; indexElement = 0) {
        for (int i = 0; i < listKitchenInfo.size(); i++)
            if ((listKitchenInfo[i].nbrPreparationPizza + listKitchenInfo[i].nbrPizza) <
                (listKitchenInfo[indexElement].nbrPreparationPizza + listKitchenInfo[indexElement].nbrPizza))
                indexElement = i;
        listKitchenInfo[indexElement].nbrPizza += 1;
        nbrPizza -= 1;
    }
}

void Plazza::Reception::Reception::addOrderFinish(std::vector<std::string> parse)
{
    std::string res("Kitchen (" + parse[1] +") has Finish his order: ");
    int indexPizza = stoi(parse[2]);
    int indexSize = stoi(parse[3]);

    for (int i = 0; Plazza::PizzaType[i].value; i++) {
        if (Plazza::PizzaType[i].value == indexPizza)
        res += Plazza::PizzaType[i].name;
    }
    for (int i = 0; Plazza::PizzaSize[i].value; i++) {
        if (Plazza::PizzaSize[i].value == indexSize)
        res += " " + Plazza::PizzaSize[i].name;
    }
    res += " x" + parse[4];
    Plazza::stockage.getLogFile() << res << std::endl;
    listDoneOrder.push_back(res);
}