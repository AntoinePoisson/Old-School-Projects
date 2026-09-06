/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** create menu
*/

#include "my_rpg.h"

void set_pos_scale(game_t *game)
{
    sfSprite_setScale(game->sprite->exit1_menu,
    (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
    sfSprite_setScale(game->sprite->exit2_menu,
    (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
    sfSprite_setScale(game->sprite->hud_menu,
    (sfVector2f){3 * game->win.ratio, 4.2 * game->win.ratio});
    sfSprite_setScale(game->sprite->logo,
    (sfVector2f){1.4 * game->win.ratio, 1.4 * game->win.ratio});
}

void set_pos_scale_menu(game_t *game)
{
    sfSprite_setScale(game->sprite->play2_menu,
    (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
    sfSprite_setScale(game->sprite->set1_menu,
    (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
    sfSprite_setScale(game->sprite->set2_menu,
    (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
    sfSprite_setScale(game->sprite->htp1_menu,
    (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
    sfSprite_setScale(game->sprite->htp2_menu,
    (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
    sfSprite_setScale(game->sprite->high_score1_menu,
    (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
    sfSprite_setScale(game->sprite->high_score2_menu,
    (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
    set_pos_scale(game);
}

void set_pos_scale_main_menu(game_t *game)
{
    sfSprite_setPosition(game->sprite->play1_menu,
    (sfVector2f){760 * game->win.ratio, 360 * game->win.ratio});
    sfSprite_setPosition(game->sprite->set1_menu,
    (sfVector2f){760 * game->win.ratio, 490 * game->win.ratio});
    sfSprite_setPosition(game->sprite->htp1_menu,
    (sfVector2f){760 * game->win.ratio, 620 * game->win.ratio});
    sfSprite_setPosition(game->sprite->high_score1_menu,
    (sfVector2f){760 * game->win.ratio, 750 * game->win.ratio});
    sfSprite_setPosition(game->sprite->exit1_menu,
    (sfVector2f){760 * game->win.ratio, 880 * game->win.ratio});
    sfSprite_setPosition(game->sprite->hud_menu,
    (sfVector2f){680 * game->win.ratio, 240 * game->win.ratio});
    sfSprite_setPosition(game->sprite->logo,
    (sfVector2f){715 * game->win.ratio, 275 * game->win.ratio});
    sfSprite_setScale(game->sprite->menu,
    (sfVector2f){game->win.ratio, game->win.ratio});
    sfSprite_setScale(game->sprite->play1_menu,
    (sfVector2f){5 * game->win.ratio, 5 * game->win.ratio});
    set_pos_scale_menu(game);
}

void create_menu(game_t *game)
{
    sfSprite_setTexture(game->sprite->htp2_menu,
    game->texture->htp2_menu, sfTrue);
    sfSprite_setTexture(game->sprite->high_score1_menu,
    game->texture->high_score1_menu, sfTrue);
    sfSprite_setTexture(game->sprite->high_score2_menu,
    game->texture->high_score2_menu, sfTrue);
    sfSprite_setTexture(game->sprite->exit1_menu,
    game->texture->exit1_menu, sfTrue);
    sfSprite_setTexture(game->sprite->exit2_menu,
    game->texture->exit2_menu, sfTrue);
    sfSprite_setTexture(game->sprite->hud_menu,
    game->texture->hud_menu, sfTrue);
    sfSprite_setTexture(game->sprite->logo, game->texture->logo, sfTrue);
}

int create_main_menu(game_t *game)
{
    initialize_menu_vars(game);
    create_sprite_main_menu(game);
    create_texture_main_menu(game);
    if (create_hitbox_map(game) == 84 || create_orientation_player(game) == 84)
        return (84);
    sfSprite_setTexture(game->sprite->menu, game->texture->menu, sfTrue);
    sfSprite_setTexture(game->sprite->play1_menu,
    game->texture->play1_menu, sfTrue);
    sfSprite_setTexture(game->sprite->play2_menu,
    game->texture->play2_menu, sfTrue);
    sfSprite_setTexture(game->sprite->set1_menu,
    game->texture->set1_menu, sfTrue);
    sfSprite_setTexture(game->sprite->set2_menu,
    game->texture->set2_menu, sfTrue);
    sfSprite_setTexture(game->sprite->htp1_menu,
    game->texture->htp1_menu, sfTrue);
    create_menu(game);
    return (0);
}
