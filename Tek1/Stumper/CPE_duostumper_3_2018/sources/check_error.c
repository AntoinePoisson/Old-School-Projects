/*
** EPITECH PROJECT, 2019
** check_error.c
** File description:
** check_error
*/

#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include "my_lib.h"

int check_if_digit(char d)
{
    if (d >= '0' && d <= '9')
        return (1);
    else
        return (0);
}

int check_error(int ac, char *av[])
{
    int fd = 0;

    if (ac != 3)
        return (my_puterror("Invalid number of arguments\n"));
    if (av[1] == NULL || av[2] == NULL)
        return (my_puterror("Invalid arguments (NULL value)\n"));
    if (av[2][0] != '-')
        if (check_if_digit(av[2][0]) == 0)
            return (my_puterror("The second argument is not a number\n"));
    for (int i = 1; av[2][i] != '\0'; i++)
        if (check_if_digit(av[2][i]) == 0)
            return (my_puterror("The second argument is not a number\n"));
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (my_puterror("An error occured when opening the file\n"));
    if (close(fd) == -1)
        return (my_puterror("An error occured when closing the file\n"));
    return (0);
}
