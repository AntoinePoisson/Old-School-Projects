/*
** EPITECH PROJECT, 2020
** DomesticKoala
** File description:
** DomesticKoala
*/

#include "DomesticKoala.hpp"

DomesticKoala::~DomesticKoala()
{
}

DomesticKoala::DomesticKoala(KoalaAction & el)
: _action(&el)
{
}

DomesticKoala::DomesticKoala(const DomesticKoala & copy)
: _action(copy._action)
{
    unsigned int size = 0;

    for (auto i = copy._stockage.begin(); size < copy._stockage.size(); i++, size++)
        _stockage.push_back(*i);
    size = 0;
    for (auto i = copy._index.begin(); size < copy._index.size(); i++, size++)
        _index.push_back(*i);
}

void DomesticKoala::setKoalaAction(KoalaAction &action)
{
    _action = &action;
}

DomesticKoala & DomesticKoala::operator=(const DomesticKoala &copy)
{
    unsigned int size = 0;

    _action = copy._action;   
    if (_stockage.size())
        _stockage.clear();
    if (_index.size()) 
        _index.clear();
    for (auto i = copy._stockage.begin(); size < copy._stockage.size(); i++, size++)
        _stockage.push_back(*i);
    size = 0;
    for (auto i = copy._index.begin(); size < copy._index.size(); i++, size++)
        _index.push_back(*i);
    return (*this);
}

const std::vector<DomesticKoala::methodPointer_t> *DomesticKoala::getActions() const
{
    return (&_stockage);
}

void DomesticKoala::learnAction(unsigned char command, methodPointer_t action)
{
    _stockage.push_back(action);
    _index.push_back(command);
}

void DomesticKoala::unlearnAction(unsigned char command)
{
    unsigned int posi = 0;
    unsigned int size = 0;

    for (auto i = _index.begin(); size < _index.size() &&
        _index[posi] != command; i++, size++) {
            posi++;
    }
    // if (posi)
    //     posi--;
    if (posi < _index.size() && _index[posi] == command) {
        _index.erase(_index.begin() + posi);
        _stockage.erase(_stockage.begin() + posi);
    }
}

void DomesticKoala::doAction(unsigned char command, const std::string & param)
{
    unsigned int posi = 0;
    unsigned int size = 0;

    for (auto i = _index.begin(); size < _index.size() &&
        _index[posi] != command; i++, size++) {
        posi++;
    }
    // if (posi)
    //     posi--;
    if (posi < _index.size() && _index[posi] == command) {
        (*_action.*_stockage[posi])(param);
    }
}