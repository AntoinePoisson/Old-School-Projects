/*
** EPITECH PROJECT, 2020
** ex04
** File description:
** ex04
*/

#include "string.h"

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    int i = 0;

    if (!this || !this->str || s == NULL ||
        pos > strlen(this->str))
        return (0);
    for (; n > 0 && pos < strlen(this->str); i++, pos++, n--) {
        s[i] = this->str[pos];
    }
    return (i);
}