/*
** EPITECH PROJECT, 2018
** move_perso
** File description:
** move_perso
*/

#include "move_perso.h"

void change_cursor_mouse(variable_t *sf)
{
    sfTexture *tex_vis = sfTexture_createFromFile("./images/viseur.png", NULL);
    sfSprite *viseur = sfSprite_create();

    sfSprite_setTexture(viseur, tex_vis, sfTrue);
    sf->vector.twoi = sfMouse_getPositionRenderWindow(sf->win.dow);
    sf->vector.twof.x = sf->vector.twoi.x * 1.0 - 42.5;
    sf->vector.twof.y = sf->vector.twoi.y * 1.0 - 34;
    sfSprite_setPosition(viseur, sf->vector.twof);
    sfRenderWindow_drawSprite(sf->win.dow, viseur, NULL);
}

void put_out_map_ghost(variable_t *sf)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sf->vector.twoi = sfMouse_getPositionRenderWindow(sf->win.dow);
        if ((sfSprite_getPosition(sf->sprite.ghost).x <= sf->vector.twoi.x) &&
            (sf->vector.twoi.y >= (sfSprite_getPosition(sf->sprite.ghost).y)))
            if ((sfSprite_getPosition(sf->sprite.ghost).y + 124 >=
                sf->vector.twoi.y) && (sf->vector.twoi.x <=
                (sfSprite_getPosition(sf->sprite.ghost).x + 124))) {
                sf->vector.ghost.y = 427;
                sf->vector.ghost.x = rand_ghost_x();
                sf->var_norm.acceleration_ghost += 0.9;
                change_time_score(sf);
            }
    }
}

void is_extension_move_ghost(int max_value, variable_t *sf)
{
    if (sf->rect.ghost.left >= max_value)
        sf->rect.ghost.left = 0;
    if (sf->vector.ghost.x >= 200)
        sf->vector.ghost.x -= sf->var_norm.acceleration_ghost;
    if (sf->vector.ghost.x <= 200) {
        sf->var_norm.heal_point--;
        change_heal_point(sf);
        sf->vector.ghost.y = 427;
        sf->vector.ghost.x = rand_ghost_x();
    }
}

void is_extension_move_ghost_three(variable_t *sf)
{
    put_out_map_ghost(sf);
    gestion_window_one(sf);
    gestion_window_two(sf);
    gestion_door_one(sf);
    gestion_door_two(sf);
    change_cursor_mouse(sf);
}

void is_extension_move_ghost_two(variable_t *sf)
{
    gestion_back(sf);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.window_one, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.window_two, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.back, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.ghost, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.duck, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.bg_h_o, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.bg_h_t, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.door_one, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.door_two, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.bg_h_o_s, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.bg_h_t_s, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.girl, NULL);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.heal_point, NULL);
    sfRenderWindow_drawText(sf->win.dow, sf->text.score, NULL);
    change_time_text(sf);
    sfRenderWindow_drawText(sf->win.dow, sf->text.time, NULL);
    if (sf->var_norm.shoot == 1)
        sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.shoot, NULL);
}
