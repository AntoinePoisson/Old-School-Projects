/*
** EPITECH PROJECT, 2019
** orientation_player.c
** File description:
** orientation_player in terms of mouse
*/

#include <math.h>
#include "my_rpg.h"

float difference_angle(sfVector2f obj, sfVector2f obj_two)
{
    float result = ((atan2f((obj_two.y - obj.y), (obj_two.x - obj.x)))
        * (180.0 / PI));
    if (result < 0)
        result = 360 - (result * -1);
    result -= 360;
    result *= -1;
    return (result);
}

int create_orientation_player(game_t *game)
{
    game->player.rect = malloc(sizeof(sfIntRect *) * 6);

    if (game->player.rect == NULL)
        return (84);
    for (int i = 0; i < 5; i++) {
        if ((game->player.rect[i] = malloc(sizeof(sfIntRect) * 11)) == NULL)
            return (84);
        game->player.rect[i + 1] = NULL;
    }
    game->player.status = 1;
    game->player.hp = game->var.player_hp;
    game->player.mana = game->var.player_mana;
    game->player.rect_x = 0;
    game->player.rect_y = 1;
    game->player.animation = game->var.player_speed;
    game->player.clock = sfClock_create();
    fill_tab_orientation_player_two(game);
    fill_tab_orientation_player(game);
    return (0);
}

int orientation_player(game_t *game, sfVector2f player)
{
    sfVector2f mouse = {sfSprite_getPosition(game->sprite->cursor).x
        * game->win.ratio,
        sfSprite_getPosition(game->sprite->cursor).y * game->win.ratio};
    float angle = difference_angle(player, mouse);

    if ((angle >= 0 && angle < 30) || (angle <= 360 && angle > 330))
        return (0);
    if (angle >= 30 && angle < 60)
        return (1);
    if (angle >= 60 && angle < 120)
        return (2);
    if (angle >= 120 && angle < 150)
        return (3);
    if (angle >= 150 && angle < 210)
        return (4);
    if (angle >= 210 && angle < 240)
        return (5);
    if (angle >= 240 && angle < 300)
        return (6);
    return (7);
}

int action_player(game_t *game)
{
    if (game->player.animation < game->var.player_speed) {
        game->player.animation += 1;
        return (game->player.rect_x);
    }
    game->player.animation = 0;
    if (game->player.rect_x < 2)
        game->player.rect_x += 1;
    else
        game->player.rect_x = 0;
    return (game->player.rect_x);
}

void management_orientation_player(game_t *game)
{
    sfIntRect rect;
    sfVector2f player = {(sfSprite_getPosition(game->sprite->player).x -
        game->view.offset.x) * game->win.ratio,
        (sfSprite_getPosition(game->sprite->player).y
        - game->view.offset.y) * game->win.ratio};

    game->player.time = sfClock_getElapsedTime(game->player.clock);
    if ((game->player.time.microseconds / 1000000.0) < 0.014)
        return;
    game->player.rect_y = orientation_player(game, player);
    if (game->var.move == 1) {
        game->player.rect_x = action_player(game);
        game->var.move = 0;
    }
    if (game->player.attack > 0)
        attack_player(game);
    rect = game->player.rect[game->player.rect_x][game->player.rect_y];
    sfClock_restart(game->player.clock);
    sfSprite_setTextureRect(game->sprite->player, rect);
}
