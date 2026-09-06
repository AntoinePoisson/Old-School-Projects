/*
** EPITECH PROJECT, 2020
** Squad
** File description:
** Squad
*/

#include "Squad.hpp"

Squad::Squad()
{
    count = 0;
    size_tab = 50;
    position = 0;
    list = new ISpaceMarine*[size_tab + 1];

    for (int i = 0; i < size_tab; i++)
        list[i] = nullptr;
}

Squad::Squad(const Squad & squad)
{
	count = squad.count;
    position = 0;
	size_tab = squad.size_tab;
	list = new ISpaceMarine*[size_tab + 1];
	for (int i = 0; i < size_tab; i++) {
 		if (squad.list[i]) {
			list[i] = squad.list[i]->clone();
		} else {
		    list[i] = nullptr;
        }
	}
}

Squad::~Squad()
{
    for (int i = 0; i < size_tab; i++)
        delete list[i];
    delete []list;
}

int Squad::getCount() const
{
    return (position);
}

ISpaceMarine *Squad::getUnit(int index)
{
    if (index < 0 || index > size_tab)
        return (nullptr);
    return (list[index]);
}

int Squad::push(ISpaceMarine *element)
{
    if (!element)
        return (position);
    for (int i = 0; i < size_tab; i++) {
        if (list[i] == element)
            return (position);
    }
    if (position >= size_tab)
        increasing_table();
    list[position] = element;
    position += 1;
    return (position);
}

void Squad::increasing_table()
{
    int old_size = size_tab;
    size_tab = size_tab * 2;
    ISpaceMarine **elemet = new ISpaceMarine*[size_tab + 1];

    for (int i = 0; i < size_tab; i++)
        elemet[i] = nullptr;
    for (int i = 0; i < old_size; i++)
        elemet[i] = list[i];
    delete []list;
    list = elemet;
}

Squad & Squad::operator=(const Squad & squad) {
	for (int i = 0; i < size_tab; i++) {
		delete list[i];
	}
	delete[] list;
	count = squad.count;
	size_tab = squad.size_tab;
	list = new ISpaceMarine*[size_tab + 1];
	for (int i = 0; i < size_tab; i++) {
		if (squad.list[i]) {
			list[i] = squad.list[i]->clone();
		} else {
		    list[i] = nullptr;
        }
	}
	return *this;
}