/*
** EPITECH PROJECT, 2019
** create_donjon.c
** File description:
** create_donjon
*/

#include "my_rpg.h"

static void create_sprite_donjon(game_t *game)
{
    game->sprite->donjon = sfSprite_create();
    game->sprite->donjon_shader = sfSprite_create();
    game->sprite->donjon_torch = sfSprite_create();
    game->sprite->donjon_wall = sfSprite_create();
    game->sprite->eye = sfSprite_create();
    game->sprite->eye_bomb = sfSprite_create();
    game->sprite->spider = sfSprite_create();
    game->sprite->evil_tick = sfSprite_create();
    game->texture->donjon =
    sfTexture_createFromFile("assets/img/map/donjon.png", NULL);
    game->texture->donjon_shader =
    sfTexture_createFromFile("assets/img/map/donjon_shader.png", NULL);
    game->texture->donjon_torch =
    sfTexture_createFromFile("assets/img/map/donjon_torch.png", NULL);
    game->texture->donjon_wall =
    sfTexture_createFromFile("assets/img/map/donjon_wall.png", NULL);
    game->texture->eye =
    sfTexture_createFromFile("assets/img/enemy/eye_1_small.png", NULL);
    game->texture->eye_bomb =
    sfTexture_createFromFile("assets/img/enemy/eye_1_bomb.png", NULL);
}

static void create_texture_donjon(game_t *game)
{
    game->texture->spider =
    sfTexture_createFromFile("assets/img/enemy/spider_1.png", NULL);
    game->texture->evil_tick =
    sfTexture_createFromFile("assets/img/enemy/tick_2.png", NULL);
    sfSprite_setTexture(game->sprite->donjon,
    game->texture->donjon, sfTrue);
    sfSprite_setTexture(game->sprite->donjon_shader,
    game->texture->donjon_shader, sfTrue);
    sfSprite_setTexture(game->sprite->donjon_torch,
    game->texture->donjon_torch, sfTrue);
    sfSprite_setTexture(game->sprite->donjon_wall,
    game->texture->donjon_wall, sfTrue);
    sfSprite_setTexture(game->sprite->eye,
    game->texture->eye, sfTrue);
    sfSprite_setTexture(game->sprite->eye_bomb,
    game->texture->eye_bomb, sfTrue);
    sfSprite_setTexture(game->sprite->spider,
    game->texture->spider, sfTrue);
    sfSprite_setTexture(game->sprite->evil_tick,
    game->texture->evil_tick, sfTrue);
}

static void rect_texture_donjon(game_t *game)
{
    game->rect.donjon_torch = (sfIntRect){0, 0, 2385, 2062};
    sfSprite_setTextureRect(game->sprite->donjon_torch,
    game->rect.donjon_torch);
    game->clock->donjon_torch = sfClock_create();
    game->clock->enemy_manage = sfClock_create();
    game->player.clock_time_score = sfClock_create();
    game->clock->flesh_sound = sfClock_create();
    if (game->var.quit_donjon != 0) {
        game->player.status = 1;
        game->player.hp = game->var.player_hp;
        game->player.mana = game->var.player_mana;
        game->player.xp = 0;
        game->player.gold = 0;
        game->var.score = 0;
        game->var.kill = 0;
        game->var.time = 0;
        game->player.rect_x = 0;
        game->var.potion = 93;
        game->player.rect_y = 1;
    }
}

static void create_dungeon2(game_t *game)
{
    create_sprite_of_skill(game);
    create_items(game);
    create_skill(game);
    create_sprite_donjon(game);
    create_donjon_other_things(game);
    create_texture_donjon(game);
    rect_texture_donjon(game);
    create_hud(game);
    create_dungeon_enemy(game);
    create_dungeon_boss(game);
    create_dungeon_sound(game);
}

void create_donjon(game_t *game)
{
    game->var.level += 1;
    reset_dungeon_view(game);
    create_dungeon2(game);
    game->var.quit_donjon = 0;
    create_donjon_two(game);
}
