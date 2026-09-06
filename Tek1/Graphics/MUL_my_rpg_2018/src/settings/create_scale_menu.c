/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** scale set menu
*/

#include "my_rpg.h"

void set_pos_scale_(game_t *game)
{
    sfSprite_setPosition(game->sprite->hud_set,
    (sfVector2f){545 * game->win.ratio, 80 * game->win.ratio});
    sfSprite_setPosition(game->sprite->size_1920_1,
    (sfVector2f){770 * game->win.ratio, 600 * game->win.ratio});
    sfSprite_setPosition(game->sprite->size_1920_2,
    (sfVector2f){750 * game->win.ratio, 600 * game->win.ratio});
    sfSprite_setPosition(game->sprite->size_1664_1,
    (sfVector2f){770 * game->win.ratio, 730 * game->win.ratio});
    sfSprite_setPosition(game->sprite->size_1664_2,
    (sfVector2f){750 * game->win.ratio, 730 * game->win.ratio});
    sfSprite_setPosition(game->sprite->size_1280_1,
    (sfVector2f){770 * game->win.ratio, 860 * game->win.ratio});
    sfSprite_setPosition(game->sprite->size_1280_2,
    (sfVector2f){750 * game->win.ratio, 860 * game->win.ratio});
    sfSprite_setPosition(game->sprite->fullscreen,
    (sfVector2f){620 * game->win.ratio, 270 * game->win.ratio});
    sfSprite_setPosition(game->sprite->vsync,
    (sfVector2f){1250 * game->win.ratio, 270 * game->win.ratio});
    sfSprite_setPosition(game->sprite->logo,
    (sfVector2f){715 * game->win.ratio, 140 * game->win.ratio});
}

void set_pos_scale_bis(game_t *game)
{
    sfSprite_setPosition(game->sprite->key_bindings_1,
    (sfVector2f){770 * game->win.ratio, 470 * game->win.ratio});
    sfSprite_setPosition(game->sprite->key_bindings_2,
    (sfVector2f){750 * game->win.ratio, 470 * game->win.ratio});
    sfText_setPosition(game->text.fullscreen,
    (sfVector2f){690 * game->win.ratio, 285 * game->win.ratio});
    sfText_setPosition(game->text.vsync,
    (sfVector2f){1105 * game->win.ratio, 285 * game->win.ratio});
    sfText_setCharacterSize(game->text.fullscreen, 25 * game->win.ratio);
    sfText_setCharacterSize(game->text.vsync, 25 * game->win.ratio);
    sfSprite_setScale(game->sprite->menu,
    (sfVector2f){game->win.ratio, game->win.ratio});
    sfSprite_setScale(game->sprite->size_1920_1,
    (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
    sfSprite_setScale(game->sprite->size_1920_2,
    (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
    sfSprite_setScale(game->sprite->size_1664_1,
    (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
    sfSprite_setScale(game->sprite->size_1664_2,
    (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
}

void set_pos_scale_set_menu(game_t *game)
{
    set_pos_scale_(game);
    set_pos_scale_bis(game);
    sfSprite_setScale(game->sprite->size_1280_1,
    (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
    sfSprite_setScale(game->sprite->size_1280_2,
    (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
    sfSprite_setScale(game->sprite->hud_set,
    (sfVector2f){4 * game->win.ratio, 5 * game->win.ratio});
    sfSprite_setScale(game->sprite->fullscreen,
    (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
    sfSprite_setScale(game->sprite->vsync,
    (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
    sfSprite_setScale(game->sprite->key_bindings_1,
    (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
    sfSprite_setScale(game->sprite->key_bindings_2,
    (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
    sfSprite_setScale(game->sprite->logo,
    (sfVector2f){1.4 * game->win.ratio, 1.4 * game->win.ratio});
}

void create_set_loop_bis(game_t *game)
{
    sfText_setFont(game->text.fullscreen, game->text.font_highscore);
    sfText_setFont(game->text.vsync, game->text.font_highscore);
    sfText_setString(game->text.fullscreen, "Fullscreen");
    sfText_setString(game->text.vsync, "Vsync");
    sfText_setCharacterSize(game->text.fullscreen, 25);
    sfText_setCharacterSize(game->text.vsync, 25);
    sfText_setColor(game->text.fullscreen, sfWhite);
    sfText_setColor(game->text.vsync, sfWhite);
    sfText_setPosition(game->text.fullscreen,
    (sfVector2f){690 * game->win.ratio, 285 * game->win.ratio});
    sfText_setPosition(game->text.vsync,
    (sfVector2f){1110 * game->win.ratio, 285 * game->win.ratio});
    sfSprite_setTexture(game->sprite->menu, game->texture->menu, sfTrue);
    sfSprite_setTexture(game->sprite->hud_set, game->texture->hud_set, sfTrue);
    sfSprite_setTexture(game->sprite->size_1920_1,
    game->texture->size_1920_1, sfTrue);
    sfSprite_setTexture(game->sprite->size_1920_2,
    game->texture->size_1920_2, sfTrue);
    sfSprite_setTexture(game->sprite->size_1664_1,
    game->texture->size_1664_1, sfTrue);
}

void create_set_loop(game_t *game)
{
    create_sprite_set_loop(game);
    create_texture_set_loop(game);
    create_text_set_loop(game);
    create_set_loop_bis(game);
    create_music_but(game);
    is_extension_create_set_loop(game);
    sfSprite_setTexture(game->sprite->size_1280_1,
    game->texture->size_1280_1, sfTrue);
    sfSprite_setTexture(game->sprite->size_1280_2,
    game->texture->size_1280_2, sfTrue);
    sfSprite_setTexture(game->sprite->fullscreen,
    game->texture->fullscreen, sfTrue);
    sfSprite_setTexture(game->sprite->vsync,
    game->texture->vsync, sfTrue);
    sfSprite_setTexture(game->sprite->key_bindings_1,
    game->texture->key_bindings_1, sfTrue);
    sfSprite_setTexture(game->sprite->key_bindings_2,
    game->texture->key_bindings_2, sfTrue);
    sfSprite_setTextureRect(game->sprite->fullscreen, game->rect.full_but);
    sfSprite_setTextureRect(game->sprite->vsync, game->rect.full_but);
}
