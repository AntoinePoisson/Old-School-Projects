/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <stdlib.h>
#include "my_struct.h"

int check_flag(flag_t *flag, int ac, char *av[]);
int is_my_ls(flag_t *flag);

int main(int ac, char *av[])
{
    flag_t *flag = malloc(sizeof(*flag));
    int value_return = 84;

    if (check_flag(flag, ac, av) == 84);
    else
        value_return = is_my_ls(flag);
    free(flag);
    return (value_return);
}
