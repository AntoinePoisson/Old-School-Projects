/*
** EPITECH PROJECT, 2020
** ex04
** File description:
** ex04
*/

#include "string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    if (str)
        return (find_c(this, str->str, pos));
    return (-1);
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    if (!this || !this->str || !str || pos > strlen(this->str))
        return (-1);
    for (int i = pos; this->str[i]; i++) {
        if (strstr(&this->str[i], str)) {
            return (i);
        }
    }
    return (-1);
}