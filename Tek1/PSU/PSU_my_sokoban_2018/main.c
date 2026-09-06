/*
** EPITECH PROJECT, 2018
** main
** File description:
** main of sokoban
*/

#include "main.h"

int main(int ac, char *av[])
{
    int nb_cols = check_error(ac, av);
    int nb_rows = 0;
    int continuer = 3;
    char **map = load_map(av[1], &nb_rows, &nb_cols);
    char **save_map = load_map(av[1], &nb_rows, &nb_cols);

    if (check_error_two(map, nb_rows, nb_cols) == 0) {
        my_putstr("Invalid Input\n");
        return (84);
    }
    while (continuer != 0) {
        if (continuer == 3)
            continuer = sokoban(map, nb_rows, nb_cols, save_map);
        else {
            my_strcpy_2d(map, save_map, nb_rows, nb_cols);
            continuer = sokoban(map, nb_rows, nb_cols, save_map);
        }
        if (continuer == 5)
            return (1);
    }
    return (0);
}
