/*
** EPITECH PROJECT, 2019
** create_background
** File description:
** Creation of the background
*/

#include "my_rpg.h"

void create_sprite_main_menu(game_t *game)
{
    game->sprite->menu = sfSprite_create();
    game->sprite->play1_menu = sfSprite_create();
    game->sprite->play2_menu = sfSprite_create();
    game->sprite->set1_menu = sfSprite_create();
    game->sprite->set2_menu = sfSprite_create();
    game->sprite->htp1_menu = sfSprite_create();
    game->sprite->htp2_menu = sfSprite_create();
    game->sprite->exit1_menu = sfSprite_create();
    game->sprite->exit2_menu = sfSprite_create();
    game->sprite->high_score1_menu = sfSprite_create();
    game->sprite->high_score2_menu = sfSprite_create();
    game->sprite->hud_menu = sfSprite_create();
    game->sprite->logo = sfSprite_create();
}

void create_texture_menu(game_t *game)
{
    game->texture->exit2_menu =
    sfTexture_createFromFile("assets/img/menu/exit2.png", NULL);
    game->texture->high_score1_menu =
    sfTexture_createFromFile("assets/img/menu/high_score_1.png", NULL);
    game->texture->high_score2_menu =
    sfTexture_createFromFile("assets/img/menu/high_score_2.png", NULL);
    game->texture->hud_menu =
    sfTexture_createFromFile("assets/img/menu/menu_hud.png", NULL);
    game->texture->logo =
    sfTexture_createFromFile("assets/img/other/logo.png", NULL);
}

void create_texture_main_menu(game_t *game)
{
    game->texture->menu =
    sfTexture_createFromFile("assets/img/menu/back.png", NULL);
    game->texture->play1_menu =
    sfTexture_createFromFile("assets/img/menu/jouer1.png", NULL);
    game->texture->play2_menu =
    sfTexture_createFromFile("assets/img/menu/jouer2.png", NULL);
    game->texture->set1_menu =
    sfTexture_createFromFile("assets/img/menu/set.png", NULL);
    game->texture->set2_menu =
    sfTexture_createFromFile("assets/img/menu/set2.png", NULL);
    game->texture->htp1_menu =
    sfTexture_createFromFile("assets/img/menu/htp1.png", NULL);
    game->texture->htp2_menu =
    sfTexture_createFromFile("assets/img/menu/htp2.png", NULL);
    game->texture->exit1_menu =
    sfTexture_createFromFile("assets/img/menu/exit1.png", NULL);
    create_texture_menu(game);
}

void is_extension_initialize_menu_vars(game_t *game)
{
    game->press.click = false;
    game->press.rightclick = false;
    game->menu_particle = NULL;
    game->press.escape = false;
    game->var.score_of_file = 0;
    game->var.time_of_file = 0;
    game->var.kill_of_file = 0;
    game->item = NULL;
    game->skill = NULL;
}

void initialize_menu_vars(game_t *game)
{
    is_extension_initialize_menu_vars(game);
    game->clock->particle = sfClock_create();
    game->clock->anim = sfClock_create();
    add_particle(game, MENU_PARTICLE_NUMBER);
    game->particle->rectangle = sfRectangleShape_create();
    sfRectangleShape_setFillColor(game->particle->rectangle,
    sfColor_fromRGBA(190, 60, 60, 255));
    sfRenderWindow_setMouseCursorVisible(game->win.dow, sfFalse);
    game->music->menu = sfMusic_createFromFile("assets/sound/main_theme.ogg");
    sfMusic_play(game->music->menu);
    sfMusic_setLoop(game->music->menu, sfTrue);
}
