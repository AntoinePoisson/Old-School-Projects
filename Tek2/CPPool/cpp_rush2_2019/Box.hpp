/*
** EPITECH PROJECT, 2020
** Box
** File description:
** Box
*/

#ifndef BOX_H
#define BOX_H

#include "Wrap.hpp"

class Box : public Wrap
{
    public:
        Box();
        Box(std::string str);
        ~Box();
        void wrapMeThat(Object *obj);
        void closeMe();
    private:
    protected:
};

#endif /* !BOX_H */
