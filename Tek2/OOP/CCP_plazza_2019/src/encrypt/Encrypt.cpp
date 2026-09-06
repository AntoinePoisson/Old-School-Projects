/*
** EPITECH PROJECT, 2019
** CCP_plazza_2019
** File description:
** encrypt.cpp
*/

#include "encrypt/Encrypt.hpp"

Plazza::Encrypt::Encrypt(std::string message)
{
    mess = message;
    c = mess.size();
}

std::string Plazza::Encrypt::pack()
{
    std::string out = mess;

    for(int i = 0; i < mess.size(); i++)
        out[i] = mess[i] ^ c;
    mess = out;
    return (out);
}

std::string Plazza::Encrypt::unpack()
{
    return (pack());
}