/*
** EPITECH PROJECT, 2019
** analyze_tetriminos.c
** File description:
** analyzation of tetriminos directory
*/

#include "my_tetris.h"

char *change_name_of_file(char *name)
{
    int size = my_strlen(name);

    if (size <= 10 || name == NULL)
        return (name);
    name[size - 10] = '\0';
    return (name);
}

int display_file_data(tetrimino_t *tetris)
{
    for (int i = 0; tetris->tetrimino && tetris->tetrimino[i]; i++) {
        write(1, tetris->tetrimino[i], my_strlen(tetris->tetrimino[i]));
        write(1, "\n", 1);
    }
    return (0);
}

int display_name_file(tetrimino_t *tetris)
{
    if (tetris == NULL)
        return (1);
    for (int i = 0; tetris->name && tetris->name[i]; i++)
        write(1, &tetris->name[i], 1);
    if (tetris->col == -1 || tetris->color == -1 ||
        tetris->row == -1 || tetris->tetrimino == NULL)
        return (1);
    return (0);
}

int display_debug_mode_file_part(options_t *opt)
{
    int check_error = 0;
    tetrimino_t *tetris = opt->map;

    for (int i = 0; tetris; i++, check_error = 0, tetris = tetris->next) {
        my_putstr("Tetriminos :  Name ");
        check_error = display_name_file(tetris);
        if (check_error == 0) {
            my_putstr(" :  Size ");
            my_putnbr(tetris->col);
            my_putchar('*');
            my_putnbr(tetris->row);
            my_putstr(" :  Color ");
            my_putnbr(tetris->color);
            my_putstr(" :\n");
            display_file_data(tetris);
        } else
            my_putstr(" :  Error\n");
    }
    return (0);
}