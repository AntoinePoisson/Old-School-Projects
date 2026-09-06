/*
** EPITECH PROJECT, 2019
** echo
** File description:
** shellprog
*/

#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include "my_shell.h"

static int check_cote(variable_t *var)
{
    bool count = false;

    for (int a = 1; var->arg_two_d[a] != NULL; a++) {
        for (int b = 0; var->arg_two_d[a][b] != '\0'; b++) {
            if (var->arg_two_d[a][b] == '"' && count == false
                && var->arg_two_d[a][b - 1] != '\\') {
                count = true;
            }
            else if (var->arg_two_d[a][b] == '"' && count == true
                    && var->arg_two_d[a][b - 1] != '\\')
                count = false;
        }
    }
    if (count == true) {
        my_printf("Unmatched '\"'.");
        return (-1);
    }
    return (0);
}

static void echo_cote(variable_t *var, int a)
{
    bool count = false;

    for (int b = 0; var->arg_two_d[a][b] != '\0'; b++) {
        if (count == true && (var->arg_two_d[a][b] != '"'))
            loop_print_double(var, a, &b);
        if (count == false && ((var->arg_two_d[a][b] != '\\' &&
            var->arg_two_d[a][b] != '"')))
            loop_print_double(var, a, &b);
        if (var->arg_two_d[a][b] == '"' && var->arg_two_d[a][b - 1] == '\\')
            my_printf("\"");
        if (var->arg_two_d[a][b] == '"' && count == false
            && var->arg_two_d[a][b - 1] != '\\')
            count = true;
        else if (var->arg_two_d[a][b] == '"' && count == true
                && var->arg_two_d[a][b - 1] != '\\')
            count = false;
    }
}

static void double_signle_cote(variable_t *var, int a)
{
    if ((var->arg_two_d[a][0] == '"' || var->arg_two_d[a][0] == 39
        || var->arg_two_d[a][0] == '\\'))
        echo_cote(var, a);
    else
        for (int b = 0; var->arg_two_d[a][b] != '\0'; b++) {
            if (var->arg_two_d[a][b] == '\"')
                b++;
            if (var->arg_two_d[a][b] == '\\' && var->arg_two_d[a][b - 1] != ' ')
                b++;
            my_printf("%c", var->arg_two_d[a][b]);
        }
}

static void tab_check(variable_t *var, char *str)
{
    int a = 0;
    int b = 0;

    for (b = 0; var->arg_two_d[a] != NULL; a++) {
        if (my_strncmp(var->arg_two_d[a], "$?", 2) != 0 && a > 1) {
            double_signle_cote(var, a);
            b++;
        }
        if (my_strncmp(var->arg_two_d[a], "-n", 2) != 0 &&
            my_strncmp(var->arg_two_d[a], "$?", 2) != 0 && a == 1) {
            double_signle_cote(var, a);
            b++;
        }
        if (my_strcmp(var->arg_two_d[a], str) == 0) {
            my_printf("%d", var->value_return);
            b++;
        }
        if (var->arg_two_d[a + 1] != NULL && b > 0)
            my_printf(" ");
    }
}

int my_echo(variable_t *var)
{
    if (check_cote(var) == 0 && check_single_cote(var) == 0)
        tab_check(var, "$?");
    if (my_strcmp(var->arg_two_d[1], "-n") != 0)
        my_printf("\n");
    return (0);
}
