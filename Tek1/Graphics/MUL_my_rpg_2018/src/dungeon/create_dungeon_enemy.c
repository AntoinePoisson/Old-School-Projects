/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** create_dungeon_enemy.c
*/

#include "my_rpg.h"

int check_actual_posi_enemy(game_t *game, sfVector2f posi)
{
    sfColor color;

    if ((posi.x < 0) || (posi.y < 0) ||
        (game->var.level == 1 && posi.x > 2400) ||
        (game->var.level == 1 && posi.y > 2600))
        return (0);
    color = sfImage_getPixel(game->texture->donjon_hitbox, posi.x, posi.y);
    if (color.r == 255 && color.b == 0 && color.g == 0)
        return (0);
    if (color.r == 0 && color.b == 0 && color.g == 255)
        return (0);
    if (color.r == 253 && color.b == 253 && color.g == 253)
        return (0);
    return (1);
}

void choose_enemy(game_t *game, sfVector2f posi, int cas)
{
    switch (cas) {
        case 1 : return (add_enemy_eye(game, posi));
        case 2 : return (add_enemy_eye_bomb(game, posi));
        case 3 : return (add_enemy_evil_tick(game, posi));
        case 4 : return (add_enemy_spider(game, posi));
        default : return (add_enemy_spider(game, posi));
    }
}

void create_dungeon_enemy(game_t *game)
{
    sfVector2f posi = {0, 0};

    game->enemy_eye = NULL;
    game->enemy_eye_bomb = NULL;
    game->enemy_spider = NULL;
    game->enemy_evil_tick = NULL;
    for (unsigned int i = 500; i;) {
        posi.x = rand() % 2458;
        posi.y = rand() % 2296;
        if (check_actual_posi_enemy(game, posi)) {
            choose_enemy(game, (sfVector2f){posi.x * 4.2, posi.y * 4.2}
                , rand() % 5);
            i--;
        }
    }
}
