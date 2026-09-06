/*
** EPITECH PROJECT, 2019
** is_initialization.c
** File description:
** is_initialization
*/

#include "my_struct.h"
#include <stdlib.h>
#include <stddef.h>

variable_t *is_initialization(void)
{
    variable_t *var = malloc(sizeof(variable_t));

    if (var == NULL)
        return (NULL);
    var->flag_w = 0;
    var->flag_s = 4;
    var->flag_g = 0;
    var->arg_w = NULL;
    var->arg_g = NULL;
    var->list = NULL;
    return (var);
}
