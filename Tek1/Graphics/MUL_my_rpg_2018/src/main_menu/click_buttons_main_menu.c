/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** Game of my_rpg
*/

#include "my_rpg.h"

static void click_buttons_menu2(game_t *game, sfVector2f hs_pos,
sfVector2f htp_pos)
{
    if (game->win.event.type == sfEvtMouseButtonReleased &&
        game->win.event.mouseButton.button == sfMouseLeft &&
        game->vector.mouse.x >= hs_pos.x &&
        game->vector.mouse.x <= hs_pos.x + 380 * game->win.ratio
        && game->vector.mouse.y >= hs_pos.y
        && game->vector.mouse.y <= hs_pos.y + 110 * game->win.ratio)
        high_score_loop(game);
    if (game->win.event.type == sfEvtMouseButtonReleased &&
        game->win.event.mouseButton.button == sfMouseLeft &&
        game->vector.mouse.x >= htp_pos.x &&
        game->vector.mouse.x <= htp_pos.x + 380 * game->win.ratio
        && game->vector.mouse.y >= htp_pos.y
        && game->vector.mouse.y <= htp_pos.y + 110 * game->win.ratio)
        htp_loop(game);
}

static void click_buttons_menu(game_t *game, sfVector2f play1_pos,
sfVector2f set_pos)
{
    if (game->win.event.type == sfEvtMouseButtonReleased &&
        game->win.event.mouseButton.button == sfMouseLeft &&
        game->vector.mouse.x >= play1_pos.x &&
        game->vector.mouse.x <= play1_pos.x + 380 * game->win.ratio
        && game->vector.mouse.y >= play1_pos.y
        && game->vector.mouse.y <= play1_pos.y + 110 * game->win.ratio)
        choose_chara_menu(game);
    if (game->win.event.type == sfEvtMouseButtonReleased &&
        game->win.event.mouseButton.button == sfMouseLeft &&
        game->vector.mouse.x >= set_pos.x &&
        game->vector.mouse.x <= set_pos.x + 380 * game->win.ratio
        && game->vector.mouse.y >= set_pos.y
        && game->vector.mouse.y <= set_pos.y + 110 * game->win.ratio)
        set_loop(game);
}

void click_buttons_main_menu(game_t *game)
{
    sfVector2f play1_pos = sfSprite_getPosition(game->sprite->play1_menu);
    sfVector2f set_pos = sfSprite_getPosition(game->sprite->set1_menu);
    sfVector2f htp_pos = sfSprite_getPosition(game->sprite->htp1_menu);
    sfVector2f hs_pos = sfSprite_getPosition(game->sprite->high_score1_menu);
    sfVector2f exit_pos = sfSprite_getPosition(game->sprite->exit1_menu);

    third_states_buttons_main_menu(game);
    click_buttons_menu(game, play1_pos, set_pos);
    click_buttons_menu2(game, hs_pos, htp_pos);
    if (game->win.event.type == sfEvtMouseButtonReleased &&
        game->win.event.mouseButton.button == sfMouseLeft &&
        game->vector.mouse.x >= exit_pos.x &&
        game->vector.mouse.x <= exit_pos.x + 380 * game->win.ratio
        && game->vector.mouse.y >= exit_pos.y
        && game->vector.mouse.y <= exit_pos.y + 110 * game->win.ratio)
        sfRenderWindow_close(game->win.dow);
}
