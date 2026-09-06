/*
** EPITECH PROJECT, 2019
** init_tab
** File description:
** init_tab
*/

#include <stdlib.h>
#include "my_lib.h"

char **init_tab(int ac, char *av[])
{
    char **tab = malloc(sizeof(char *) * ac - 1);
    int size = 0;
    int i_three = 0;

    for (int i = 1; i < ac; i++, i_three++) {
        size = my_strlen(av[i]);
        *tab = malloc(sizeof(char) * (size + 2));
        for (int i_two = 0; i_two <= size; i++)
            tab[i_three][i_two] = av[i][i_two];
    }
    return (tab);
}
