/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** create a custom rpg
*/

#include "my_rpg.h"

void free_main_functions(game_t *game)
{
    free(game->intro);
    free(game->texture);
    free(game->sprite);
    free(game->clock);
    free(game->music);
    free(game->particle);
}

int main(int ac, char **av, char **env)
{
    game_t *game = malloc(sizeof(game_t));

    if (malloc_struct(game) == 84)
        return (84);
    if (error_gestion(env) == 84)
        return (84);
    if (ac == 2 && !my_strcmp(av[1], "-h"))
        return (display_help());
    if (ac == 1)
        create_window(game, true, 1);
    else
        create_window(game, false, my_atoi(av[1]));
    if (main_menu(game) == 84)
        return (84);
    free_main_functions(game);
    free(game);
    return (0);
}
