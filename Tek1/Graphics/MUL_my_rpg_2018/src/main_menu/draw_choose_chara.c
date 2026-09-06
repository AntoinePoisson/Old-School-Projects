/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** Game of my_rpg
*/

#include "my_rpg.h"

void draw_chara(game_t *game)
{
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->chara_menu1, NULL);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->chara_menu2, NULL);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->chara_menu3, NULL);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->chara_menu4, NULL);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->chara_menu5, NULL);
    sfRenderWindow_drawText(game->win.dow, game->text.kgnight_menu, NULL);
    sfRenderWindow_drawText(game->win.dow, game->text.priest_menu, NULL);
    sfRenderWindow_drawText(game->win.dow, game->text.sorcerer_menu, NULL);
    sfRenderWindow_drawText(game->win.dow, game->text.thief_menu, NULL);
    sfRenderWindow_drawText(game->win.dow, game->text.wizard_menu, NULL);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->cursor, NULL);
}

void draw_chara_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->menu, NULL);
    sfRenderWindow_drawSprite(game->win.dow,
    game->sprite->chara_menu_hud, NULL);
    sfRenderWindow_drawRectangleShape(game->win.dow,
    game->rectangle.knight_menu, NULL);
    sfRenderWindow_drawRectangleShape(game->win.dow,
    game->rectangle.priest_menu, NULL);
    sfRenderWindow_drawRectangleShape(game->win.dow,
    game->rectangle.sorcerer_menu, NULL);
    sfRenderWindow_drawRectangleShape(game->win.dow,
    game->rectangle.thief_menu, NULL);
    sfRenderWindow_drawRectangleShape(game->win.dow,
    game->rectangle.wizard_menu, NULL);
    draw_chara(game);
}
