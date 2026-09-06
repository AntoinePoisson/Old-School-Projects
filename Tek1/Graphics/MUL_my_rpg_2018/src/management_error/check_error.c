/*
** EPITECH PROJECT, 2019
** check_error.c
** File description:
** Check error
*/

#include "my_rpg.h"

int malloc_struct(game_t *game)
{
    if (game == NULL)
        return (84);
    if ((game->sprite = malloc(sizeof(sprite_t))) == NULL)
        return (84);
    if ((game->texture = malloc(sizeof(texture_t))) == NULL)
        return (84);
    if ((game->intro = malloc(sizeof(intro_t))) == NULL)
        return (84);
    if ((game->clock = malloc(sizeof(clocker_t))) == NULL)
        return (84);
    if ((game->music = malloc(sizeof(music_t))) == NULL)
        return (84);
    if ((game->particle = malloc(sizeof(particle_t))) == NULL)
        return (84);
    return (0);
}

int display_help(void)
{
    my_putstr("DESCRIPTION :\n");
    my_putstr("\t./my_rpg\t\t\t:  Launch game.\n");
    my_putstr("\t./my_rpg --hitbox\t\t:  Launch game with hitbox.\n");
    my_putstr("\t./my_rpg -h\t\t\t:  Show help.\n");
    my_putstr("USER INPUTS :\n");
    my_putstr("\tMouse\t\t: Turn the character.\n");
    my_putstr("\tKey_left or Q\t: go left.\n");
    my_putstr("\tKey_right or D\t: go right.\n");
    my_putstr("\tKey_up or Z\t: go up.\n");
    my_putstr("\tKey_down or S\t: go down.\n");
    my_putstr("\tEchap\t\t: Pause the game.\n");
    my_putstr("\tQ\t\t: To quit the pause game.\n");
    return (0);
}

int error_gestion(char **env)
{
    if (!env || !env[0])
        return (my_puterror("Environment not set\n"));
    return (0);
}

void create_window(game_t *game, bool fullscreen, int size)
{
    sfVideoMode screen;

    screen = (sfVideoMode){1920, 1080, 32};
    if (size == 1)
        game->win.ratio = 1;
    else if (size == 2) {
        game->win.ratio = 0.86666667;
        screen = (sfVideoMode){1664, 936, 32};
    } else {
        game->win.ratio = 0.66666667;
        screen = (sfVideoMode){1280, 720, 32};
    }
    game->win.dow = sfRenderWindow_create(screen,
    "my_rpg", ((fullscreen) ? sfFullscreen : 0) | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->win.dow, 60);
    sfRenderWindow_setVerticalSyncEnabled(game->win.dow, sfTrue);
}
