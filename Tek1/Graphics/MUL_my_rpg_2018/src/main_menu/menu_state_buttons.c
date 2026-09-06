/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** menu third state button
*/

#include "my_rpg.h"

void menu_play_button(game_t *game, sfVector2f *play1_pos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)
    && game->vector.mouse.x >= play1_pos->x
    && game->vector.mouse.x <= play1_pos->x + 380 * game->win.ratio
    && game->vector.mouse.y >= play1_pos->y &&
    game->vector.mouse.y <= play1_pos->y + 110 * game->win.ratio
    && !game->press.click) {
        game->press.click = true;
        sfSprite_setScale(game->sprite->play2_menu,
        (sfVector2f){4.8 * game->win.ratio, 4.8 * game->win.ratio});
        sfSprite_setPosition(game->sprite->play2_menu,
        (sfVector2f){748 * game->win.ratio, 362 * game->win.ratio});
    } else {
        game->press.click = false;
        sfSprite_setScale(game->sprite->play2_menu,
        (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
        sfSprite_setPosition(game->sprite->play2_menu,
        (sfVector2f){740 * game->win.ratio, 360 * game->win.ratio});
    }
}

void menu_set_button(game_t *game, sfVector2f *set_pos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)
    && game->vector.mouse.x >= set_pos->x
    && game->vector.mouse.x <= set_pos->x + 380 * game->win.ratio
    && game->vector.mouse.y >= set_pos->y
    && game->vector.mouse.y <= set_pos->y + 110 * game->win.ratio
    && !game->press.click) {
        game->press.click = true;
        sfSprite_setScale(game->sprite->set2_menu,
        (sfVector2f){4.8 * game->win.ratio, 4.8 * game->win.ratio});
        sfSprite_setPosition(game->sprite->set2_menu,
        (sfVector2f){748 * game->win.ratio, 492 * game->win.ratio});
    } else {
        game->press.click = false;
        sfSprite_setScale(game->sprite->set2_menu,
        (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
        sfSprite_setPosition(game->sprite->set2_menu,
        (sfVector2f){740 * game->win.ratio, 490 * game->win.ratio});
    }
}

void menu_htp_button(game_t *game, sfVector2f *htp_pos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)
    && game->vector.mouse.x >= htp_pos->x
    && game->vector.mouse.x <= htp_pos->x + 380 * game->win.ratio
    && game->vector.mouse.y >= htp_pos->y
    && game->vector.mouse.y <= htp_pos->y + 110 * game->win.ratio
    && !game->press.click) {
        game->press.click = true;
        sfSprite_setScale(game->sprite->htp2_menu,
        (sfVector2f){4.8 * game->win.ratio, 4.8 * game->win.ratio});
        sfSprite_setPosition(game->sprite->htp2_menu,
        (sfVector2f){748 * game->win.ratio, 622 * game->win.ratio});
    } else {
        game->press.click = false;
        sfSprite_setScale(game->sprite->htp2_menu,
        (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
        sfSprite_setPosition(game->sprite->htp2_menu,
        (sfVector2f){740 * game->win.ratio, 620 * game->win.ratio});
    }
}

void menu_score_button(game_t *game, sfVector2f *score_pos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)
    && game->vector.mouse.x >= score_pos->x
    && game->vector.mouse.x <= score_pos->x + 380 * game->win.ratio
    && game->vector.mouse.y >= score_pos->y
    && game->vector.mouse.y <= score_pos->y + 110 * game->win.ratio
    && !game->press.click) {
        game->press.click = true;
        sfSprite_setScale(game->sprite->high_score2_menu,
        (sfVector2f){4.8 * game->win.ratio, 4.8 * game->win.ratio});
        sfSprite_setPosition(game->sprite->high_score2_menu,
        (sfVector2f){748 * game->win.ratio, 752 * game->win.ratio});
    } else {
        game->press.click = false;
        sfSprite_setScale(game->sprite->high_score2_menu,
        (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
        sfSprite_setPosition(game->sprite->high_score2_menu,
        (sfVector2f){740 * game->win.ratio, 750 * game->win.ratio});
    }
}

void menu_exit_button(game_t *game, sfVector2f *exit_pos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)
    && game->vector.mouse.x >= exit_pos->x
    && game->vector.mouse.x <= exit_pos->x + 380 * game->win.ratio
    && game->vector.mouse.y >= exit_pos->y
    && game->vector.mouse.y <= exit_pos->y + 110 * game->win.ratio
    && !game->press.click) {
        game->press.click = true;
        sfSprite_setScale(game->sprite->exit2_menu,
        (sfVector2f){4.8 * game->win.ratio, 4.8 * game->win.ratio});
        sfSprite_setPosition(game->sprite->exit2_menu,
        (sfVector2f){748 * game->win.ratio, 882 * game->win.ratio});
    } else {
        game->press.click = false;
        sfSprite_setScale(game->sprite->exit2_menu,
        (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
        sfSprite_setPosition(game->sprite->exit2_menu,
        (sfVector2f){740 * game->win.ratio, 880 * game->win.ratio});
    }
}
