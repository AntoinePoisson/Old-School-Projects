/*
** EPITECH PROJECT, 2019
** management_skill.c
** File description:
** management skill
*/

#include "my_rpg.h"

int research_skill(game_t *game, int element)
{
    if (game->var.slot_skill_one == element ||
        game->var.slot_skill_two == element ||
        game->var.slot_skill_three == element ||
        game->var.slot_skill_four == element)
        return (1);
    return (0);
}

void management_skill(game_t *game, int nbr)
{
    if (research_skill(game, nbr) == 0)
        return;
    switch (nbr) {
        case 1: return (resusite_player(game, nbr));
        case 2: return (more_hp(game, nbr));
        case 3: return (more_mana(game, nbr));
        case 4: return (more_armor(game, nbr));
        case 5: return (incremente_mana(game, nbr));
        case 6: return (incremente_hp(game, nbr));
        case 7: return (deal_more_dmg(game, nbr));
        case 9: return (gain_more_xp(game, nbr));
        case 10: return (restaure_potion(game, nbr));
        case 11: return (go_to_the_end(game, nbr));
    }
}