/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** Thread
*/

#include <iostream>
#include "kitchen/Cooker.hpp"
#include "ipc/QueueMessage.hpp"

void Plazza::Cooker::cooking()
{
    Plazza::Order temp;

    while (!_stop) {
        if (_order.tryPop(temp)) {
            makePizza(temp.getType(), temp.getSize());
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

void Plazza::Cooker::makePizza(Plazza::pizza_s type, Plazza::pizza_s size)
{
    int time = 0;

    if (type.value == Plazza::PizzaType::Americana 
    || type.value == Plazza::PizzaType::Fantasia
    || type.value == Plazza::PizzaType::Margarita
    || type.value == Plazza::PizzaType::Regina) {
        Plazza::Order pizza(type.value, size.value);
        //Plazza::stockage.getLogFile() << "Cook start making " << type.name << " (time: " << pizza.getTime() << " s. mutl: " << Plazza::stockage.getMultiplTimeCook() << ")" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(pizza.getTime()));
        _pizzaCooked.push_front(pizza);
        //Plazza::stockage.getLogFile() << "Cook: " << type.name << " is ready !" << std::endl;
    }
}

Plazza::Cooker::Cooker(SafeQueue<Plazza::Order> &order, std::deque<Plazza::Order> &pizzaCooked) : _stdThread(&Plazza::Cooker::cooking, this), _order(order), _pizzaCooked(pizzaCooked), _stop(false)
{
}

Plazza::Cooker::~Cooker()
{
    join();
}

bool Plazza::Cooker::joinable() const
{
    return (_stdThread.joinable());
}

void Plazza::Cooker::join()
{
    _stdThread.join();
}

void Plazza::Cooker::detach()
{
    _stdThread.detach();
}