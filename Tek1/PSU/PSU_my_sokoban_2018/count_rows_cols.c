/*
** EPITECH PROJECT, 2018
** count_rows_cols
** File description:
** counter of number lines and cols
*/

#include <stdlib.h>
int my_putstr(char const *str);

int count_rows(char *map)
{
    int count_rows = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n')
            count_rows++;
    }
    return (count_rows);
}

void is_exten_count_cols_check(int *cols_max, int *count_cols)
{
    if (*cols_max != 0) {
        if (*cols_max != *count_cols) {
            my_putstr("Invalide file\n");
            exit(84);
        }
    }
    else
        *cols_max = *count_cols;
    *count_cols = 0;
}

int count_cols_check(char *map)
{
    int count_cols = 0;
    int cols_max = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n') {
            if (count_cols > cols_max)
                cols_max = count_cols;
            count_cols = 0;
        }
        else
            count_cols++;
    }
    return (cols_max);
}

int count_nbr_x(char **map, int nb_rows, int nb_cols)
{
    int nb_x = 0;

    for (int i = 0; i <= nb_rows; i++)
        for (int i_two = 0; i_two <= nb_cols; i_two++)
            if (map[i][i_two] == 'X')
                nb_x++;
    return (nb_x);
}
/*
int count_cols(char *map)
{
    return (count_cols_check(map));
}
*/
   /* for (int i = 0; map[i] != '\0'; i++) {
    if (map[i] == '\n') {
    if (count_cols > cols_max)
    cols_max = count_cols;
    count_cols = 0;
    }
    else
    count_cols++;
    }*/
