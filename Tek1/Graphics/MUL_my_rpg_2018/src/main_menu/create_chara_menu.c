/*
** EPITECH PROJECT, 2019
** create_chara_menu
** File description:
** Create of chara menu
*/

#include "my_rpg.h"

void create_rect_shape_chara_menu(game_t *game)
{
    sfRectangleShape_setPosition(game->rectangle.knight_menu,
    (sfVector2f){375 * game->win.ratio, 150 * game->win.ratio});
    sfRectangleShape_setPosition(game->rectangle.priest_menu,
    (sfVector2f){828 * game->win.ratio, 150 * game->win.ratio});
    sfRectangleShape_setPosition(game->rectangle.sorcerer_menu,
    (sfVector2f){1245 * game->win.ratio, 150 * game->win.ratio});
    sfRectangleShape_setPosition(game->rectangle.thief_menu,
    (sfVector2f){598 * game->win.ratio, 550 * game->win.ratio});
    sfRectangleShape_setPosition(game->rectangle.wizard_menu,
    (sfVector2f){1054 * game->win.ratio, 550 * game->win.ratio});
}

void create_rectangle_shape_chara_menu(game_t *game)
{
    game->rectangle.knight_menu = sfRectangleShape_create();
    game->rectangle.priest_menu = sfRectangleShape_create();
    game->rectangle.sorcerer_menu = sfRectangleShape_create();
    game->rectangle.thief_menu = sfRectangleShape_create();
    game->rectangle.wizard_menu = sfRectangleShape_create();
    sfRectangleShape_setSize(game->rectangle.knight_menu,
    (sfVector2f){250 * game->win.ratio, 300 * game->win.ratio});
    sfRectangleShape_setSize(game->rectangle.priest_menu,
    (sfVector2f){200 * game->win.ratio, 300 * game->win.ratio});
    sfRectangleShape_setSize(game->rectangle.sorcerer_menu,
    (sfVector2f){190 * game->win.ratio, 300 * game->win.ratio});
    sfRectangleShape_setSize(game->rectangle.thief_menu,
    (sfVector2f){200 * game->win.ratio, 300 * game->win.ratio});
    sfRectangleShape_setSize(game->rectangle.wizard_menu,
    (sfVector2f){190 * game->win.ratio, 300 * game->win.ratio});
    create_rect_shape_chara_menu(game);
}

static void create_text_chara(game_t *game)
{
    sfText_setCharacterSize(game->text.kgnight_menu, 40 * game->win.ratio);
    sfText_setCharacterSize(game->text.priest_menu, 40 * game->win.ratio);
    sfText_setCharacterSize(game->text.sorcerer_menu, 40 * game->win.ratio);
    sfText_setCharacterSize(game->text.thief_menu, 40 * game->win.ratio);
    sfText_setCharacterSize(game->text.wizard_menu, 40 * game->win.ratio);
    sfText_setPosition(game->text.kgnight_menu,
    (sfVector2f){405 * game->win.ratio, 485 * game->win.ratio});
    sfText_setPosition(game->text.priest_menu,
    (sfVector2f){810 * game->win.ratio, 485 * game->win.ratio});
    sfText_setPosition(game->text.sorcerer_menu,
    (sfVector2f){1210 * game->win.ratio, 485 * game->win.ratio});
    sfText_setPosition(game->text.thief_menu,
    (sfVector2f){610 * game->win.ratio, 885 * game->win.ratio});
    sfText_setPosition(game->text.wizard_menu,
    (sfVector2f){1050 * game->win.ratio, 885 * game->win.ratio});
}

void create_text_chara_menu(game_t *game)
{
    game->text.font_highscore = sfFont_createFromFile("assets/font/pixel.ttf");
    game->text.kgnight_menu = sfText_create();
    game->text.priest_menu = sfText_create();
    game->text.sorcerer_menu = sfText_create();
    game->text.thief_menu = sfText_create();
    game->text.wizard_menu = sfText_create();
    sfText_setFont(game->text.kgnight_menu, game->text.font_highscore);
    sfText_setFont(game->text.priest_menu, game->text.font_highscore);
    sfText_setFont(game->text.sorcerer_menu, game->text.font_highscore);
    sfText_setFont(game->text.thief_menu, game->text.font_highscore);
    sfText_setFont(game->text.wizard_menu, game->text.font_highscore);
    sfText_setString(game->text.kgnight_menu, "Knight");
    sfText_setString(game->text.priest_menu, "Priest");
    sfText_setString(game->text.sorcerer_menu, "Sorcerer");
    sfText_setString(game->text.thief_menu, "Thief");
    sfText_setString(game->text.wizard_menu, "Wizard");
    create_text_chara(game);
}
