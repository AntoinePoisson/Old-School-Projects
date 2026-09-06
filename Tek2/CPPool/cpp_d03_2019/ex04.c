/*
** EPITECH PROJECT, 2020
** ex04
** File description:
** ex04
*/

#include "string.h"

void clear(string_t *this)
{
    if (this) {
        this->str = realloc(this->str, 1);
        if (this->str)
            this->str[0] = 0;
    }
}