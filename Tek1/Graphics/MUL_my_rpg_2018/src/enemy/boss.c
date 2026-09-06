/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

#include "my_rpg.h"

void event_attack_boss(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyE) &&
    in_radius(sfSprite_getPosition(game->sprite->player),
    sfText_getPosition(game->boss.attempt_attack), 350) &&
    !game->boss.attack_status) {
        game->boss.attack_status = 1;
        sfClock_restart(game->boss.attack);
        if (!game->var.disp_music) {
            sfMusic_stop(game->music->dungeon_theme);
            sfMusic_play(game->music->boss_theme);
        }
    }
}

void display_dungeon_boss(game_t *game)
{
    sfSprite_setTextureRect(game->sprite->boss, game->boss.rect);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->boss, NULL);
}

void create_dungeon_boss_two(game_t *game)
{
    sfSprite_setPosition(game->sprite->boss,
    (sfVector2f){8200 * game->win.ratio, 2450 * game->win.ratio});
    game->boss.attempt_attack = sfText_create();
    sfText_setPosition(game->boss.attempt_attack, (sfVector2f)
    {8170 * game->win.ratio, 2450 * game->win.ratio});
    sfText_setString(game->boss.attempt_attack, "Press E to attack");
    sfText_setCharacterSize(game->boss.attempt_attack, 20);
    sfText_setFont(game->boss.attempt_attack, game->text.font_highscore);
    game->boss.health = 1200;
    game->boss.health_display = sfRectangleShape_create();
    sfRectangleShape_setFillColor(game->boss.health_display,
    sfColor_fromRGBA(0, 255, 0, 255));
    sfRectangleShape_setSize(game->boss.health_display,
    (sfVector2f){1200, 10});
    sfRectangleShape_setPosition(game->boss.health_display,
    (sfVector2f){820 / 2 + game->view.offset.x, 80 + game->view.offset.y});
}

void create_dungeon_boss(game_t *game)
{
    game->boss.attack_status = 0;
    game->boss.attack = sfClock_create();
    game->boss.anim = sfClock_create();
    game->sprite->boss = sfSprite_create();
    game->texture->boss =
    sfTexture_createFromFile("assets/img/enemy/boss.png", NULL);
    sfSprite_setTexture(game->sprite->boss, game->texture->boss, sfTrue);
    sfSprite_setScale(game->sprite->boss,
    (sfVector2f){2 * game->win.ratio, 2 * game->win.ratio});
    game->boss.rect = (sfIntRect){0, 0, 125, 125};
    create_dungeon_boss_two(game);
}

void manage_dungeon_boss(game_t *game)
{
    static float angle = 0;
    static bool change_pos = false;
    static short times = 0;

    manage_boss_projectile(game);
    manage_boss_particle(game);
    manage_boss_fireball(game, &change_pos, &angle, &times);
    manage_boss_spawn_enemies(game);
    if (game->boss.attack_status == 3 &&
        sfClock_getElapsedTime(game->boss.attack).microseconds >= 15000000)
        game->boss.attack_status = 2;
}
