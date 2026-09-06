/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** modify_term.c
*/

#include "my_tetris.h"

int wait_input(void)
{
    char c = '\0';
    struct termios old;
    struct termios new;

    if (ioctl(0, TCGETS, &new) == -1)
        return (EXIT_ERROR);
    old = new;
    new.c_lflag &= ~ECHO;
    new.c_lflag &= ~ICANON;
    if (ioctl(0, TCSETS, &new) == -1)
        return (EXIT_ERROR);
    if (read(0, &c, 1) == -1)
        return (EXIT_ERROR);
    if (ioctl(0, TCSETS, &old) == -1)
        return (EXIT_ERROR);
    return (EXIT_SUCCESS);
}

int set_newterm(void)
{
    struct termios new;

    if (ioctl(0, TCGETS, &new) < 0)
        return (EXIT_FAILURE);
    new.c_cc[VMIN] = 0;
    new.c_cc[VTIME] = 1;
    if (ioctl(0, TCSETS, &new) < 0)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}
