/*
** EPITECH PROJECT, 2020
** ex04
** File description:
** ex04
*/

#include "string.h"

int size(const string_t *this)
{
    if (!this || !this->str)
        return (-1);
    return (strlen(this->str));
}