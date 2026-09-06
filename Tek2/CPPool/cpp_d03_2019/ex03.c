/*
** EPITECH PROJECT, 2020
** ex03
** File description:
** ex03
*/

#include "string.h"

char at(const string_t *this, size_t pos)
{
    if (this && this->str && strlen(this->str) > pos)
        return (this->str[pos]);
    return (-1);
}