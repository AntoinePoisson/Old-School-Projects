/*
** EPITECH PROJECT, 2018
** is_control_sokoban
** File description:
** is_control_sokoban
*/

#include <curses.h>
int research_perso(char **map, int *x, int *y, int nb_rows);

void control_move_z(char **map, int x, int y)
{
    if (x > 0 && map[x - 1][y] != '#') {
        if ((x - 2) >= 1 && map[x - 1][y] == 'X')
            if (map[x - 2][y] != 'X' && map[x - 2][y] != '#') {
                map[x - 1][y] = 'P';
                map[x - 2][y] = 'X';
                map[x][y] = ' ';
            }
        if (x > 0 && map[x - 1][y] != 'X') {
            map[x - 1][y] = 'P';
            map[x][y] = ' ';
        }
    }
}

void control_move_q(char **map, int x, int y)
{
    if (y > 0 && map[x][y - 1] != '#') {
        if (y > 1 && map[x][y - 1] == 'X' && map[x][y - 2] != 'X' &&
            map[x][y - 2] != '#') {
            map[x][y - 1] = 'P';
            map[x][y - 2] = 'X';
            map[x][y] = ' ';
        }
        if (map[x][y - 1] != 'X') {
            map[x][y - 1] = 'P';
            map[x][y] = ' ';
        }
    }
}

void control_move_s(char **map, int x, int y, int nb_rows)
{
    if ((x + 1 < nb_rows) && map[x + 1][y] != '#') {
        if ((x + 2 < nb_rows) && map[x + 1][y] == 'X' && map[x + 2][y] != 'X' &&
            map[x + 2][y] != '#') {
            map[x + 1][y] = 'P';
            map[x + 2][y] = 'X';
            map[x][y] = ' ';
        }
        if (map[x + 1][y] != 'X') {
            map[x + 1][y] = 'P';
            map[x][y] = ' ';
        }
    }
}

void control_move_d(char **map, int x, int y)
{
    int nb_cols = 0;

    for (int i = 0; map[x][i] != '\0'; i++, nb_cols++);
    if ((y < (nb_cols - 1)) && map[x][y + 1] != '#') {
        if (y < (nb_cols - 2) && map[x][y + 1] == 'X' && map[x][y + 2] != 'X'
            && map[x][y + 2] != '#') {
            map[x][y + 1] = 'P';
            map[x][y + 2] = 'X';
            map[x][y] = ' ';
        }
        if (map[x][y + 1] != 'X') {
            map[x][y + 1] = 'P';
            map[x][y] = ' ';
        }
    }
}

int gestion_move(char **map, int nb_rows)
{
    int x = 0;
    int y = 0;
    int c = 0;

    research_perso(map, &x, &y, nb_rows);
    c = getch();
    if (c == KEY_UP)
        control_move_z(map, x, y);
    if (c == KEY_DOWN)
        control_move_s(map, x, y, nb_rows);
    if (c == KEY_LEFT)
        control_move_q(map, x, y);
    if (c == KEY_RIGHT)
        control_move_d(map, x, y);
    if (c == ' ')
        return (1);
    if (c == 'q')
        return (0);
    return (2);
}
