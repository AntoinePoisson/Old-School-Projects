/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "unistd.h"

int check_error(int ac, char *av[]);
int palindrome(char *);

int main(int ac, char *av[])
{
    int i = check_error(ac, av);

    if (i == 84) {
        write(2, "Error: missing arguments.\n", 26);
        return (84);
    }
    if (palindrome(av[1]) == 1)
        write(1, "palindrome!\n", 12);
    else
        write(1, "not a palindrome.\n", 18);
    return (0);
}
