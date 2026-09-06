/*
** EPITECH PROJECT, 2019
** is_fractal_management
** File description:
** management fractale
*/

#include <stdlib.h>
#include <stddef.h>
#include "my_lib.h"

int display(char **parce);
char **find_str(char **, int, char **);

char **new_tab(int iteration, char *str, int *size_)
{
    int i = 0;
    int size = 0;
    char **new_tab = NULL;

    for (; str[size] != '@'; size++);
    size = my_compute_power_rec(size, iteration);
    new_tab = malloc(sizeof(char *) * (size + 1));
    for (; i < size + 1; i++)
        new_tab[i] = malloc(sizeof(char) * (size + 1));
    new_tab[i] = NULL;
    size = *size_;
    return (new_tab);
}

char **fill_map(char **str, int size, char **last_str, int last_size)
{
    int i_two = 0;
    int i_three = 0;
    int count = 0;
    int nbr_repetition =  my_strlen(last_str[0]);

    for (int i = 0; i < size * nbr_repetition; i++, count++, i_three = 0) {
        for (i_two = 0; i_two != size * nbr_repetition;
            i_two++, i_three++) {
            if (i_three == nbr_repetition)
                i_three = 0;
            if (count == nbr_repetition)
                count = 0;
            str[i][i_two] = last_str[count][i_three];
        }
        str[i][i_two] = '\0';
    }
    return (str);
}

static char **rework_parcing(char **av, int *size)
{
    for (int i = 0; av[i]; i++) {
        for (int i_two = 0; av[i][i_two];i_two++)
            if (av[i][i_two] == '/')
                av[i][i_two] = '\0';
        *size = i + 1;
    }
    return (av);
}

char **fill_point(char **parce, int x, int y, int size)
{
    static int posi = 0;
    int i_two = 0;

    if (y == -1) {
        posi = size;
        return (parce);
    }
    for (int i = 0; i != y * size; i++) {
        for (i_two = x; i_two != x * size; i_two++)
            parce[i][i_two] = '.';
    }
    return (parce);
}

int is_fractal_management(char *av[])
{
    int nbr_iteration = my_getnbr(av[1]);
    int size = 0;
    int last_size = 0;
    char **last_str = NULL;
    char **parce = my_str_to_selec_array(av[2], '@');

    parce = rework_parcing(parce, &size);
    fill_point(parce, 0, -1, nbr_iteration);
    for (int i = 1; i < nbr_iteration; i++) {
        last_size = size;
        last_str = parce;
        parce = new_tab(nbr_iteration, av[2], &size);
        parce = fill_map(parce, size, last_str, last_size);
        parce = find_str(parce, size, av);
    }
    display(parce);
    return (0);
}
