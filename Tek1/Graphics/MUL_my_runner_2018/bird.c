/*
** EPITECH PROJECT, 2018
** bird
** File description:
** file of bird
*/

#include <stdlib.h>
#include "csfml.h"
#include "struct.h"

void display_bird(variable_t *sf)
{
    for (int i = 1; i < 3; i++) {
        if (sf->bird->position.x > -146) {
            sf->bird->position.x -= sf->var_norm.offset_bird;
            sfSprite_setPosition(sf->sprite.bird, sf->bird->position);
            if (sf->var_norm.slow_dino >= 3) {
                sf->bird->rect.left += 134;
                if (sf->bird->rect.left >= 268)
                    sf->bird->rect.left = 0;
                sfSprite_setTextureRect(sf->sprite.bird, sf->bird->rect);
            }
            sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.bird, NULL);
        }
        else {
            if (i != 1)
                i += 2;
            sf->bird->position.x =
                (rand() % ((2500 * i) - (1900 * i)) + 1900 * i) + 1600;
        }
        sf->bird = sf->bird->next;
    }
}

void do_circular_list_bird(variable_t *sf)
{
    list_bird_t *save = sf->bird;

    while (sf->bird->next != NULL)
        sf->bird = sf->bird->next;
    sf->bird->next = save;
}

void is_extension_create_bird(variable_t *sf)
{
    list_bird_t *bird = malloc(sizeof(*bird));

    sf->bird->next = NULL;
    bird->position.x = (rand() % (3500 - 3100) + 3100) + 1600;
    bird->position.y = 370;
    bird->rect.top = 0;
    bird->rect.left = 0;
    bird->rect.width = 134;
    bird->rect.height = 134;
    bird->next = sf->bird;
    sf->bird = bird;
    do_circular_list_bird(sf);
}

void create_bird(variable_t *sf)
{
    list_bird_t *bird = malloc(sizeof(*bird));
    sfTexture *Texture;
    sfSprite *Sprite = sfSprite_create();

    if (sf->var_norm.hitbox_mode == 0)
        Texture = sfTexture_createFromFile("./images/bird.png", NULL);
    else
        Texture = sfTexture_createFromFile("./images/hitbox_bird.png", NULL);
    sf->bird = bird;
    sf->sprite.bird = Sprite;
    sf->texture.bird = Texture;
    sf->var_norm.offset_bird = sf->var_norm.speed_background + 3;
    sf->bird->position.x = (rand() % (1000 - 500) + 500) + 1600;
    sf->bird->position.y = 540;
    sf->bird->rect.top = 0;
    sf->bird->rect.left = 0;
    sf->bird->rect.width = 134;
    sf->bird->rect.height = 134;
    is_extension_create_bird(sf);
    sfSprite_setTexture(sf->sprite.bird, sf->texture.bird, sfTrue);
}
