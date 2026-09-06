/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my_lib.h"

int check_error(int ac, char *av[]);
char **init_tab(int ac, char *av[]);
int sort_alpha(char *tab[], int);
char **my_str_to_word_array(char *, int *);

int main(int ac, char *av[])
{
    int return_value = check_error(ac, av);
    char **tab;
    int size = 0;

    if (return_value == 1)
        return (0);
    tab = my_str_to_word_array(av[1], &size);
    if (sort_alpha(tab, size) == 84)
        return (84);
    my_putstr("\n");
    return (0);
}
