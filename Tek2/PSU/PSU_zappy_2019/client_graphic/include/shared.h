/*
** EPITECH PROJECT, 2020
** PSU_zappy_2019
** File description:
** shared
*/

#ifndef SHARED_H_
#define SHARED_H_

# define DEFAULT_TEAM_NAME_LENGTH 512
# define MAX_PLAYER_SAME_POSITION 128
# define SIZE_ID_UUID 37
# define EGG_TEAM_NAME "__EGG_OF_TEAM_"

typedef enum look_direction_e {
    None,
    Up,
    Down,
    Left,
    Right,
} look_direction_t;

typedef struct cell_player_s
{
    char id[SIZE_ID_UUID];
    char player_team[DEFAULT_TEAM_NAME_LENGTH];
    look_direction_t look;
} cell_player_t;

typedef struct cell_s
{
    int x;
    int y;
    unsigned int food;
    unsigned int linemate;
    unsigned int deraumere;
    unsigned int sibur;
    unsigned int mendiane;
    unsigned int phiras;
    unsigned int thystame;
    cell_player_t players[MAX_PLAYER_SAME_POSITION];
} cell_t;

#endif