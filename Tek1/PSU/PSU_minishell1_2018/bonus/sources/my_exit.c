/*
** EPITECH PROJECT, 2019
** my_exit.c
** File description:
** my_exit
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_struct.h"
#include "my_lib.h"

void destroy_arg_two_d(var_t *var);
int destroy_env(var_t *var);

static int destroy_path(var_t *var)
{
    if (var->path != NULL) {
        for (int i = 0; var->path[i] != NULL; i++)
            free(var->path[i]);
        free(var->path);
    }
    return (0);
}

static void is_extension_my_exit(var_t *var)
{
    if (var->pwd != NULL)
        free(var->pwd);
    destroy_env(var);
    if (var->arg_two_d != NULL) {
        for (int i = 0; var->arg_two_d[i] != NULL; i++)
            free(var->arg_two_d[i]);
        free(var->arg_two_d);
    }
    if (var->alias != NULL) {
        for (int i = 0; var->alias[i] != NULL; i++)
            free(var->alias[i]);
        free(var->alias);
    }
    if (var->prev_pwd != NULL)
        free(var->prev_pwd);
    if (var->arg != NULL)
        free(var->arg);
    destroy_path(var);
    free(var);
}

static int check_error_my_exit(var_t *var, char *nbr)
{
    if (nbr != NULL)
        for (int i = 0; nbr[i] != '\0'; i++)
            if (nbr[i] < '0' && nbr[i] > '9' && nbr[i] != '-') {
                write(2, "exit: Expression Syntax.\n", 25);
                return (84);
            }
    if (var->arg_two_d != NULL)
        destroy_arg_two_d(var);
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (count_arg(var->arg_two_d) > 2) {
        write(2, "exit: Too many arguments.\n", 26);
        return (84);
    }
    return (0);
}

int my_exit(var_t *var, char *arg_nbr)
{
    int nbr = my_getnbr(arg_nbr);

    if (check_error_my_exit(var, arg_nbr) == 84)
        return (84);
    is_extension_my_exit(var);
    my_putstr("exit\n");
    exit(nbr);
    return (0);
}
