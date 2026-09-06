/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** manage_inputs.c
*/

#include "my_tetris.h"

int game_pause(time_t *stack)
{
    char buf[2] = {'\0'};
    time_t t = time(NULL);

    do {
        read(0, buf, 2);
    } while (buf[0] ^ ' ');
    *stack += (time(NULL) - t);
    return (1);
}

int check_usr_input(options_t opt, time_t *stack)
{
    int res = 0;
    char buf[2];

    res = read(0, buf, 2);
    if (res <= 0)
        return (1);
    buf[res] = '\0';
    if (!str_comp(buf, opt.keys.quit))
        return (0);
    if (!str_comp(buf, opt.keys.pause))
        return (game_pause(stack));
    return (1);
}
