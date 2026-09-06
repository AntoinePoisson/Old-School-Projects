/*
** EPITECH PROJECT, 2019
** draw_buttons_main_menu
** File description:
** Draw buttons of the main menu
*/

#include "my_rpg.h"

void draw_play(game_t *game)
{
    sfVector2f play_pos = sfSprite_getPosition(game->sprite->play1_menu);

    if (game->vector.mouse.x >= play_pos.x &&
        game->vector.mouse.x <= play_pos.x + 380 * game->win.ratio &&
        game->vector.mouse.y >= play_pos.y &&
        game->vector.mouse.y <= play_pos.y + 110 * game->win.ratio)
        sfRenderWindow_drawSprite(game->win.dow,
            game->sprite->play2_menu, NULL);
    else
        sfRenderWindow_drawSprite(game->win.dow,
            game->sprite->play1_menu, NULL);
}

void draw_set(game_t *game)
{
    sfVector2f set_pos = sfSprite_getPosition(game->sprite->set1_menu);

    if (game->vector.mouse.x >= set_pos.x &&
        game->vector.mouse.x <= set_pos.x + 380 * game->win.ratio &&
        game->vector.mouse.y >= set_pos.y &&
        game->vector.mouse.y <= set_pos.y + 110 * game->win.ratio)
        sfRenderWindow_drawSprite(game->win.dow,
            game->sprite->set2_menu, NULL);
    else
        sfRenderWindow_drawSprite(game->win.dow,
            game->sprite->set1_menu, NULL);
}

void draw_htp(game_t *game)
{
    sfVector2f htp_pos = sfSprite_getPosition(game->sprite->htp1_menu);

    if (game->vector.mouse.x >= htp_pos.x &&
        game->vector.mouse.x <= htp_pos.x + 380 * game->win.ratio &&
        game->vector.mouse.y >= htp_pos.y &&
        game->vector.mouse.y <= htp_pos.y + 110 * game->win.ratio)
        sfRenderWindow_drawSprite(game->win.dow,
            game->sprite->htp2_menu, NULL);
    else
        sfRenderWindow_drawSprite(game->win.dow,
            game->sprite->htp1_menu, NULL);
}

void draw_exit(game_t *game)
{
    sfVector2f exit_pos = sfSprite_getPosition(game->sprite->exit1_menu);

    if (game->vector.mouse.x >= exit_pos.x &&
        game->vector.mouse.x <= exit_pos.x + 380 * game->win.ratio &&
        game->vector.mouse.y >= exit_pos.y &&
        game->vector.mouse.y <= exit_pos.y + 110 * game->win.ratio)
        sfRenderWindow_drawSprite(game->win.dow,
            game->sprite->exit2_menu, NULL);
    else
        sfRenderWindow_drawSprite(game->win.dow,
            game->sprite->exit1_menu, NULL);
}

void draw_high_score(game_t *game)
{
    sfVector2f score_pos = sfSprite_getPosition(game->sprite->high_score1_menu);

    if (game->vector.mouse.x >= score_pos.x &&
        game->vector.mouse.x <= score_pos.x + 380 * game->win.ratio &&
        game->vector.mouse.y >= score_pos.y &&
        game->vector.mouse.y <= score_pos.y + 110 * game->win.ratio)
        sfRenderWindow_drawSprite(game->win.dow,
            game->sprite->high_score2_menu, NULL);
    else
        sfRenderWindow_drawSprite(game->win.dow,
            game->sprite->high_score1_menu, NULL);
}
