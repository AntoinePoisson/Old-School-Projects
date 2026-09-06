/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

#include "my_rpg.h"

bool check_close_combat_collision(game_t *game)
{
    sfVector2f player_pos = sfSprite_getPosition(game->sprite->player);

    if (check_combat_eye(game, player_pos))
        return (false);
    if (check_combat_spider(game, player_pos))
        return (false);
    if (check_combat_evil_tick(game, player_pos))
        return (false);
    if (check_combat_boss(game, player_pos))
        return (false);
    play_sword_sound(game, false);
    return (false);
}

void event_hand_to_hand(game_t *game)
{
    if (game->win.event.type == sfEvtMouseButtonPressed &&
        game->win.event.mouseButton.button == sfMouseLeft &&
        game->press.click == false) {
        game->press.click = true;
        check_close_combat_collision(game);
        game->player.attack = 6;
    }
    if (game->win.event.type == sfEvtMouseButtonReleased &&
        game->win.event.mouseButton.button == sfMouseLeft &&
        game->press.click == true) {
        game->press.click = false;
    }
}
