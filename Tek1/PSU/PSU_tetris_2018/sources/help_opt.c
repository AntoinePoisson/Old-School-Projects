/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** help_opt.c
*/

#include "my_tetris.h"

int help_opt(char const *binary)
{
    mprintf("Usage:  %s [options]\nOptions:\n--help\t\t\t", binary);
    my_putstr("Display this help\n-L --level={num}\t");
    my_putstr("Start Tetris at level num (def: 1)\n-l --key-left={K}\t");
    my_putstr("Move the tetrimino LEFT using the K key (def: left arrow)\n");
    my_putstr("-r --key-right={K}\t");
    my_putstr("Move the tetrimino RIGHT using the K key (def: right arrow)\n");
    my_putstr("-t --key-turn={K}\tTURN");
    my_putstr(" the tetrimino clockwise 90d using the K key (def: top arrow)");
    my_putstr("\n-d --key-drop={K}\t");
    my_putstr("DROP the tetrimino using the K key (def: down arrow)\n");
    my_putstr("-q --key-quit={K}\t");
    my_putstr("QUIT the game using the K key (def: 'q' key)\n");
    my_putstr("-p --key-pause={K}\t");
    my_putstr("PAUSE/RESTART the game using the K key (def: space bar)\n");
    my_putstr("--map-size={row,col}\t");
    my_putstr("Set the numbers of rows and columns of the map (def: 20,10)\n");
    my_putstr("-w --without-next\tHide next tetrimino (def: false)\n");
    my_putstr("-D --debug\t\tDebug mode (def: false)\n");
    return (EXIT_SUCCESS);
}
