/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** pause_funct
*/

#include "my_rpg.h"

void draw_pause_game_loop(game_t *game)
{
    display_beach(game);
    display_spell_particle(game);
    display_rain_particle(game);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->back_pause, NULL);
    draw_buttons_pause(game);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->cursor, NULL);
}

void draw_pause_donjon(game_t *game)
{
    display_donjon(game);
    display_spell_particle(game);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->back_pause, NULL);
    draw_buttons_pause(game);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->cursor, NULL);
}

void pause_game_loop(game_t *game)
{
    game->press.click = false;
    game->var.pause = false;
    while (1) {
        sfRenderWindow_pollEvent(game->win.dow, &game->win.event);
        if (game->win.event.type == sfEvtClosed) {
            game->var.quit_beach = 1;
            return;
        }
        if (game->var.pause == true)
            return;
        event_move_mouse(game);
        set_pos_pause(game);
        state_buttons_pause(game);
        click_buttons_pause(game);
        draw_pause_game_loop(game);
        sfRenderWindow_display(game->win.dow);
        sfRenderWindow_clear(game->win.dow, sfBlack);
    }
}

void pause_game_donjon(game_t *game)
{
    game->press.click = false;
    game->var.pause = false;
    while (1) {
        sfRenderWindow_pollEvent(game->win.dow, &game->win.event);
        if (game->win.event.type == sfEvtClosed) {
            game->var.quit_donjon = 1;
            return;
        }
        if (game->var.pause == true)
            return;
        event_move_mouse(game);
        set_pos_pause(game);
        state_buttons_pause(game);
        click_buttons_pause(game);
        draw_pause_donjon(game);
        sfRenderWindow_display(game->win.dow);
        sfRenderWindow_clear(game->win.dow, sfBlack);
    }
}
