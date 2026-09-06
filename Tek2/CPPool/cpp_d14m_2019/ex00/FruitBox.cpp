/*
** EPITECH PROJECT, 2020
** Fruit
** File description:
** Fruit
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size)
{
    _size_max = size;
    _size_currently = 0;
	_next = nullptr;
	_head = nullptr;
}

FruitBox::~FruitBox()
{
}

int FruitBox::nbFruits() const
{
    return (_size_currently);
}

bool FruitBox::putFruit(Fruit *f)
{
    FruitNode_t *save = _next;
    
    if ((!f) || (_size_currently >= _size_max))
        return (false);
    if (_next == nullptr) {
        FruitNode_t *element = new FruitNode_t;
        element->next = nullptr;
        element->data = f;
        _next = element;
        _head = element;
        _size_currently += 1;
        return (true);
    }
    while (_next && _next->next) {
        _next = _next->next;
        if (_next->data == f) {
            return (false);
        }
    }
    if (_next->data == f) {
        return (false);
    }
    FruitNode_t *element = new FruitNode_t;
    element->next = nullptr;
    element->data = f;
    _next->next = element;
    _next = save;
    _size_currently += 1;
    return (true);
}

Fruit *FruitBox::pickFruit()
{
    if (_next == nullptr || _head == nullptr)
        return (nullptr);
    _size_currently -= 1;
    _next = _next->next;
    Fruit *result = _head->data;
    _head = _next;
    return (result);
}

FruitNode_t *FruitBox::head() const
{
    return (_head);
}
