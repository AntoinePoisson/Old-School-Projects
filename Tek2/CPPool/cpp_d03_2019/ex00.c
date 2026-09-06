/*
** EPITECH PROJECT, 2020
** ex00
** File description:
** ex00
*/

#include "string.h"

void string_init(string_t *this, const char *s)
{
    if (this == NULL)
        return;
    if (s) {
        this->str = strdup(s);
    } else {
        this->str = NULL;
    }
    this->assign_c = &assign_c;
    this->assign_s = &assign_s;
    this->append_c = &append_c;
    this->append_s = &append_s;
    this->at = &at;
    this->clear = &clear;
    this->size = &size;
    this->compare_c = &compare_c;
    this->compare_s = &compare_s;
    this->copy = &copy;
    this->c_str = &c_str;
    this->empty = &empty;
    this->find_c = &find_c;
    this->find_s = &find_s;
}

void string_destroy(string_t *this)
{
    if (this == NULL)
        return;
    free(this->str);
    this->str = NULL;
}
