/*
** EPITECH PROJECT, 2020
** Itable
** File description:
** Itable
*/

#include "Itable.hpp"

Itable::Itable()
{
    Object **result = new Object*[table_size + 1];

    for (int i = 0; i < table_size ; i++)
        result[i] = nullptr;
    this->ObjectOnTable = result;
    std::cout << "Creation Table" << std::endl;
}

Itable::~Itable()
{
/*    for (int i = 0; i < table_size; i++)
        delete this->ObjectOnTable[i];
    std::cout << "Destruction Table" << std::endl;
*/
}

Itable *Itable::createTable()
{
    return (new Itable());
}

std::string **Itable::look() const
{
    std::string **result = new std::string*[table_size + 1];

    for (int i = 0; i < table_size; i++)
        result[i] = nullptr;
    if (ObjectOnTable[0] == nullptr) {
        std::cout << "Void Table" << std::endl;
        return (result);
    }
    for (int i = 0; i < table_size; i++)
        result[i] = new std::string(ObjectOnTable[i]->getTitle());
    for (int i = 0; result[i]; i++)
        result[i] ? std::cout << "[" << i << "] - " << result[i] << std::endl :
        std::cout << "[" << i << "] ++ Nothing" << std::endl;
    return (result);
}

bool Itable::addTableObject(Object *obj)
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

bool Itable::addTableObject(Object *obj, int index, bool force_add)
{   
    if (index < 0 || index > table_size - 1) {
        std::cout << "Out of table position" << std::endl;
        return (false);
    }
    if (ObjectOnTable[index] != nullptr) {
        if (force_add) {
            return (addTableObject(obj));
        }
        std::cout << "Can't be put on Table" << std::endl;
        return (false);
    }
    ObjectOnTable[index] = obj;
    return (true);
}

bool Itable::deleteTableObject(int index)
{   
    if (index < 0 || index > table_size - 1) {
        std::cout << "Out of table position" << std::endl;
        return (false);
    }
    if (ObjectOnTable[index] == nullptr) {
        std::cout << "Nothing to delete" << std::endl;
        return (false);
    }
    ObjectOnTable[index] = nullptr;
    std::cout << "Table success delete" << std::endl;
    return (true);
}

bool Itable::deleteTableObject(Object *obj)
{   
    if (!obj)
        return (false);
    for (int i = 0; i < table_size; i++) {
        if (ObjectOnTable[i] && ObjectOnTable[i]->getTitle() == obj->getTitle()) {
            std::cout << "Table success delete" << std::endl;
            ObjectOnTable[i] = nullptr;
            return (true);
        }
    }
    return (false);
}

Object *Itable::take()
{   
    Object *save = nullptr;

    for (int i = 0; i < table_size; i++) {
        if (ObjectOnTable[i]) {
            save = ObjectOnTable[i];
            deleteTableObject(i);
            return (save);
        }
    }
    return (nullptr);
}