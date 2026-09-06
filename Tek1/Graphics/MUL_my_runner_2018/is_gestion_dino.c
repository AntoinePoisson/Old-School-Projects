/*
** EPITECH PROJECT, 2018
** is_runner
** File description:
** file of runner
*/

#include "csfml.h"
#include "struct.h"

void display(variable_t *sf);

void is_extension_create_dino(variable_t *sf);

void create_dino(variable_t *sf)
{
    sfSprite *Sprite = sfSprite_create();
    sfTexture *Texture;

    if (sf->var_norm.hitbox_mode == 0)
        Texture = sfTexture_createFromFile("./images/dino.png", NULL);
    else
        Texture = sfTexture_createFromFile("./images/hitbox_dino.png", NULL);
    sfSprite_setTexture(Sprite, Texture, sfTrue);
    sf->sprite.dino = Sprite;
    sf->texture.dino = Texture;
    is_extension_create_dino(sf);
    sfSprite_setTextureRect(sf->sprite.dino, sf->rect.dino);
    sfSprite_setPosition(sf->sprite.dino, sf->vector.dino);
}

void is_extension_gestion_dino(variable_t *sf)
{
    if (sf->var_norm.dino_jump == 1 && sf->vector.dino.y <= 300) {
        sf->var_norm.dino_jump -= 1;
        sf->var_norm.dino_sinus *= -1;
    }
    if (sf->var_norm.dino_jump != 0) {
        sf->vector.dino.y -= 30;
        sf->var_norm.dino_sinus += 0.7;
    }
    if (sf->var_norm.dino_jump <= 0) {
        if (sf->vector.dino.y < 638) {
            sf->vector.dino.y += 33;
            sf->var_norm.dino_sinus += 0.8;
        }
        if (sf->vector.dino.y > 638) {
            sf->vector.dino.y = 638;
            sf->var_norm.dino_sinus = 0;
        }
    }
}

void gestion_dino(variable_t *sf)
{
    if (sf->var_norm.slow_dino >= 3) {
        sf->rect.dino.left += sf->var_norm.offset_dino;
        if (sf->rect.dino.left >= 511)
            sf->rect.dino.left = 256;
        sfSprite_setTextureRect(sf->sprite.dino, sf->rect.dino);
        sf->var_norm.slow_dino = 0;
    }
    else {
        sf->var_norm.slow_dino += 1;
    }
    if (sf->var_norm.dino_jump != 0 || sf->vector.dino.y != 638) {
        is_extension_gestion_dino(sf);
        sf->vector.dino.y += sf->var_norm.dino_sinus;
        sf->rect.dino.left = 0;
        sfSprite_setTextureRect(sf->sprite.dino, sf->rect.dino);
        sf->rect.dino.left = 256;
        sfSprite_setPosition(sf->sprite.dino, sf->vector.dino);
    }
}

int gestion_acceleration_bg(int modulo)
{
    if (modulo == 9)
        return (0);
    if (modulo == 8)
        return (10);
    if (modulo == 7)
        return (20);
    if (modulo == 6)
        return (30);
    if (modulo == 5)
        return (30);
    if (modulo == 4)
        return (40);
    if (modulo == 3)
        return (0);
    if (modulo == 2)
        return (65);
    if (modulo == 1)
        return (100);
    return (0);
}

void dino_move_speed(variable_t *sf)
{
    sf->var_norm.speed_background += 50;
    sf->var_norm.offset_bird = sf->var_norm.speed_background + 3;
    sfSprite_setPosition(sf->sprite.dino, sf->vector.dino);
    gestion_dino(sf);
    display(sf);
    sf->var_norm.speed_background -= 50;
    sf->var_norm.offset_bird = sf->var_norm.speed_background + 3;
    sfClock_restart(sf->clock.game);
}
