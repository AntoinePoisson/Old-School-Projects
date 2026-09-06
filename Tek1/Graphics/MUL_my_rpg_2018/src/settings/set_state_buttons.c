/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** set state button
*/

#include "my_rpg.h"

void set_size1_button(game_t *game, sfVector2f *size1_pos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)
        && game->vector.mouse.x >= size1_pos->x
        && game->vector.mouse.x <= size1_pos->x + 380 * game->win.ratio
        && game->vector.mouse.y >= size1_pos->y &&
        game->vector.mouse.y <= size1_pos->y + 110 * game->win.ratio
        && !game->press.click) {
        game->press.click = true;
        sfSprite_setScale(game->sprite->size_1920_2,
        (sfVector2f){4.8 * game->win.ratio, 4.8 * game->win.ratio});
        sfSprite_setPosition(game->sprite->size_1920_2,
        (sfVector2f){758 * game->win.ratio, 602 * game->win.ratio});
    } else {
        game->press.click = false;
        sfSprite_setScale(game->sprite->size_1920_2,
        (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
        sfSprite_setPosition(game->sprite->size_1920_2,
        (sfVector2f){750 * game->win.ratio, 600 * game->win.ratio});
    }
}

void set_size2_button(game_t *game, sfVector2f *size2_pos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)
        && game->vector.mouse.x >= size2_pos->x
        && game->vector.mouse.x <= size2_pos->x + 380 * game->win.ratio
        && game->vector.mouse.y >= size2_pos->y
        && game->vector.mouse.y <= size2_pos->y + 110 * game->win.ratio
        && !game->press.click) {
        game->press.click = true;
        sfSprite_setScale(game->sprite->size_1664_2,
        (sfVector2f){4.8 * game->win.ratio, 4.8 * game->win.ratio});
        sfSprite_setPosition(game->sprite->size_1664_2,
        (sfVector2f){758 * game->win.ratio, 732 * game->win.ratio});
    } else {
        game->press.click = false;
        sfSprite_setScale(game->sprite->size_1664_2,
        (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
        sfSprite_setPosition(game->sprite->size_1664_2,
        (sfVector2f){750 * game->win.ratio, 730 * game->win.ratio});
    }
}

void set_size3_button(game_t *game, sfVector2f *size3_pos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)
        && game->vector.mouse.x >= size3_pos->x
        && game->vector.mouse.x <= size3_pos->x + 380 * game->win.ratio
        && game->vector.mouse.y >= size3_pos->y
        && game->vector.mouse.y <= size3_pos->y + 110 * game->win.ratio
        && !game->press.click) {
        game->press.click = true;
        sfSprite_setScale(game->sprite->size_1280_2,
        (sfVector2f){4.8 * game->win.ratio, 4.8 * game->win.ratio});
        sfSprite_setPosition(game->sprite->size_1280_2,
        (sfVector2f){758 * game->win.ratio, 862 * game->win.ratio});
    } else {
        game->press.click = false;
        sfSprite_setScale(game->sprite->size_1280_2,
        (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
        sfSprite_setPosition(game->sprite->size_1280_2,
        (sfVector2f){750 * game->win.ratio, 860 * game->win.ratio});
    }
}

void set_size4_button(game_t *game, sfVector2f *size4_pos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)
        && game->vector.mouse.x >= size4_pos->x
        && game->vector.mouse.x <= size4_pos->x + 380 * game->win.ratio
        && game->vector.mouse.y >= size4_pos->y
        && game->vector.mouse.y <= size4_pos->y + 110 * game->win.ratio
        && !game->press.click) {
        game->press.click = true;
        sfSprite_setScale(game->sprite->key_bindings_2,
        (sfVector2f){4.8 * game->win.ratio, 4.8 * game->win.ratio});
        sfSprite_setPosition(game->sprite->key_bindings_2,
        (sfVector2f){758 * game->win.ratio, 472 * game->win.ratio});
    } else {
        game->press.click = false;
        sfSprite_setScale(game->sprite->key_bindings_2,
        (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
        sfSprite_setPosition(game->sprite->key_bindings_2,
        (sfVector2f){750 * game->win.ratio, 470 * game->win.ratio});
    }
}

void set_full_button(game_t *game, sfVector2f *full_pos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)
        && game->vector.mouse.x >= full_pos->x
        && game->vector.mouse.x <= full_pos->x + 55 * game->win.ratio
        && game->vector.mouse.y >= full_pos->y
        && game->vector.mouse.y <= full_pos->y + 55 * game->win.ratio
        && !game->press.click) {
        game->press.click = true;
        sfSprite_setScale(game->sprite->fullscreen,
        (sfVector2f){4.8 * game->win.ratio, 4.8 * game->win.ratio});
        sfSprite_setPosition(game->sprite->fullscreen,
        (sfVector2f){622 * game->win.ratio, 272 * game->win.ratio});
    } else {
        game->press.click = false;
        sfSprite_setScale(game->sprite->fullscreen,
        (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
        sfSprite_setPosition(game->sprite->fullscreen,
        (sfVector2f){620 * game->win.ratio, 270 * game->win.ratio});
    }
}
