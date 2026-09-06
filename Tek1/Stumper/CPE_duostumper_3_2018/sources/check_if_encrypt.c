/*
** EPITECH PROJECT, 2019
** Duo_Stumpe_3
** File description:
** check if the encrypt mode
*/

#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include "my_lib.h"

int check_if_digit(char);

int error_handling_encrypt_str(char *av[])
{
    if (av[2] == NULL)
        return (my_puterror("Invalid second argument.\n"));
    if (av[3][0] != '-')
        if (check_if_digit(av[3][0]) == 0)
            return (my_puterror("The third argument is not a number.\n"));
    for (int i = 1; av[3][i] != '\0'; i++)
        if (check_if_digit(av[3][i]) == 0)
            return (my_puterror("the third argument is not a number.\n"));
    return (0);
}

int error_handling_encrypt_file(char *av[])
{
    int fd = 0;

    if (av[2] == NULL || av[3] == NULL)
        return (my_puterror("Invalid second argument.\n"));
    if ((fd = open(av[2], O_RDONLY)) == -1)
        return (my_puterror("An error occured when opening the file.\n"));
    if (close(fd) == -1)
        return (my_puterror("An error occured when closing the file.\n"));
    if (av[3][0] != '-')
        if (check_if_digit(av[3][0]) == 0)
            return (my_puterror("The third argument is not a number.\n"));
    for (int i = 1; av[3][i] != '\0'; i++)
        if (check_if_digit(av[3][i]) == 0)
            return (my_puterror("The third argument is not a number.\n"));
    return (0);
}

int check_if_encrypt(int ac, char *av[])
{
    if (ac != 4)
        return (my_puterror("Invalid number of arguments.\n"));
    if (av[1] == NULL)
        return (84);
    if (my_strcmp(av[1], "-f") == 0) {
        if (error_handling_encrypt_file(av) == 84)
            return (84);
        else
            return (1);
    }
    if (my_strcmp(av[1], "-s") == 0) {
        if (error_handling_encrypt_str(av) == 84)
            return (84);
        else
            return (2);
    }
    return (0);
}
