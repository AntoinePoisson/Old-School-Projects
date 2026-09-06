/*
** EPITECH PROJECT, 2019
** create_skill.c
** File description:
** create skill
*/

#include "my_rpg.h"

char *different_text_of_skill(int nbr)
{
    switch (nbr) {
        case 1: return ("Recover HP And Mana");
        case 2: return ("More HP");
        case 3: return ("More Mana");
        case 4: return ("More Armor");
        case 5: return ("Regeneration faster mana");
        case 6: return ("Regeneration faster hp");
        case 7: return ("Deal more dmg on mobs");
        case 8: return ("Delete dmg of trap");
        case 9: return ("Gain faster XP");
        case 10: return ("Restores 5 potions");
        case 11: return ("Need less items to win");
    }
    return ("Error");
}

void create_sprite_of_skill(game_t *game)
{
    game->sprite->skill = sfSprite_create();
    game->texture->skill =
    sfTexture_createFromFile("assets/img/other/skill.png", NULL);
    sfSprite_setTexture(game->sprite->skill,
    game->texture->skill, sfTrue);
}

void add_node_skill(game_t *game, int nbr)
{
    skill_t *new = malloc(sizeof(*new));

    if (!new)
        return;
    new->choose = 0;
    new->number = nbr;
    new->text = different_text_of_skill(nbr);
    new->rect.top = 96 * nbr - 96;
    new->rect.left = 0;
    new->rect.width = 96;
    new->rect.height = 96;
    new->next = game->skill;
    game->skill = new;
}

void create_skill(game_t *game)
{
    for (int i = 11; i > 0; i--)
        add_node_skill(game, i);
}
