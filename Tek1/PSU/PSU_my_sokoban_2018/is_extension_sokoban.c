/*
** EPITECH PROJECT, 2018
** is_extension_sokoban
** File description:
** is_extension_sokoban
*/

int count_nbr_x(char **map, int nb_rows, int nb_cols);

int control_x_block_calcul(char **map, int x, int y)
{
    if (map[x - 1][y] != ' ' && map[x][y - 1] != ' ' && map[x - 1][y] != 'P' &&
        map[x][y - 1] != 'P' && map[x - 1][y] != 'O' && map[x][y - 1] != 'O')
        return (1);
    if (map[x - 1][y] != ' ' && map[x][y + 1] != ' ' && map[x - 1][y] != 'P' &&
        map[x][y + 1] != 'P' && map[x - 1][y] != 'O' && map[x][y + 1] != 'O')
        return (1);
    if (map[x][y + 1] != ' ' && map[x + 1][y] != ' ' && map[x][y + 1] != 'P' &&
        map[x + 1][y] != 'P' && map[x][y + 1] != 'O' && map[x + 1][y] != 'O')
        return (1);
    if (map[x][y - 1] != ' ' && map[x + 1][y] != ' ' && map[x][y - 1] != 'P' &&
        map[x + 1][y] != 'P' && map[x][y - 1] != 'O' && map[x + 1][y] != 'O')
        return (1);
    return (0);
}

int control_x_check_block(char **map, int nb_rows, int nb_cols)
{
    int nb_x_tot = count_nbr_x(map, nb_rows, nb_cols);
    int nb_x_block = 0;
    int i = 0;
    int i_two = 0;

    for (i = 0; i <= nb_rows; i++) {
        for (i_two = 0; i_two <= nb_cols; i_two++) {
            if (map[i][i_two] == 'X') {
                nb_x_block += control_x_block_calcul(map, i, i_two);
            }
        }
    }
    if (nb_x_block == nb_x_tot)
        return (5);
    return (1);
}

void control_o(char **map, int nb_rows, int nb_cols, char **save)
{
    for (int i = 0; i <= nb_rows; i++) {
        for (int i_two = 0; i_two <= nb_cols; i_two++) {
            if (save[i][i_two] == 'O') {
                if (map[i][i_two] != 'P' && map[i][i_two] != 'X') {
                    map[i][i_two] = 'O';
                }
            }
        }
    }
}

int research_perso(char **map, int *x, int *y, int nb_rows)
{
    for (int i = 0; i <= nb_rows; i++) {
        for (int i_two = 0; map[i][i_two] != '\0'; i_two++) {
            if (map[i][i_two] == 'P') {
                *x = i;
                *y = i_two;
                return (1);
            }
        }
    }
    return (0);
}
