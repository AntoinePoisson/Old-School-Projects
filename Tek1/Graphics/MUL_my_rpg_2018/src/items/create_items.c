/*
** EPITECH PROJECT, 2019
** create_items.c
** File description:
** create_items
*/

#include "my_rpg.h"

static sfVector2f calcul_vector_(int cas)
{
    switch (cas) {
    case -1: return ((sfVector2f){695 * 4.2 , 1238 * 4.2});
    case -2: return ((sfVector2f){1484 * 4.2, 528 * 4.2});
    case -3: return ((sfVector2f){2000 * 4.2, 754 * 4.2});
    case -4: return ((sfVector2f){1760 * 4.2, 1734 * 4.2});
    case -5: return ((sfVector2f){1300 * 4.2, 1930 * 4.2});
    case -6: return ((sfVector2f){1330 * 4.2, 1340 * 4.2});
    case -7: return ((sfVector2f){1212 * 4.2, 2199 * 4.2});
    }
    return ((sfVector2f){-60, -60});
}

static sfIntRect value_rect_(int cas)
{
    sfIntRect r;

    switch (cas) {
        case 1: r = ((sfIntRect){0, 0, 35, 35});
            break;
        case 2: r = ((sfIntRect){35, 0, 35, 35});
            break;
        case 3: r = ((sfIntRect){70, 0, 35, 35});
            break;
        case 4: r = ((sfIntRect){105, 0, 35, 35});
            break;
        case 5: r = ((sfIntRect){140, 0, 35, 35});
            break;
        case 6: r = ((sfIntRect){175, 0, 35, 35});
            break;
        case 7: r = ((sfIntRect){210, 0, 35, 35});
            break;
    }
    return (r);
}

void add_node(game_t *game, int cas)
{
    item_t *new = malloc(sizeof(*new));

    if (new == NULL)
        return;
    new->f = 0;
    new->clock = sfClock_create();
    new->posi = calcul_vector_(cas * -1);
    new->rect = value_rect_(cas);
    new->next = game->item;
    game->item = new;
}

void management_item(game_t *game)
{
    sfVector2f posi = sfSprite_getPosition(game->sprite->player);

    for (item_t *s = game->item; s &&
        sfRenderWindow_isOpen(game->win.dow); s = s->next) {
        if (posi.x >= s->posi.x && posi.y >= s->posi.y &&
            posi.x <= s->posi.x + 69 && posi.y <= s->posi.y + 69) {
            s->f = 1;
            s->rect.top = -35;
        }
        if (!s->f && sfClock_getElapsedTime(s->clock).microseconds > 400000) {
            s->rect.top += 35;
            if (s->rect.top > 113)
                s->rect.top = 0;
            sfClock_restart(s->clock);
        }
        sfSprite_setTextureRect(game->sprite->item, s->rect);
        sfSprite_setPosition(game->sprite->item, s->posi);
        sfRenderWindow_drawSprite(game->win.dow, game->sprite->item, NULL);
    }
}

void create_items(game_t *game)
{
    game->item = NULL;
    game->sprite->item = sfSprite_create();
    game->texture->item =
    sfTexture_createFromFile("assets/img/other/item.png", NULL);
    sfSprite_setTexture(game->sprite->item, game->texture->item, sfTrue);
    add_node(game, 5);
    add_node(game, 4);
    add_node(game, 2);
    add_node(game, 1);
    add_node(game, 3);
    add_node(game, 7);
    add_node(game, 6);
}
