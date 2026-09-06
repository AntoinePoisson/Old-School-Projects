/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** create a custom rpg
*/

#include "my_rpg.h"

void main_menu_bis(game_t *game)
{
    event_move_mouse(game);
    click_buttons_main_menu(game);
    draw_main_menu(game);
    draw_buttons_main_menu(game);
    sfRenderWindow_drawRectangleShape(game->win.dow,
    game->intro->rectangle, NULL);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->cursor, NULL);
    display_particle(game);
    sfRenderWindow_display(game->win.dow);
    sfRenderWindow_clear(game->win.dow, sfBlack);
}

int main_menu(game_t *game)
{
    init_struct(game);
    if (create_main_menu(game) == 84)
        return (84);
    intro_menu(game);
    while (sfRenderWindow_isOpen(game->win.dow)) {
        event_menu(game);
        manage_fade(game, 2);
        set_pos_scale_main_menu(game);
        if (sfClock_getElapsedTime(game->clock->particle).microseconds
        >= 30000) {
            manage_particle(game);
            sfClock_restart(game->clock->particle);
        }
        main_menu_bis(game);
    }
    destroy_main_menu(game);
    return (0);
}
