/*
** EPITECH PROJECT, 2019
** display_donjon.c
** File description:
** display_donjon
*/

#include "my_rpg.h"

void is_extension_display_donjon_torch(game_t *game, int *cas)
{
    game->rect.donjon_torch.left -= 2385;
    if (game->rect.donjon_torch.top > 0 &&
        game->rect.donjon_torch.left <= 0) {
        game->rect.donjon_torch.left = 2385;
        game->rect.donjon_torch.top = 0;
    }
    if (game->rect.donjon_torch.top <= 0 &&
        game->rect.donjon_torch.left <= 0) {
        game->rect.donjon_torch.top = 0;
        game->rect.donjon_torch.left = 0;
        *cas = 0;
    }
    sfSprite_setTextureRect(game->sprite->donjon_torch,
        game->rect.donjon_torch);
    sfClock_restart(game->clock->donjon_torch);
}

void display_donjon_torch(game_t *game)
{
    static int cas = 0;

    if (sfClock_getElapsedTime(game->clock->donjon_torch).microseconds
        > 150000) {
        if (cas == 1)
            return (is_extension_display_donjon_torch(game, &cas));
        game->rect.donjon_torch.left += 2385;
        if (game->rect.donjon_torch.left >= 4770) {
            game->rect.donjon_torch.left = 0;
            game->rect.donjon_torch.top += 2062;
        }
        if (game->rect.donjon_torch.top >= 4124) {
            game->rect.donjon_torch.top = 2062;
            game->rect.donjon_torch.left = 0;
            cas = 1;
        }
        sfSprite_setTextureRect(game->sprite->donjon_torch,
            game->rect.donjon_torch);
        sfClock_restart(game->clock->donjon_torch);
    }
}

void display_dungeon(game_t *game)
{
    sfRenderWindow_drawSprite(game->win.dow,
    game->sprite->donjon_shader, NULL);
    management_hud(game);
    if (game->var.disp_inventory)
        print_inventory(game);
    sfSprite_move(game->sprite->cursor, game->view.offset);
    if (game->intro->fade) {
        sfRectangleShape_setPosition(game->intro->rectangle, game->view.offset);
        sfRenderWindow_drawRectangleShape(game->win.dow,
        game->intro->rectangle, NULL);
    }
    if (game->boss.attack_status) {
        sfRectangleShape_setSize(game->boss.health_display,
        (sfVector2f){game->boss.health, 10});
        sfRectangleShape_setPosition(game->boss.health_display,
        (sfVector2f){700 / 2 + game->view.offset.x, 80 + game->view.offset.y});
        sfRenderWindow_drawRectangleShape(game->win.dow,
        game->boss.health_display, NULL);
    }
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->cursor, NULL);
}

void display_donjon(game_t *game)
{
    sfRenderWindow_clear(game->win.dow, sfColor_fromRGBA(11, 13, 16, 255));
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->donjon, NULL);
    management_item(game);
    display_spell_particle(game);
    display_boss_particle(game);
    display_enemy_eye_bomb(game);
    display_enemy_eye(game);
    display_enemy_spider(game);
    display_enemy_evil_tick(game);
    display_dungeon_boss(game);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->player, NULL);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->donjon_wall, NULL);
    display_donjon_torch(game);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->donjon_torch,
    NULL);
    display_dungeon(game);
    if (in_radius(sfSprite_getPosition(game->sprite->player),
    sfText_getPosition(game->boss.attempt_attack), 350) &&
    !game->boss.attack_status)
        sfRenderWindow_drawText(game->win.dow, game->boss.attempt_attack, NULL);
}
