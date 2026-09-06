/*
** EPITECH PROJECT, 2018
** is_menu
** File description:
** menu
*/

#include "my_lib.h"
#include "csfml.h"
#include "struct.h"

int is_runner(variable_t *sf, char *av[], int ac);
void create_end_level(variable_t *sf);
void create_is_second_menu(variable_t *sf);

int select_on_play(variable_t *sf)
{
    sf->vector.twoi = sfMouse_getPositionRenderWindow(sf->win.dow);
    if (sfSprite_getPosition(sf->sprite.play).x <= sf->vector.twoi.x &&
        sf->vector.twoi.y >= (sfSprite_getPosition(sf->sprite.play).y)) {
        if (sfSprite_getPosition(sf->sprite.play).y + 123 >= sf->vector.twoi.y
            && sf->vector.twoi.x <= (sfSprite_getPosition(sf->sprite.play).x
            + 465)) {
            return (1);
        }
    }
    return (0);
}

int select_on_highscore(variable_t *sf)
{
    sf->vector.twoi = sfMouse_getPositionRenderWindow(sf->win.dow);
    if (sfSprite_getPosition(sf->sprite.highscore).x <= sf->vector.twoi.x &&
        sf->vector.twoi.y >= (sfSprite_getPosition(sf->sprite.highscore).y)) {
        if (sfSprite_getPosition(sf->sprite.highscore).y + 119 >=
            sf->vector.twoi.y && sf->vector.twoi.x <=
            (sfSprite_getPosition(sf->sprite.highscore).x + 465)) {
            return (1);
        }
    }
    return (0);
}

int select_on_quit(variable_t *sf)
{
    sf->vector.twoi = sfMouse_getPositionRenderWindow(sf->win.dow);
    if (sfSprite_getPosition(sf->sprite.quit).x <= sf->vector.twoi.x &&
        sf->vector.twoi.y >= (sfSprite_getPosition(sf->sprite.quit).y)) {
        if (sfSprite_getPosition(sf->sprite.quit).y + 103 >= sf->vector.twoi.y
            && sf->vector.twoi.x <= (sfSprite_getPosition(sf->sprite.quit).x
            + 465)) {
            return (1);
        }
    }
    return (0);
}

void position_obj_menu(variable_t *sf)
{
    sf->vector.select.x = 560;
    sf->vector.select.y = 399;
    sfSprite_setPosition(sf->sprite.play, sf->vector.select);
    sf->vector.select.x = 566;
    sf->vector.select.y = 539;
    sfSprite_setPosition(sf->sprite.highscore, sf->vector.select);
    sf->vector.select.x = 565;
    sf->vector.select.y = 675;
    sfSprite_setPosition(sf->sprite.quit, sf->vector.select);
}
void clic_button_play(variable_t *sf, char *av[], int ac)
{
    create_end_level(sf);
    sfMusic_stop(sf->music.bg_menu);
    is_runner(sf, av, ac);
    sfSprite_destroy(sf->sprite.end_level);
    sfTexture_destroy(sf->texture.end_level);
    sfMusic_play(sf->music.bg_menu);
    sfMusic_setLoop(sf->music.bg_menu, sfTrue);
}