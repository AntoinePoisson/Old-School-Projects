/*
** EPITECH PROJECT, 2020
** mem_ptr.c
** File description:
** daytwo
*/

#include <stdlib.h>
#include <string.h>
#include "mem_ptr.h"

void add_str(const char *str1, const char *str2, char **res)
{
    char *result = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 2));
    int index = 0;

    if (!result)
        return;
    for (int i = 0; i != (strlen(str1) + strlen(str2) + 1);
    result[i] = '\0', i++) {
    }
    for (int i = 0; str1 && str1[i]; i++, index++) {
        result[index] = str1[i];
    }
    for (int i = 0; str2 && str2[i]; i++, index++) {
        result[index] = str2[i];
    }
    *res = result;
}

void add_str_struct(str_op_t *str_op)
{
    char *result = malloc(sizeof(char) * (strlen(str_op->str1) +
        strlen(str_op->str2) + 2));
    int index = 0;

    if (!result)
        return;
    for (int i = 0; i != (strlen(str_op->str1) + strlen(str_op->str2) + 1);
        result[i] = '\0', i++) {
    }
    for (int i = 0; str_op->str1 && str_op->str1[i]; i++, index++) {
        result[index] = str_op->str1[i];
    }
    for (int i = 0; str_op->str2 && str_op->str2[i]; i++, index++) {
        result[index] = str_op->str2[i];
    }
    str_op->res = result;
}
