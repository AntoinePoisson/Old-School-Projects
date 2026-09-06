/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** create a custom rpg
*/

#include "my_rpg.h"

int manage_fade(game_t *game, unsigned short value)
{
    if (sfClock_getElapsedTime(game->clock->anim).microseconds >= 30000)
        sfClock_restart(game->clock->anim);
    else
        return (0);
    if (game->intro->fade == 2 && game->intro->alpha < 244) {
        game->intro->alpha += value;
        sfRectangleShape_setFillColor(game->intro->rectangle,
        sfColor_fromRGBA(0, 0, 0, game->intro->alpha));
        if (game->intro->alpha >= 244)
            game->intro->fade = 1;
    }
    else if (game->intro->fade == 1 && game->intro->alpha > 0) {
        game->intro->alpha -= value;
        sfRectangleShape_setFillColor(game->intro->rectangle,
        sfColor_fromRGBA(0, 0, 0, game->intro->alpha));
        if (game->intro->alpha == 0)
            game->intro->fade = 0;
    }
    return (0);
}

void create_intro_bis(game_t *game)
{
    game->particle->spell = sfRectangleShape_create();
    sfRectangleShape_setFillColor(game->particle->spell,
    sfColor_fromRGBA(190, 60, 60, 255));
    sfRectangleShape_setSize(game->particle->spell,
    (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
}

void create_intro(game_t *game)
{
    game->intro->alpha = 254;
    sfRectangleShape_setFillColor(game->intro->rectangle,
    sfColor_fromRGBA(0, 0, 0, 255));
    sfRectangleShape_setSize(game->intro->rectangle,
    (sfVector2f){1920 * game->win.ratio, 1080 * game->win.ratio});
    game->intro->sprite = sfSprite_create();
    game->intro->texture =
    sfTexture_createFromFile("assets/img/menu/menu_intro.png", NULL);
    sfSprite_setScale(game->intro->sprite,
    (sfVector2f){1.461 * game->win.ratio, 1.461 * game->win.ratio});
    sfSprite_setTexture(game->intro->sprite, game->intro->texture, sfTrue);
    game->sprite->cursor = sfSprite_create();
    game->texture->cursor =
    sfTexture_createFromFile("assets/img/other/cursor.png", NULL);
    sfSprite_setTexture(game->sprite->cursor, game->texture->cursor, sfTrue);
    sfSprite_setScale(game->sprite->cursor,
    (sfVector2f){1.5 * game->win.ratio, 1.5 * game->win.ratio});
    create_intro_bis(game);
}

void draw_intro_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->win.dow, game->intro->sprite, NULL);
    sfRenderWindow_drawRectangleShape(game->win.dow,
    game->intro->rectangle, NULL);
    sfRenderWindow_display(game->win.dow);
    sfRenderWindow_clear(game->win.dow, sfBlack);
}

void intro_menu(game_t *game)
{
    bool close = false;
    bool fade_out = false;

    game->intro->rectangle = sfRectangleShape_create();
    create_intro(game);
    game->intro->fade = 1;
    while (sfRenderWindow_isOpen(game->win.dow) && close == false) {
        event_intro(game, &close);
        if (close)
            break;
        manage_fade(game, 2);
        if (game->intro->alpha <= 5) {
            game->intro->fade = 2;
            fade_out = true;
        }
        if (fade_out && game->intro->alpha >= 240)
            break;
        draw_intro_menu(game);
    }
    destroy_intro(game);
}
