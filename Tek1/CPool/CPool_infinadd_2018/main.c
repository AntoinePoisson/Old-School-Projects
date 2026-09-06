/*
** EPITECH PROJECT, 2018
** infin_add
** File description:
** This program must take two strings and represents the result of the sum.
*/

#include "include/my.h"

int is_zero_zero(char *av[])
{
    int taille_1 = my_strlen(av[1]);
    int taille_2 = my_strlen(av[2]);

    if (taille_1 == 1 && taille_2 == 1)
        if (av[1][0] == '0' && av[2][0] == '0') {
            my_putchar('0');
            my_putchar('\n');
            return (1);
        }
    return (0);
}
int main(int ac, char *av[])
{
    int a = 1;
    int b = 2;

    if (checks_errors(av, ac) == 0)
        return (0);
    if (is_zero_zero(av) == 1)
	return (0);
    if (my_strlen(av[1]) < my_strlen(av[2])) {
        a = 2;
        b = 1;
    }
    infin_add(av, a, b);
    return (0);
}
