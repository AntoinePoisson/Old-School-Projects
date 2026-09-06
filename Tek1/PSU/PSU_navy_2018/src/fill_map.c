/*
** EPITECH PROJECT, 2019
** navy
** File description:
** fill_map.c
*/

#include "navy.h"

static int malloc_map(char ***map_usr)
{
    *map_usr = malloc(sizeof(char *) * 10 + 8);
    if (*map_usr == NULL)
        return (-1);
    (*map_usr)[10] = NULL;
    for (int a = 0; a != 10; a++) {
        (*map_usr)[a] = malloc(18);
        if ((*map_usr)[a] == NULL)
            return (-1);
    }
    for (int a = 0; a != 10; a++)
        (*map_usr)[a][17] = 0;
    return (0);
}

static void fill_empty_map(char ***map_usr)
{
    char c = 'A';

    (*map_usr)[0][0] = 32;
    (*map_usr)[0][1] = '|';
    for (int a = 2; a != 17; a++) {
        (*map_usr)[0][a] = ((a % 2) == 0) ? c : 32;
        c += ((a % 2) == 0) ? 1 : 0;
    }
    for (int a = 0; a != 17; a++)
        (*map_usr)[1][a] = (a != 1) ? '-' : '+';
    for (int a = 2; a != 10; a++) {
        (*map_usr)[a][0] = a + 47;
        (*map_usr)[a][1] = '|';
        for (int b = 2; b != 17; b++) {
            if ((b % 2) == 0)
                (*map_usr)[a][b] = '.';
            else
                (*map_usr)[a][b] = ' ';
        }
    }
}

static void fill_with_ship(char ***my_map, char *buff, int value, int size)
{
    int a;
    int b;

    for (a = 2; (*my_map)[0][a] != buff[value]; a++);
    for (b = 2; (*my_map)[b][0] != buff[value + 1]; b++);
    if (buff[value] != buff[value + 3]) {
        for (int c = 0; c != size; c++)
            (*my_map)[b][c + c + a] = size + 48;
    } else
        for (int c = 0; c != size; c++)
            (*my_map)[c + b][a] = size + 48;
}

static int place_ships(char ***my_map, char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buff = NULL;

    if (fd == -1)
        return (-1);
    buff = create_buffer(buff, fd);
    if (buff == NULL)
        return (-1);
    fill_with_ship(my_map, buff, 2, buff[0] - 48);
    fill_with_ship(my_map, buff, 10, buff[8] - 48);
    fill_with_ship(my_map, buff, 18, buff[16] - 48);
    fill_with_ship(my_map, buff, 26, buff[24] - 48);
    free(buff);
    close(fd);
    return (0);
}

int fill_map(char ***my_map, char ***enemy_map, char **av)
{
    if (malloc_map(my_map) == -1 || malloc_map(enemy_map) == -1)
        return (-1);
    fill_empty_map(my_map);
    fill_empty_map(enemy_map);
    if (av[2] == NULL) {
        if (place_ships(my_map, av[1]) == -1)
            return (-1);
    } else
        if (place_ships(my_map, av[2]) == -1)
            return (-1);
    return (0);
}
