/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** orientation player
*/

#include "my_rpg.h"

void fill_tab_orientation_player_two(game_t *game)
{
    game->player.rect[0][4] = (sfIntRect){92, 1, 16, 19};
    game->player.rect[1][4] = (sfIntRect){94, 24, 14, 20};
    game->player.rect[2][4] = (sfIntRect){92, 49, 16, 20};
    game->player.rect[3][4] = (sfIntRect){91, 72, 18, 20};
    game->player.rect[4][4] = (sfIntRect){92, 97, 16, 20};
    game->player.rect[0][5] = (sfIntRect){115, 1, 17, 20};
    game->player.rect[1][5] = (sfIntRect){115, 24, 17, 20};
    game->player.rect[2][5] = (sfIntRect){116, 49, 16, 20};
    game->player.rect[3][5] = (sfIntRect){117, 73, 16, 21};
    game->player.rect[4][5] = (sfIntRect){117, 97, 16, 19};
    game->player.rect[0][6] = (sfIntRect){139, 1, 17, 19};
    game->player.rect[1][6] = (sfIntRect){141, 24, 15, 20};
    game->player.rect[2][6] = (sfIntRect){141, 49, 15, 20};
    game->player.rect[3][6] = (sfIntRect){141, 73, 16, 22};
    game->player.rect[4][6] = (sfIntRect){143, 97, 17, 19};
    game->player.rect[0][7] = (sfIntRect){168, 1, 14, 19};
    game->player.rect[1][7] = (sfIntRect){168, 24, 14, 20};
    game->player.rect[2][7] = (sfIntRect){168, 49, 14, 20};
    game->player.rect[3][7] = (sfIntRect){168, 73, 17, 20};
    game->player.rect[4][7] = (sfIntRect){168, 97, 19, 19};
}

void fill_tab_orientation_player(game_t *game)
{
    game->player.rect[0][0] = (sfIntRect){1, 1, 16, 19};
    game->player.rect[1][0] = (sfIntRect){1, 24, 14, 20};
    game->player.rect[2][0] = (sfIntRect){1, 49, 17, 20};
    game->player.rect[3][0] = (sfIntRect){0, 73, 19, 19};
    game->player.rect[4][0] = (sfIntRect){1, 97, 15, 19};
    game->player.rect[0][1] = (sfIntRect){25, 1, 15, 19};
    game->player.rect[1][1] = (sfIntRect){25, 24, 15, 20};
    game->player.rect[2][1] = (sfIntRect){26, 49, 15, 20};
    game->player.rect[3][1] = (sfIntRect){25, 73, 15, 19};
    game->player.rect[4][1] = (sfIntRect){25, 97, 15, 19};
    game->player.rect[0][2] = (sfIntRect){49, 1, 12, 19};
    game->player.rect[1][2] = (sfIntRect){49, 24, 11, 21};
    game->player.rect[2][2] = (sfIntRect){49, 49, 13, 19};
    game->player.rect[3][2] = (sfIntRect){49, 73, 15, 19};
    game->player.rect[4][2] = (sfIntRect){49, 97, 12, 19};
    game->player.rect[0][3] = (sfIntRect){72, 1, 13, 19};
    game->player.rect[1][3] = (sfIntRect){72, 24, 13, 20};
    game->player.rect[2][3] = (sfIntRect){71, 49, 14, 20};
    game->player.rect[3][3] = (sfIntRect){68, 73, 20, 19};
    game->player.rect[4][3] = (sfIntRect){70, 97, 15, 19};
}
