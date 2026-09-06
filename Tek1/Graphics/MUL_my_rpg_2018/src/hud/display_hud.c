/*
** EPITECH PROJECT, 2019
** display_hud.c
** File description:
** display hud
*/

#include "my_rpg.h"

int calcul_rect(int value_max, int value, int cas)
{
    float pourcent = (((value * 1.0) / (value_max * 1.0)) * 100.0);
    int result = 0;

    result = ((308 * pourcent) / 100);
    if (cas == 0)
        result = ((432 * pourcent) / 100);
    if (result < 0)
        return (0);
    return (result);
}

void display_hp_mana(game_t *game)
{
    sfVector2f view = sfView_getCenter(game->view.view);

    sfSprite_setTextureRect(game->sprite->hud,
    (sfIntRect){696, 938, 36, calcul_rect(game->var.player_hp,
    game->player.hp, 1)});
    view.x = view.x - 952 * game->win.ratio;
    view.y = view.y + 224 * game->win.ratio;
    sfSprite_setPosition(game->sprite->hud, view);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->hud, NULL);
    sfSprite_setTextureRect(game->sprite->hud,
    (sfIntRect){732, 938, 36, calcul_rect(game->var.player_mana,
    game->player.mana, 1)});
    view = sfView_getCenter(game->view.view);
    view.x = view.x - 892 * game->win.ratio;
    view.y = view.y + 224 * game->win.ratio;
    sfSprite_setPosition(game->sprite->hud, view);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->hud, NULL);
}

void display_money(game_t *game)
{
    sfVector2f view = sfView_getCenter(game->view.view);

    sfSprite_setTextureRect(game->sprite->hud,
    (sfIntRect){1384, 966, 426, 78});
    view.x = view.x - 213 * game->win.ratio;
    view.y = view.y - 542 * game->win.ratio;
    sfSprite_setPosition(game->sprite->hud, view);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->hud, NULL);
}

void display_potion(game_t *game)
{
    sfVector2f view = sfView_getCenter(game->view.view);

    sfSprite_setTextureRect(game->sprite->hud,
    (sfIntRect){631, 861, 93, 4});
    view.x = view.x - 950 * game->win.ratio;
    view.y = view.y + 188 * game->win.ratio;
    sfSprite_setPosition(game->sprite->hud, view);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->hud, NULL);
    view = sfView_getCenter(game->view.view);
    sfSprite_setTextureRect(game->sprite->hud,
    (sfIntRect){631, 865, game->var.potion, 4});
    view.x = view.x - 950 * game->win.ratio;
    view.y = view.y + 188 * game->win.ratio;
    sfSprite_setPosition(game->sprite->hud, view);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->hud, NULL);
}

void display_hud(game_t *game)
{
    sfVector2f view = sfView_getCenter(game->view.view);
    sfText *sf_text = sfText_create();
    sfFont *sf_font = sfFont_createFromFile("assets/font/pixel.ttf");

    sfText_setFont(sf_text, sf_font);
    sfText_setCharacterSize(sf_text, 20);
    display_money(game);
    display_hp_mana(game);
    sfText_setString(sf_text, my_itoa(game->player.gold, 0));
    sfText_setPosition(sf_text, (sfVector2f){view.x - 51 * game->win.ratio,
    view.y - 512 * game->win.ratio});
    sfRenderWindow_drawText(game->win.dow, sf_text, NULL);
    sfSprite_setTextureRect(game->sprite->hud,
    (sfIntRect){781, 889, 8, calcul_rect(game->var.player_xp,
    game->player.xp, 0)});
    sfSprite_setPosition(game->sprite->hud, (sfVector2f){view.x - 840 *
        game->win.ratio, view.y + 100 * game->win.ratio});
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->hud, NULL);
    sfFont_destroy(sf_font);
    sfText_destroy(sf_text);
}
