/*
** EPITECH PROJECT, 2019
** check_error.c
** File description:
** check_error
*/

#include "my_lib.h"

int verify_position_of_line_breaker(char const *str1, char const *str2)
{
    int line_breaker = 0;

    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        line_breaker = 0;
        if (str1[i] == '@')
            line_breaker = 1;
        if (line_breaker == 1 && str2[i] != '@')
            return (84);
    }
    return (1);
}

int is_extension_check_error(int ac, char *av[])
{
    for (int i = 0; av[1] && av[1][i]; i++)
        if (!(av[1][i] >= '0' && av[1][i] <= '9'))
            return (84);
    for (int i = 2; i < ac; i++)
        for (int i_two = 0; av[i] && av[i][i_two]; i_two++)
            if (av[i][i_two] != '@' && av[i][i_two] != '.'
                && av[i][i_two] != '#')
                return (84);
    return (0);
}

int check_error(int ac, char *av[])
{
    if (ac != 4)
        return (my_puterror("Invalide nbr charac\n"));
    if (!av[1] || !av[2] || !av[3])
        return (my_puterror("Invalide input 1\n"));
    if (is_extension_check_error(ac, av) != 0)
        return (my_puterror("Invalide input 2\n"));
    if (my_strlen(av[2]) != my_strlen(av[3]))
        return (my_puterror("Invalide input 3\n"));
    if (verify_position_of_line_breaker(av[2], av[3]) == 84)
        return (my_puterror("Invalide postion of line breaker\n"));
    return (0);
}
