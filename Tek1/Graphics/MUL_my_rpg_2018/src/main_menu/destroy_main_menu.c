/*
** EPITECH PROJECT, 2019
** destroy_main_menu
** File description:
** All destroy of the main menu
*/

#include "my_rpg.h"

void destroy_intro(game_t *game)
{
    sfSprite_destroy(game->intro->sprite);
    sfTexture_destroy(game->intro->texture);
}

static void is_extension_destroy_main_menu(game_t *game)
{
    sfImage_destroy(game->texture->donjon_hitbox);
    sfClock_destroy(game->clock->particle);
    sfClock_destroy(game->player.clock);
    sfRenderWindow_close(game->win.dow);
    sfRenderWindow_destroy(game->win.dow);
}

void destroy_main_menu(game_t *game)
{
    sfSprite_destroy(game->sprite->menu);
    sfTexture_destroy(game->texture->menu);
    sfSprite_destroy(game->sprite->play1_menu);
    sfTexture_destroy(game->texture->play2_menu);
    sfSprite_destroy(game->sprite->set1_menu);
    sfTexture_destroy(game->texture->set2_menu);
    sfSprite_destroy(game->sprite->htp1_menu);
    sfTexture_destroy(game->texture->htp2_menu);
    sfSprite_destroy(game->sprite->exit1_menu);
    sfTexture_destroy(game->texture->exit2_menu);
    sfSprite_destroy(game->sprite->logo);
    sfTexture_destroy(game->texture->logo);
    sfSprite_destroy(game->sprite->hud_menu);
    sfTexture_destroy(game->texture->hud_menu);
    sfRectangleShape_destroy(game->intro->rectangle);
    sfMusic_destroy(game->music->menu);
    sfClock_destroy(game->clock->anim);
    is_extension_destroy_main_menu(game);
}
