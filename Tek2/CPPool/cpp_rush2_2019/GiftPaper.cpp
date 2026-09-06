/*
** EPITECH PROJECT, 2020
** GiftPaper
** File description:
** GiftPaper
*/

#include "GiftPaper.hpp"

GiftPaper::GiftPaper()
{
    open = true;
}

GiftPaper::GiftPaper(std::string str) : Wrap(str)
{
    open = true;
}

GiftPaper::~GiftPaper()
{
}