/*
** EPITECH PROJECT, 2018
** is_runner
** File description:
** file of runner
*/

#include "is_runner.h"

void refresh_game(variable_t *sf, float seconds)
{
    if (seconds >= 0.013) {
        gestion_dino(sf);
        display(sf);
        sfClock_restart(sf->clock.game);
        if (sf->var_norm.nbr_obstacle <= sf->var_norm.nbr_obstacle_past ||
            sf->var_norm.health_point <= 0)
            end_level(sf);
    }
}

void destroy_game(variable_t *sf)
{
    sfSprite_destroy(sf->sprite.bird);
    sfTexture_destroy(sf->texture.bird);
    sfSprite_destroy(sf->sprite.dino);
    sfTexture_destroy(sf->texture.dino);
    sfSprite_destroy(sf->sprite.portal);
    sfTexture_destroy(sf->texture.portal);
    sfSprite_destroy(sf->sprite.cactus);
    sfTexture_destroy(sf->texture.cactus);
    sfSprite_destroy(sf->sprite.health_point);
    sfTexture_destroy(sf->texture.health_point);
    sfSprite_destroy(sf->sprite.win);
    sfTexture_destroy(sf->texture.win);
    sfSprite_destroy(sf->sprite.loss);
    sfTexture_destroy(sf->texture.loss);
    sfText_destroy(sf->text.score);
    sfFont_destroy(sf->text.font_score);
}

void is_extension_is_runner_two(variable_t *sf)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) ||
        sfKeyboard_isKeyPressed(sfKeySpace) ||
        sfKeyboard_isKeyPressed(sfKeyUp))
        dino_move_up(sf);
    if (sfKeyboard_isKeyPressed(sfKeyS) ||
        sfKeyboard_isKeyPressed(sfKeyDown))
        dino_move_down(sf);
    if (sfKeyboard_isKeyPressed(sfKeyD) ||
        sfKeyboard_isKeyPressed(sfKeyRight))
        dino_move_right(sf);
    if (sfKeyboard_isKeyPressed(sfKeyQ) ||
        sfKeyboard_isKeyPressed(sfKeyLeft))
        dino_move_left(sf);
    if (sfKeyboard_isKeyPressed(sfKeyA))
        dino_move_speed(sf);

}

int is_extension_is_runner(variable_t *sf)
{
    if (sf->var_norm.health_point != 0 && sf->var_norm.nbr_obstacle_past !=
        sf->var_norm.nbr_obstacle && sf->var_norm.quit_game == 1) {
        if (sf->event.event.type == sfEvtClosed) {
            sf->var_norm.quit_game = 0;
            sf->var_norm.menu = 0;
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sf->var_norm.quit_game = 0;
        is_extension_is_runner_two(sf);
    }
    else
        return (0);
    return (1);
}

int is_runner(variable_t *sf, char *av[], int ac)
{
    float seconds = 0;

    transition_menu_to_game(sf);
    sfMusic_play(sf->music.bg_game);
    sfMusic_setLoop(sf->music.bg_game, sfTrue);
    if (sf->var_norm.quit_game != 0 && is_create_obstacle(av, ac, sf) != 0)
        sf->var_norm.quit_game = 0;
    else
        sf->var_norm.quit_game = 1;
    while (sfRenderWindow_isOpen(sf->win.dow) && sf->var_norm.quit_game == 1) {
        sf->time.game = sfClock_getElapsedTime(sf->clock.game);
        seconds = sf->time.game.microseconds / 1000000.0;
        if (sfRenderWindow_pollEvent(sf->win.dow, &sf->event.event) &&
            (is_extension_is_runner(sf) == 1));
        else
            refresh_game(sf, seconds);
    }
    destroy_game(sf);
    return (0);
}
