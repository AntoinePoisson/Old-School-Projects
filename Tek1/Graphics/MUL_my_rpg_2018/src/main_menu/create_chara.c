/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** create perso
*/

#include "my_rpg.h"

static void create_texture_chara_menu(game_t *game)
{
    game->sprite->chara_menu_hud = sfSprite_create();
    game->sprite->chara_menu1 = sfSprite_create();
    game->sprite->chara_menu2 = sfSprite_create();
    game->sprite->chara_menu3 = sfSprite_create();
    game->sprite->chara_menu4 = sfSprite_create();
    game->sprite->chara_menu5 = sfSprite_create();
    game->texture->chara_menu_hud =
    sfTexture_createFromFile("assets/img/menu/chara_menu_hud.png", NULL);
    game->texture->chara_menu1 =
    sfTexture_createFromFile("assets/img/player_skin/knight_a.png", NULL);
    game->texture->chara_menu2 =
    sfTexture_createFromFile("assets/img/player_skin/priest_a.png", NULL);
    game->texture->chara_menu3 =
    sfTexture_createFromFile("assets/img/player_skin/sorcerer_a.png", NULL);
    game->texture->chara_menu4 =
    sfTexture_createFromFile("assets/img/player_skin/thief_a.png", NULL);
    game->texture->chara_menu5 =
    sfTexture_createFromFile("assets/img/player_skin/wizard_a.png", NULL);
}

void create_chara_main_menu(game_t *game)
{
    sfSprite_setScale(game->sprite->chara_menu3,
    (sfVector2f){15 * game->win.ratio, 15 * game->win.ratio});
    sfSprite_setScale(game->sprite->chara_menu4,
    (sfVector2f){15 * game->win.ratio, 15 * game->win.ratio});
    sfSprite_setScale(game->sprite->chara_menu5,
    (sfVector2f){15 * game->win.ratio, 15 * game->win.ratio});
    sfSprite_setTextureRect(game->sprite->chara_menu1, game->rect.knight_a);
    sfSprite_setTextureRect(game->sprite->chara_menu2, game->rect.priest_a);
    sfSprite_setTextureRect(game->sprite->chara_menu3, game->rect.sorcerer_a);
    sfSprite_setTextureRect(game->sprite->chara_menu4, game->rect.thief_a);
    sfSprite_setTextureRect(game->sprite->chara_menu5, game->rect.wizard_a);
}

void create_chara(game_t *game)
{
    sfSprite_setTexture(game->sprite->chara_menu5,
    game->texture->chara_menu5, sfTrue);
    sfSprite_setPosition(game->sprite->chara_menu_hud,
    (sfVector2f){240 * game->win.ratio, 100 * game->win.ratio});
    sfSprite_setPosition(game->sprite->chara_menu1,
    (sfVector2f){380 * game->win.ratio, 150 * game->win.ratio});
    sfSprite_setPosition(game->sprite->chara_menu2,
    (sfVector2f){808 * game->win.ratio, 150 * game->win.ratio});
    sfSprite_setPosition(game->sprite->chara_menu3,
    (sfVector2f){1258 * game->win.ratio, 150 * game->win.ratio});
    sfSprite_setPosition(game->sprite->chara_menu4,
    (sfVector2f){558 * game->win.ratio, 550 * game->win.ratio});
    sfSprite_setPosition(game->sprite->chara_menu5,
    (sfVector2f){1068 * game->win.ratio, 550 * game->win.ratio});
    sfSprite_setScale(game->sprite->chara_menu_hud,
    (sfVector2f){4 * game->win.ratio, 4 * game->win.ratio});
    sfSprite_setScale(game->sprite->chara_menu1,
    (sfVector2f){15 * game->win.ratio, 15 * game->win.ratio});
    sfSprite_setScale(game->sprite->chara_menu2,
    (sfVector2f){15 * game->win.ratio, 15 * game->win.ratio});
}

void create_chara_menu(game_t *game)
{
    create_text_chara_menu(game);
    create_texture_chara_menu(game);
    game->rect.knight_a = (sfIntRect){139, 0 , 17, 19};
    game->rect.priest_a = (sfIntRect){143, 0 , 15, 20};
    game->rect.sorcerer_a = (sfIntRect){142, 0 , 15, 20};
    game->rect.thief_a = (sfIntRect){138, 0 , 17, 20};
    game->rect.wizard_a = (sfIntRect){143, 0 , 15, 20};
    create_rectangle_shape_chara_menu(game);
    sfSprite_setTexture(game->sprite->chara_menu_hud,
    game->texture->chara_menu_hud, sfTrue);
    sfSprite_setTexture(game->sprite->chara_menu1,
    game->texture->chara_menu1, sfTrue);
    sfSprite_setTexture(game->sprite->chara_menu2,
    game->texture->chara_menu2, sfTrue);
    sfSprite_setTexture(game->sprite->chara_menu3,
    game->texture->chara_menu3, sfTrue);
    sfSprite_setTexture(game->sprite->chara_menu4,
    game->texture->chara_menu4, sfTrue);
    create_chara(game);
    create_chara_main_menu(game);
}
