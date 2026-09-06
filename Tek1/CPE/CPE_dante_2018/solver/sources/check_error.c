/*
** EPITECH PROJECT, 2019
** check_error.c
** File description:
** check_error
*/

#include <sys/stat.h>
#include <stddef.h>
#include "my_struct.h"

int my_str_isnum(char const *str)
{
    if (str == NULL || str[0] == '\0')
        return (1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' && str[i] > '9')
            return (0);
    }
    return (1);
}

int check_error(int ac, char *av[], variable_t *var)
{
    struct stat info;

    if (ac != 2)
        return (84);
    if (stat(av[1], &info) == -1)
        return (84);
    if ((info.st_mode & S_IFMT) != S_IFREG)
        return (84);
    if (var == NULL)
        return (84);
    var->size_file = info.st_size;
    return (0);
}

int move_on_direction_(variable_t *var, int *x, int *y, int cas)
{
    if (cas == 3) {
        var->map[*y][*x] = 'o';
        var->map[*y][*x - 1] = 'o';
        *x -= 1;
        return (1);
    }
    return (0);
}