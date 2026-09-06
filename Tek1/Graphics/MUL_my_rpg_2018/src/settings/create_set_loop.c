/*
** EPITECH PROJECT, 2019
** create_set_loop
** File description:
** Creations of the set loop
*/

#include "my_rpg.h"

void create_sprite_set_loop(game_t *game)
{
    game->sprite->menu = sfSprite_create();
    game->sprite->hud_set = sfSprite_create();
    game->sprite->size_1920_1 = sfSprite_create();
    game->sprite->size_1664_1 = sfSprite_create();
    game->sprite->size_1280_1 = sfSprite_create();
    game->sprite->size_1920_2 = sfSprite_create();
    game->sprite->size_1664_2 = sfSprite_create();
    game->sprite->size_1280_2 = sfSprite_create();
    game->sprite->fullscreen = sfSprite_create();
    game->sprite->vsync = sfSprite_create();
    game->sprite->key_bindings_1 = sfSprite_create();
    game->sprite->key_bindings_2 = sfSprite_create();
}

void create_texture_set_loop_bis(game_t *game)
{
    game->texture->size_1920_2 =
    sfTexture_createFromFile("assets/img/menu/1920_2.png", NULL);
    game->texture->size_1664_1 =
    sfTexture_createFromFile("assets/img/menu/1664_1.png", NULL);
    game->texture->size_1664_2 =
    sfTexture_createFromFile("assets/img/menu/1664_2.png", NULL);
    game->texture->size_1280_1 =
    sfTexture_createFromFile("assets/img/menu/1280_1.png", NULL);
    game->texture->size_1280_2 =
    sfTexture_createFromFile("assets/img/menu/1280_2.png", NULL);
    game->texture->fullscreen =
    sfTexture_createFromFile("assets/img/menu/fullscreen.png", NULL);
    game->texture->vsync =
    sfTexture_createFromFile("assets/img/menu/fullscreen.png", NULL);
    game->texture->key_bindings_1 =
    sfTexture_createFromFile("assets/img/menu/key_bindings_1.png", NULL);
    game->texture->key_bindings_2 =
    sfTexture_createFromFile("assets/img/menu/key_bindings_2.png", NULL);
}

void create_texture_set_loop(game_t *game)
{
    game->text.fullscreen = sfText_create();
    game->text.vsync = sfText_create();
    game->text.font_highscore = sfFont_createFromFile("assets/font/pixel.ttf");
    game->texture->menu =
    sfTexture_createFromFile("assets/img/menu/back.png", NULL);
    game->texture->hud_set =
    sfTexture_createFromFile("assets/img/menu/menu_hud2.png", NULL);
    game->texture->size_1920_1 =
    sfTexture_createFromFile("assets/img/menu/1920_1.png", NULL);
    create_texture_set_loop_bis(game);
}

void create_text_set_loop(game_t *game)
{
    game->text.fullscreen = sfText_create();
    game->text.vsync = sfText_create();
    game->text.font_highscore = sfFont_createFromFile("assets/font/pixel.ttf");
}
