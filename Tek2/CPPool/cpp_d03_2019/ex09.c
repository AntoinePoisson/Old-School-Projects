/*
** EPITECH PROJECT, 2020
** ex04
** File description:
** ex04
*/

#include "string.h"

int empty(const string_t *this)
{
    if (this && this->str == NULL)
        return (1);
    return (0);
}