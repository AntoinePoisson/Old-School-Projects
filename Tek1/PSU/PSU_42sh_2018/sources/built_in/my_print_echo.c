/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** ext of echo
*/

#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include "my_shell.h"

int check_single_cote(variable_t *var)
{
    bool count = false;

    for (int a = 1; var->arg_two_d[a] != NULL; a++) {
        for (int b = 0; var->arg_two_d[a][b] != '\0'; b++) {
        if (var->arg_two_d[a][b] == 39 && count == false
            && var->arg_two_d[a][b - 1] != '\\') {
            count = true;
        }
        else if (var->arg_two_d[a][b] == 39 && count == true
                && var->arg_two_d[a][b - 1] != '\\')
            count = false;
        }
    }
    if (count == true) {
        my_printf("Unmatched '''.");
        return (-1);
    }
    return (0);
}

void loop_print_single(variable_t *var, int a, int *b)
{
    if (var->arg_two_d[a][*b] == '\\' && var->arg_two_d[a][*b + 1] == 'n') {
        my_printf("\n");
        *b = *b + 1;
    }
    else
        my_printf("%c", var->arg_two_d[a][*b]);
}

void loop_print_double(variable_t *va, int a, int *b)
{
    if (va->arg_two_d[a][*b] == '\\' && va->arg_two_d[a][*b + 1] == 'n') {
        my_printf("\n");
        *b = *b + 1;
    }
    else if (va->arg_two_d[a][*b] == '\\' && va->arg_two_d[a][*b + 1] == 't') {
        my_printf("\t");
        *b = *b + 1;
    }
    else if (va->arg_two_d[a][*b] == '\\' && va->arg_two_d[a][*b + 1] == 'r') {
        my_printf("\r");
        *b = *b + 1;
    }
    else if (va->arg_two_d[a][*b] == '\\' && va->arg_two_d[a][*b + 1] == 'a') {
        my_printf("\a");
        *b = *b + 1;
    }
    else
        my_printf("%c", va->arg_two_d[a][*b]);
}
