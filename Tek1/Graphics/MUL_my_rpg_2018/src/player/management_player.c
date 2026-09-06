/*
** EPITECH PROJECT, 2019
** management_player.c
** File description:
** managament action of player
*/

#include "my_rpg.h"

static char **managament_choose_map(game_t *game, int map, sfVector2f *posi)
{
    switch (map) {
        case 0: (*posi).x = 14.1 * game->win.ratio;
            (*posi).y = 12 * game->win.ratio;
            return (game->map.beach);
        default: return (NULL);
    }
    return (NULL);
}

static int control_result(char **map, int x, int y)
{
    int size_cols = 0;
    int size_line = 0;

    if (map == NULL)
        return (84);
    for (; map[size_line] != NULL; size_line++) {
    }
    if (y > size_line || y < 0)
        return (84);
    for (; map[y][size_cols]; size_cols++) {
    }
    if (x > size_cols || x < 0)
        return (84);
    return (0);
}

int check_move_perso(game_t *game, sfVector2f perso, int cas)
{
    sfVector2f posi = {0, 0};
    char **map = managament_choose_map(game, cas, &posi);
    int x = 0;
    int y = 0;

    if (map == NULL)
        return (0);
    for (; posi.x * x + posi.x < perso.x; x++) {
    }
    for (; posi.y * y + posi.y < perso.y; y++) {
    }
    if (control_result(map, x, y) == 84) {
        return (1);
    }
    if (map[y][x] == '0')
        return (0);
    else
        return (1);
    return (0);
}

static sfVector2f player_position_get(game_t *game, int cas)
{
    sfVector2f posi = sfSprite_getPosition(game->sprite->player);

    switch (cas) {
        case 1: posi.y += -2 * game->win.ratio;
            return (posi);
        case 2: posi.y += 2 * game->win.ratio;
            return (posi);
        case 3: posi.x += -2 * game->win.ratio;
            return (posi);
        case 4: posi.x += 2 * game->win.ratio;
            return (posi);
    }
    return (posi);
}

int control_move_player(game_t *game, int cas)
{
    sfVector2f posi = player_position_get(game, cas);

    if (game->var.level > 0)
        return (management_hitbox_donjon(game, posi));
    if (check_move_perso(game, posi, game->var.level) == 1)
        return (0);
    if (check_move_perso(game, (sfVector2f){posi.x + game->rect.player.width,
        posi.y}, game->var.level) == 1)
        return (0);
    if (check_move_perso(game, (sfVector2f){posi.x + game->rect.player.width,
        posi.y + game->rect.player.height}, game->var.level) == 1)
        return (0);
    if (check_move_perso(game, (sfVector2f){posi.x +(game->rect.player.width
        / 2), posi.y + (game->rect.player.height / 2)}, game->var.level) == 1)
        return (0);
    if (check_move_perso(game, (sfVector2f){posi.x, posi.y +
        game->rect.player.height}, game->var.level) == 1)
        return (0);
    game->var.move = 1;
    return (1);
}
