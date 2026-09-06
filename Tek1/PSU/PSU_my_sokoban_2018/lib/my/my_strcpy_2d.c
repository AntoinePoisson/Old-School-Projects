/*
** EPITECH PROJECT, 2018
** my_strcpy_2d
** File description:
** my_strcpy_2d
*/

void my_strcpy_2d(char **map, char **save_map, int nb_rows, int nb_cols)
{
    for (int i = 0; i <= nb_rows; i++)
        for (int i_two = 0; i_two <= nb_cols; i_two++)
            map[i][i_two] = save_map[i][i_two];
}