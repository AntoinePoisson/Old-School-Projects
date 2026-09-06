/*
** EPITECH PROJECT, 2020
** ex01
** File description:
** ex01
*/

#include "string.h"

void assign_s(string_t *this, const string_t *str)
{
    if (!this)
        return;
    free(this->str);
    this->str = NULL;
    if (!str)
        return;
    this->str = strdup(str->str);
}

void assign_c(string_t *this, const char *s)
{
    if (!this)
        return;
    free(this->str);
    this->str = NULL;
    if (!s)
        return;
    this->str = strdup(s);
}