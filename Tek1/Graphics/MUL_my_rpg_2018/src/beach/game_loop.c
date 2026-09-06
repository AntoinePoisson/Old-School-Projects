/*
** EPITECH PROJECT, 2019
** game_loop
** File description:
** Main loop of the game
*/

#include "my_rpg.h"

void destroy_beach(game_t *game)
{
    game->var.quit_beach = 1;
    sfMusic_stop(game->music->rain);
    sfMusic_destroy(game->music->rain);
    sfSprite_destroy(game->sprite->pnj_beach);
    sfTexture_destroy(game->texture->pnj_beach);
    sfText_destroy(game->text.pnj_name);
    sfText_destroy(game->text.player_name);
    sfText_destroy(game->text.pnj_answ);
    sfText_destroy(game->text.player_answ);
    sfText_destroy(game->text.press_space);
    sfClock_destroy(game->clock->regeneration);
    sfClock_destroy(game->clock->trap);
    sfClock_destroy(game->player.clock_regen);
}

void enter_cave(game_t *game)
{
    sfVector2f player = {(sfSprite_getPosition(game->sprite->player).x -
    game->view.offset.x) * game->win.ratio,
    (sfSprite_getPosition(game->sprite->player).y
    - game->view.offset.y) * game->win.ratio};

    if ((player.x > (1323 * game->win.ratio) && player.x <
        (1571 * game->win.ratio)) || (game->var.quit_donjon == 0))
        if ((player.y > (117 * game->win.ratio) &&
        player.y < (190 * game->win.ratio)) || (game->var.quit_donjon == 0)) {
        game->var.quit_beach = 1;
        game->intro->fade = 2;
        game->intro->alpha = 0;
        management_donjon(game);
        sfView_reset(game->view.view, (sfFloatRect){0, 0, 1920, 1080});
        sfRenderWindow_setView(game->win.dow, game->view.view);
    }
}

void event_game_loop(game_t *game)
{
    enter_cave(game);
    while (sfRenderWindow_pollEvent(game->win.dow, &game->win.event)) {
        if (game->win.event.type == sfEvtClosed)
            sfRenderWindow_close(game->win.dow);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) &&
            !game->press.escape) {
            game->press.escape = true;
            pause_game_loop(game);
        }
        event_open_inventory(game);
        if (game->win.event.type == sfEvtKeyReleased &&
        game->win.event.key.code == sfKeyEscape && game->press.escape)
            game->press.escape = false;
    }
    event_move_mouse(game);
    event_spell(game);
}

void game_loop(game_t *game)
{
    create_game_loop(game);
    while (sfRenderWindow_isOpen(game->win.dow) && !game->var.quit_beach) {
        rand();
        event_game_loop(game);
        manage_rain_particle(game);
        manage_spell_projectile(game);
        manage_spell_particle(game);
        management_orientation_player(game);
        event_move(game);
        display_beach(game);
        display_spell_particle(game);
        display_rain_particle(game);
        print_inventory(game);
        sfRenderWindow_drawSprite(game->win.dow, game->sprite->cursor, NULL);
        check_pos_player_to_dialog(game);
        skip_text_dialog(game);
    }
    destroy_beach(game);
}
