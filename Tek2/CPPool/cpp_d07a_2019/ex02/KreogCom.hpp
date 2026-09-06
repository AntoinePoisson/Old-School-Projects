/*
** EPITECH PROJECT, 2020
** KreogCom
** File description:
** KreogCom
*/

#ifndef KREOGCOM_H
#define KREOGCOM_H

#include <string>
#include <iostream>

class KreogCom
{
    public:
        KreogCom(int x, int y, int serial);
        ~KreogCom();
        void addCom(int x, int y, int serial);
        void removeCom();
        KreogCom *getCom();
        void ping();
        void locateSquad();

    private:
        int _serial;
        int _x;
        int _y;
        KreogCom* _next;
};

#endif /* !KREOGCOM */
