/*
** EPITECH PROJECT, 2020
** ex04
** File description:
** ex04
*/

#include "string.h"

const char *c_str(const string_t *this)
{
    if (this)
        return (this->str);
    return (NULL);
}