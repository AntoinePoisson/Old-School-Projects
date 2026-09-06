/*
** EPITECH PROJECT, 2019
** navy
** File description:
** file_descriptor.c
*/

#include "navy.h"

int game_help(void)
{
    mputstr("USAGE\n\t./navy [first_player_pid] navy_positions\n");
    mputstr("DESCRIPTION\n\tfirst_player_pid: only for the 2nd player.");
    mputstr(" pid of the first player.\n\tnavy_positions: file");
    mputstr(" representing the positions of the ships.\n");
    return (0);
}
