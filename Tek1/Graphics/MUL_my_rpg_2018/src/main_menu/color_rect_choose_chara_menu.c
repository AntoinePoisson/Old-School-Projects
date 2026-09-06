/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** Click on buttons in choose chara menu
*/

#include "my_rpg.h"

static void color_rect_knight_chara_menu(game_t *game)
{
    sfVector2f knight_pos =
    sfRectangleShape_getPosition(game->rectangle.knight_menu);

    if (game->vector.mouse.x >= knight_pos.x &&
        game->vector.mouse.x <= knight_pos.x + 250 * game->win.ratio &&
        game->vector.mouse.y >= knight_pos.y &&
        game->vector.mouse.y <= knight_pos.y + 300 * game->win.ratio)
        sfRectangleShape_setFillColor(game->rectangle.knight_menu,
        sfColor_fromRGBA(255, 140, 0, 100));
    else
        sfRectangleShape_setFillColor(game->rectangle.knight_menu,
        sfColor_fromRGBA(255, 140, 0, 0));
}

static void color_rect_priest_chara_menu(game_t *game)
{
    sfVector2f priest_pos =
    sfRectangleShape_getPosition(game->rectangle.priest_menu);

    if (game->vector.mouse.x >= priest_pos.x &&
        game->vector.mouse.x <= priest_pos.x + 200 * game->win.ratio &&
        game->vector.mouse.y >= priest_pos.y &&
        game->vector.mouse.y <= priest_pos.y + 300 * game->win.ratio)
        sfRectangleShape_setFillColor(game->rectangle.priest_menu,
        sfColor_fromRGBA(255, 140, 0, 100));
    else
        sfRectangleShape_setFillColor(game->rectangle.priest_menu,
        sfColor_fromRGBA(255, 140, 0, 0));
}

static void color_rect_sorcerer_chara_menu(game_t *game)
{
    sfVector2f sorcerer_pos =
    sfRectangleShape_getPosition(game->rectangle.sorcerer_menu);

    if (game->vector.mouse.x >= sorcerer_pos.x &&
        game->vector.mouse.x <= sorcerer_pos.x + 190 * game->win.ratio &&
        game->vector.mouse.y >= sorcerer_pos.y &&
        game->vector.mouse.y <= sorcerer_pos.y + 300 * game->win.ratio)
        sfRectangleShape_setFillColor(game->rectangle.sorcerer_menu,
        sfColor_fromRGBA(255, 140, 0, 100));
    else
        sfRectangleShape_setFillColor(game->rectangle.sorcerer_menu,
        sfColor_fromRGBA(255, 140, 0, 0));
}

static void color_rect_thief_chara_menu(game_t *game)
{
    sfVector2f thief_pos =
    sfRectangleShape_getPosition(game->rectangle.thief_menu);

    if (game->vector.mouse.x >= thief_pos.x &&
        game->vector.mouse.x <= thief_pos.x + 200 * game->win.ratio &&
        game->vector.mouse.y >= thief_pos.y &&
        game->vector.mouse.y <= thief_pos.y + 300 * game->win.ratio)
        sfRectangleShape_setFillColor(game->rectangle.thief_menu,
        sfColor_fromRGBA(255, 140, 0, 100));
    else
        sfRectangleShape_setFillColor(game->rectangle.thief_menu,
        sfColor_fromRGBA(255, 140, 0, 0));
}

void color_rect_choose_chara_menu(game_t *game)
{
    sfVector2f wizard_pos =
    sfRectangleShape_getPosition(game->rectangle.wizard_menu);

    color_rect_knight_chara_menu(game);
    color_rect_priest_chara_menu(game);
    color_rect_sorcerer_chara_menu(game);
    color_rect_thief_chara_menu(game);
    if (game->vector.mouse.x >= wizard_pos.x &&
        game->vector.mouse.x <= wizard_pos.x + 190 * game->win.ratio &&
        game->vector.mouse.y >= wizard_pos.y &&
        game->vector.mouse.y <= wizard_pos.y + 300 * game->win.ratio)
        sfRectangleShape_setFillColor(game->rectangle.wizard_menu,
        sfColor_fromRGBA(255, 140, 0, 100));
    else
        sfRectangleShape_setFillColor(game->rectangle.wizard_menu,
        sfColor_fromRGBA(255, 140, 0, 0));
}