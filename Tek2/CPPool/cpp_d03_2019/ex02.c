/*
** EPITECH PROJECT, 2020
** ex02
** File description:
** ex02
*/

#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    if (ap)
        append_c(this, ap->str);
}

void append_c(string_t *this, const char *ap)
{
    int size = 0;

    if (!ap || !this)
        return;
    if (this->str)
        size = strlen(this->str);
    this->str = realloc(this->str,
    (sizeof(char) * (size + strlen(ap) + 1)));
    if (this->str)
        this->str = strcat(this->str, ap);
}