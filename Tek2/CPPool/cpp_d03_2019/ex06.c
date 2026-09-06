/*
** EPITECH PROJECT, 2020
** ex04
** File description:
** ex04
*/

#include "string.h"

int compare_s(const string_t *this, const string_t *str)
{
    if (!this || !this->str || !str || !str->str)
        return (0);
    return (strcmp(this->str, str->str));
}

int compare_c(const string_t *this, const char *str)
{
    if (!this || !this->str || !str)
        return (0);
    return (strcmp(this->str, str));
}