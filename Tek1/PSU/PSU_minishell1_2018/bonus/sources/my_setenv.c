/*
** EPITECH PROJECT, 2019
** my_setenv.c
** File description:
** my_setenv
*/

#include <unistd.h>
#include "my_lib.h"
#include "my_struct.h"

int push(var_t *var, char const *str);
int display_env(var_t *var);

static int check_error_my_setenv(var_t *var)
{
    char *z = "setenv: Variable name must contain alphanumeric characters.\n";

    if (count_arg(var->arg_two_d) <= 1) {
        display_env(var);
        return (1);
    }
    if (count_arg(var->arg_two_d) >= 2) {
        if (var->arg_two_d[1][0] >= '0' && var->arg_two_d[1][0] <= '9') {
            write(2, "setenv: Variable name must begin with a letter.\n", 48);
            return (1);
        }
        for (int i = 0; var->arg_two_d[1][i] != '\0'; i++)
            if (!((var->arg_two_d[1][i] >= 'a' && var->arg_two_d[1][i] <= 'z')
                || (var->arg_two_d[1][i] >= 'A' && var->arg_two_d[1][i] <= 'Z')
                || (var->arg_two_d[1][i] >= '1' && var->arg_two_d[1][i] <= '9')
                || (var->arg_two_d[1][i] == '_'))) {
                write(2, z, my_strlen(z));
                return (1);
            }
    }
    return (0);
}

int my_setenv(var_t *var)
{
    if (count_arg(var->arg_two_d) > 3) {
        write(2, "setenv: Too many arguments.\n", 28);
        return (84);
    }
    if (check_error_my_setenv(var) == 1)
        return (84);
    return (push(var, var->arg_two_d[1]));
}
