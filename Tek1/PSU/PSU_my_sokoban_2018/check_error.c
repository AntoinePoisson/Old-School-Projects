/*
** EPITECH PROJECT, 2018
** check_error
** File description:
** check error of sokoban
*/

#include <stdlib.h>
#include "my.h"

void option_h(void)
{
    my_putstr("USAGE\n     ./my_sokoban map\n     'q' in order to quit.\n"
              "     'ESPACE' in order to reset map.\nDESCRIPTION\n"
              "     map file representing the warehouse map, containing ‘#’"
              " for walls,\n          ‘P’ for the player, ‘X’ for boxes and "
              "‘O’ for storage locations.\n");
    exit(0);
}

int check_error(int ac, char *av[])
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h'
        && av[1][2] == '\0')
        option_h();
    if (ac != 2) {
        my_putstr("Invalid Input, please check -h\n");
        exit(84);
    }
    return (1);
}

int equal_o_x(char **map, int nb_rows, int nb_cols, int nb_o)
{
    int nb_x = 0;

    for (int i = 0; i <= nb_rows; i++)
        for (int i_two = 0; i_two <= nb_cols; i_two++)
            if (map[i][i_two] == 'X')
                nb_x++;
    if (nb_x != nb_o)
        return (0);
    return (1);
}

int check_error_two(char **map, int nb_rows, int nb_cols)
{
    int nb_p = 0;
    int nb_o = 0;

    for (int i = 0; i <= nb_rows; i++)
        for (int i_two = 0; i_two <= nb_cols; i_two++) {
            if (map[i][i_two] == 'O')
                nb_o++;
            if (map[i][i_two] == 'P')
                nb_p++;
        }
    if (nb_p != 1)
        return (0);
    if (nb_o == 0)
        return (0);
    if (equal_o_x(map, nb_rows, nb_cols, nb_o) == 0)
        return (0);
    return (1);
}
