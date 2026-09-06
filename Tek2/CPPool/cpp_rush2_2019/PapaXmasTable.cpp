/*
** EPITECH PROJECT, 2020
** PapaXmasTable
** File description:
** PapaXmasTable
*/

#include "PapaXmasTable.hpp"

PapaXmasTable::PapaXmasTable()
{
    Object **result = new Object*[table_size + 1];

    for (int i = 0; i < table_size; i++)
        result[i] = nullptr;
    this->ObjectOnTable = result;
    std::cout << "Creation Table" << std::endl;
}

PapaXmasTable::~PapaXmasTable()
{
 /*   for (int i = 0; i < table_size; i++)
        delete this->ObjectOnTable[i];
        */
}

bool PapaXmasTable::addTable(Object *obj)
{
    int i = 0;

    for (; ObjectOnTable[i]; i++) {
    }
    if (i >= table_size - 1) {
        for (i = 0; i < table_size; i++) {
            ObjectOnTable[i] = nullptr;
        }
        std::cout << "Table Collapses" << std::endl;
        return (false);
    }
    ObjectOnTable[i] = obj;
    std::cout << obj->getTitle() << " add on Table" << std::endl;
    return (true);
}