/*
** EPITECH PROJECT, 2019
** management_hitbox.c
** File description:
** management hitbox
*/

#include "my_rpg.h"

void check_actual_posi_player(game_t *game)
{
    sfVector2f posi = sfSprite_getPosition(game->sprite->player);
    sfColor color;

    posi.x = (float)((int)posi.x * 10 * (1 / game->win.ratio)) / 42;
    posi.y = (float)((int)(posi.y + 12) * 10 * (1 / game->win.ratio)) / 42;
    if ((posi.x < 0) || (posi.y < 0) ||
        (game->var.level == 1 && posi.x > 2400) ||
        (game->var.level == 1 && posi.y > 2600))
        return;
    color = sfImage_getPixel(game->texture->donjon_hitbox, posi.x, posi.y);
    if (color.r == 255 && color.b == 0 && color.g == 0 &&
        research_skill(game, 8) == 0)
        management_trap(game);
    if (color.r == 0 && color.b == 0 && color.g == 255)
        save_file(game);
}

int check_move_perso_d(game_t *game, sfVector2f posi)
{
    sfColor color;

    if ((posi.x < 0) || (posi.y < 0) ||
        (game->var.level == 1 && posi.x > 2400) ||
        (game->var.level == 1 && posi.y > 2600))
        return (1);
    color = sfImage_getPixel(game->texture->donjon_hitbox, posi.x, posi.y);
    if (color.r != 253 && color.b != 253 && color.g != 253)
        return (0);
    return (1);
}

int management_hitbox_donjon(game_t *game, sfVector2f posi)
{
    posi.x = (float)((int)posi.x * 10 * (1 / game->win.ratio)) / 42;
    posi.y = (float)((int)(posi.y + 12) * 10 * (1 / game->win.ratio)) / 42;

    if (posi.x < 0 || posi.y < 0 || game->var.level < 1)
        return (0);
    if (check_move_perso_d(game, (sfVector2f){posi.x + 6, posi.y + 12}) == 1)
        return (0);
    if (check_move_perso_d(game, (sfVector2f){posi.x, posi.y + 12}) == 1)
        return (0);
    if (check_move_perso_d(game, (sfVector2f){posi.x - 6, posi.y + 12}) == 1)
        return (0);
    if (check_move_perso_d(game, (sfVector2f){posi.x - 6, posi.y + 6}) == 1)
        return (0);
    if (check_move_perso_d(game, (sfVector2f){posi.x + 6, posi.y + 6}) == 1)
        return (0);
    if (check_move_perso_d(game, (sfVector2f){posi.x, posi.y + 6}) == 1)
        return (0);
    game->var.move = 1;
    return (1);
}
