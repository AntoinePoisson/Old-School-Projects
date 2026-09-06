/*
** EPITECH PROJECT, 2019
** display_highscore.c
** File description:
** display_highscore.c
*/

#include "my_rpg.h"

static void take_data_of_file(game_t *game)
{
    static int i = 0;

    if (i == 0) {
        management_highscore(game, 0);
        i = 1;
    }
}

static void display_highscore_text(game_t *game, sfText *sf_text)
{
    char *time = my_strcat("Time : ", my_itoa(game->var.time_of_file, 0));
    char *kill = my_strcat("Kill : ", my_itoa(game->var.kill_of_file, 0));

    sfText_setString(sf_text, time);
    sfText_setPosition(sf_text, (sfVector2f){750 * game->win.ratio,
    600 * game->win.ratio});
    sfRenderWindow_drawText(game->win.dow, sf_text, NULL);
    sfText_setString(sf_text, kill);
    sfText_setPosition(sf_text, (sfVector2f){750 * game->win.ratio,
    750 * game->win.ratio});
    sfText_setColor(sf_text, sfColor_fromRGB(255, 219, 38));
    sfRenderWindow_drawText(game->win.dow, sf_text, NULL);
    free(time);
    free(kill);
}

void display_highscore(game_t *game)
{
    char *score = my_strcat("Score : ", my_itoa(game->var.score_of_file, 0));
    sfText *sf_text = sfText_create();
    sfFont *sf_font = sfFont_createFromFile("assets/font/game.ttf");

    take_data_of_file(game);
    sfText_setFont(sf_text, sf_font);
    sfText_setCharacterSize(sf_text, 40);
    sfText_setString(sf_text, score);
    sfText_setPosition(sf_text, (sfVector2f){750 * game->win.ratio,
    450 * game->win.ratio});
    sfText_setColor(sf_text, sfColor_fromRGB(255, 219, 38));
    sfRenderWindow_drawText(game->win.dow, sf_text, NULL);
    display_highscore_text(game, sf_text);
    sfFont_destroy(sf_font);
    sfText_destroy(sf_text);
    free(score);
}