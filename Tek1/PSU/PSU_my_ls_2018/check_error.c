/*
** EPITECH PROJECT, 2018
** check_error
** File description:
** check_error
*/

#include <unistd.h>

int check_error_flag(char *arg)
{
    for (int i = 1; arg[i] != '\0'; i++)
        if (arg[i] != 'l' && arg[i] != 'R' && arg[i] != 'd' && arg[i] != 'r'
            && arg[i] != 't') {
            write(2, "Invalid Argument.\n", 18);
            return (84);
        }
    return (0);
}
