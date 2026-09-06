/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** create_music_but.c
*/

#include "my_rpg.h"

void create_music_but(game_t *game)
{
    game->rect.music_but = (sfIntRect){0, 0, 11, 11};
    game->text.music = sfText_create();
    sfText_setFont(game->text.music, game->text.font_highscore);
    sfText_setCharacterSize(game->text.music, 30);
    sfText_setString(game->text.music, "Music");
    sfText_setPosition(game->text.music,
    (sfVector2f){920 * game->win.ratio, 378 * game->win.ratio});
    game->sprite->music_but = sfSprite_create();
    game->texture->music_but =
    sfTexture_createFromFile("assets/img/menu/fullscreen.png", NULL);
    sfSprite_setTexture(game->sprite->music_but,
    game->texture->music_but, sfTrue);
    sfSprite_setTextureRect(game->sprite->music_but, game->rect.music_but);
}

static void second_state_music_button(game_t *game)
{
    sfVector2f music_pos = sfSprite_getPosition(game->sprite->music_but);

    if (game->vector.mouse.x >= music_pos.x
        && game->vector.mouse.x <= music_pos.x + 55 * game->win.ratio
        && game->vector.mouse.y >= music_pos.y
        && game->vector.mouse.y <= music_pos.y + 55 * game->win.ratio) {
        game->rect.music_but.top = 11;
        sfSprite_setTextureRect(game->sprite->music_but, game->rect.music_but);
    } else {
        game->rect.music_but.top = 0;
        sfSprite_setTextureRect(game->sprite->music_but, game->rect.music_but);
    }

}

void event_clik_music_but(game_t *game)
{
    sfVector2f music_pos = sfSprite_getPosition(game->sprite->music_but);

    if (sfMouse_isButtonPressed(sfMouseLeft)
        && game->vector.mouse.x >= music_pos.x
        && game->vector.mouse.x <= music_pos.x + 55 * game->win.ratio
        && game->vector.mouse.y >= music_pos.y
        && game->vector.mouse.y <= music_pos.y + 55 * game->win.ratio
        && !game->press.click) {
        game->press.click = true;
        sfSprite_setScale(game->sprite->music_but,
        (sfVector2f){4.8 * game->win.ratio, 4.8 * game->win.ratio});
        sfSprite_setPosition(game->sprite->music_but,
        (sfVector2f){842 * game->win.ratio, 367 * game->win.ratio});
    } else {
        game->press.click = false;
        sfSprite_setScale(game->sprite->music_but,
        (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
        sfSprite_setPosition(game->sprite->music_but,
        (sfVector2f){840 * game->win.ratio, 365 * game->win.ratio});
    }
    second_state_music_button(game);
}
