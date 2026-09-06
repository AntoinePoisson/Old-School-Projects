/*
** EPITECH PROJECT, 2020
** Plazza
** File description:
** Order
*/

#include "kitchen/Order.hpp"

Plazza::Order::Order(pizza_s type, pizza_s size) : _type(type), _size(size)
{
}

Plazza::Order::Order(std::string type, std::string size)
{
    _time = 0;
    for (int i = (type.size() - 1);i >= 0;i--)
        type[i] = std::tolower(type[i]);
    for (int i = (size.size() - 1);i >= 0;i--)
        size[i] = std::tolower(size[i]);

    for (int i = (PizzaType.size() - 1);i >= 0;i--) {
        if (type.compare(PizzaType[i].name) == 0)
            _type = PizzaType[i];
    }
    for (int i = (PizzaSize.size() - 1);i >= 0;i--) {
        if (size.compare(PizzaSize[i].name) == 0)
            _size = PizzaSize[i];
    }
    for (int i = (PizzaType.size() - 1);i >= 0;i--) {
        if (type.compare(PizzaTime[i].name) == 0)
            _time = PizzaTime[i].value * stockage.getMultiplTimeCook();
    }
}

Plazza::Order::Order(int type, int size)
{
    _time = 0;
    _type = PizzaType[0];
    _size = PizzaSize[0];

    for (int i = (PizzaType.size() - 1);i >= 0;i--) {
        if (type == PizzaType[i].value)
            _type = PizzaType[i];
    }
    for (int i = (PizzaSize.size() - 1);i >= 0;i--) {
        if (size == PizzaSize[i].value)
            _size = PizzaSize[i];
    }
    for (int i = (PizzaTime.size() - 1);i >= 0;i--) {
        if (PizzaTime[i].name.compare(_type.name) == 0) {
            _time = PizzaTime[i].value * stockage.getMultiplTimeCook();
        }
    }
}

Plazza::pizza_s const &Plazza::Order::getType()
{
    return (_type);
}

Plazza::pizza_s const &Plazza::Order::getSize()
{
    return (_size);
}

int Plazza::Order::getTime()
{
    return (_time);
}