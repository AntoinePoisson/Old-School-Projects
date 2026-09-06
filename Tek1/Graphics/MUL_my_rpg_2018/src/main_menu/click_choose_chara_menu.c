/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** Click on characters in chara menu
*/

#include "my_rpg.h"

static void click_knight_chara_menu(game_t *game)
{
    sfVector2f knight_pos =
    sfRectangleShape_getPosition(game->rectangle.knight_menu);

    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    game->vector.mouse.x >= knight_pos.x &&
    game->vector.mouse.x <= knight_pos.x + 200 * game->win.ratio &&
    game->vector.mouse.y >= knight_pos.y &&
    game->vector.mouse.y <= knight_pos.y + 300 * game->win.ratio &&
    !game->press.click) {
        game->press.click = true;
        game->var.chara = 1;
        game->var.quit_beach = 0;
        game_loop(game);
    }
}

static void click_priest_chara_menu(game_t *game)
{
    sfVector2f priest_pos =
    sfRectangleShape_getPosition(game->rectangle.priest_menu);

    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    game->vector.mouse.x >= priest_pos.x &&
    game->vector.mouse.x <= priest_pos.x + 200 * game->win.ratio &&
    game->vector.mouse.y >= priest_pos.y &&
    game->vector.mouse.y <= priest_pos.y + 300 * game->win.ratio &&
    !game->press.click) {
        game->press.click = true;
        game->var.chara = 2;
        game->var.quit_beach = 0;
        game_loop(game);
    }
}

static void click_sorcerer_chara_menu(game_t *game)
{
    sfVector2f sorcerer_pos =
    sfRectangleShape_getPosition(game->rectangle.sorcerer_menu);

    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    game->vector.mouse.x >= sorcerer_pos.x &&
    game->vector.mouse.x <= sorcerer_pos.x + 200 * game->win.ratio &&
    game->vector.mouse.y >= sorcerer_pos.y &&
    game->vector.mouse.y <= sorcerer_pos.y + 300 * game->win.ratio &&
    !game->press.click) {
        game->press.click = true;
        game->var.chara = 3;
        game->var.quit_beach = 0;
        game_loop(game);
    }
}

static void click_thief_chara_menu(game_t *game)
{
    sfVector2f thief_pos =
    sfRectangleShape_getPosition(game->rectangle.thief_menu);

    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    game->vector.mouse.x >= thief_pos.x &&
    game->vector.mouse.x <= thief_pos.x + 200 * game->win.ratio &&
    game->vector.mouse.y >= thief_pos.y &&
    game->vector.mouse.y <= thief_pos.y + 300 * game->win.ratio &&
    !game->press.click) {
        game->press.click = true;
        game->var.chara = 4;
        game->var.quit_beach = 0;
        game_loop(game);
    }
}

void click_choose_chara_menu(game_t *game)
{
    sfVector2f wizard_pos =
    sfRectangleShape_getPosition(game->rectangle.wizard_menu);

    click_knight_chara_menu(game);
    click_priest_chara_menu(game);
    click_sorcerer_chara_menu(game);
    click_thief_chara_menu(game);
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    game->vector.mouse.x >= wizard_pos.x &&
    game->vector.mouse.x <= wizard_pos.x + 200 * game->win.ratio &&
    game->vector.mouse.y >= wizard_pos.y &&
    game->vector.mouse.y <= wizard_pos.y + 300 * game->win.ratio &&
    !game->press.click) {
        game->press.click = true;
        game->var.chara = 5;
        game->var.quit_beach = 0;
        game_loop(game);
    } if (game->win.event.type == sfEvtMouseButtonReleased &&
        game->win.event.mouseButton.button == sfMouseLeft &&
        game->press.click)
        game->press.click = false;
}
