/*
** EPITECH PROJECT, 2019
** management_donjon.c
** File description:
** management_donjon
*/

#include "my_rpg.h"

void event_game_loop_donjon(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->win.dow, &game->win.event)) {
        if (game->win.event.type == sfEvtClosed)
            sfRenderWindow_close(game->win.dow);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) &&
            !game->press.escape) {
            game->press.escape = true;
            pause_game_donjon(game);
        }
        if (sfKeyboard_isKeyPressed(sfKeyA))
            use_potion(game);
        event_open_inventory(game);
        if (game->win.event.type == sfEvtKeyReleased &&
        game->win.event.key.code == sfKeyEscape && game->press.escape)
        game->press.escape = false;
    }
    event_move(game);
}

void management_intro_dungeon(game_t *game)
{
    sfRectangleShape_setPosition(game->intro->rectangle, game->view.offset);
    while (sfRenderWindow_isOpen(game->win.dow) && game->intro->fade == 2 &&
        game->var.quit_donjon != 0) {
        manage_fade(game, 10);
        sfRenderWindow_clear(game->win.dow, sfBlack);
        display_beach(game);
        display_spell_particle(game);
        display_rain_particle(game);
        sfRenderWindow_drawRectangleShape(game->win.dow,
        game->intro->rectangle, NULL);
        sfRenderWindow_display(game->win.dow);
    }
    sfMusic_stop(game->music->menu);
    sfMusic_stop(game->music->rain);
    game->intro->fade = 1;
    game->intro->alpha = 250;
    create_donjon(game);
}

void manage_donjon(game_t *game)
{
    if (game->intro->fade)
        manage_fade(game, 10);
    if (sfClock_getElapsedTime(game->clock->enemy_manage)
        .microseconds > 25000) {
        manage_enemy_eye(game);
        manage_enemy_eye_bomb(game);
        manage_enemy_spider(game);
        manage_enemy_evil_tick(game);
        game->var.time = sfClock_getElapsedTime(game->player.clock_time_score)
        .microseconds / 1000000.0;
        sfClock_restart(game->clock->enemy_manage);
    }
    display_donjon(game);
    sfRenderWindow_display(game->win.dow);
    manage_dungeon_boss(game);
    management_regeneration(game);
    check_actual_posi_player(game);
}

void management_donjon(game_t *game)
{
    management_intro_dungeon(game);
    while (sfRenderWindow_isOpen(game->win.dow) && !game->var.quit_donjon) {
        event_game_loop_donjon(game);
        event_move_mouse(game);
        event_spell(game);
        event_hand_to_hand(game);
        event_attack_boss(game);
        manage_spell_particle(game);
        manage_spell_projectile(game);
        management_orientation_player(game);
        set_pos_text_stats(game);
        manage_donjon(game);
        check_choose_skill(game);
        if (check_leave_donjon(game))
            leave_donjon(game);
    }
    destroy_donjon(game);
}
