/*
** EPITECH PROJECT, 2020
** Object
** File description:
** Rush2
*/

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <iostream>
#include <string>

class Object {
    public:
        Object();
        Object(std::string str);
        ~Object();
        virtual void isTaken() const = 0;
        std::string getTitle() const;
    protected:
        std::string title;
    private:
};

#endif