/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rpg
*/

#include "my_rpg.h"

char *write_text_end_game(game_t *game, int cas)
{
    char *result = NULL;
    char *two = "           ";

    if (cas == 1) {
        result = my_strcat("Score :   ", my_itoa(game->var.score, 0));
        two = my_strcat(two, my_itoa(game->var.score_of_file, 0));
        return (my_strcat(result, two));
    }
    if (cas == 2) {
        result = my_strcat("Kill :   ", my_itoa(game->var.kill, 0));
        two = my_strcat("              ", my_itoa(game->var.kill_of_file, 0));
        return (my_strcat(result, two));
    } else if (cas == 3) {
        result = my_strcat("Time :   ", my_itoa(game->var.time, 0));
        two = my_strcat("              ", my_itoa(game->var.time_of_file, 0));
        return (my_strcat(result, two));
    } else {
        result = my_strcat("Items : ", my_itoa(cas * -1, 0));
        return (my_strcat(result, " / 7"));
    }
}

void is_extension_display_text_end_game(game_t *game, sfVector2f view,
sfText *sf_text)
{
    int i = 0;
    int count = 0;

    sfText_setString(sf_text, write_text_end_game(game, 3));
    sfText_setPosition(sf_text, (sfVector2f){view.x - 235, view.y + 395});
    sfRenderWindow_drawText(game->win.dow, sf_text, NULL);
    for (item_t *s = game->item; s; s = s->next, i += 1)
        if (s->f) {
            count++;
            s->rect.top = 148;
            sfSprite_setTextureRect(game->sprite->item, s->rect);
            sfSprite_setPosition(game->sprite->item, (sfVector2f){
            view.x - 410 * game->win.ratio + i * 140, view.y + 458});
            sfRenderWindow_drawSprite(game->win.dow, game->sprite->item, NULL);
            s->rect.top = -35;
        }
    sfText_setString(sf_text, write_text_end_game(game, count * -1));
    sfText_setPosition(sf_text, (sfVector2f){view.x - 710, view.y + 480});
    sfRenderWindow_drawText(game->win.dow, sf_text, NULL);
    sfRenderWindow_display(game->win.dow);
}

void display_text_end_game(game_t *game)
{
    sfVector2f view = sfView_getCenter(game->view.view);
    sfText *sf_text = sfText_create();
    sfFont *sf_font = sfFont_createFromFile("assets/font/game.ttf");

    management_highscore(game, 0);
    sfText_setFont(sf_text, sf_font);
    sfText_setCharacterSize(sf_text, 30);
    sfText_setString(sf_text, write_text_end_game(game, 1));
    sfText_setPosition(sf_text, (sfVector2f){view.x - 235 * game->win.ratio,
    view.y + 95 * game->win.ratio});
    sfRenderWindow_drawText(game->win.dow, sf_text, NULL);
    sfText_setString(sf_text, write_text_end_game(game, 2));
    sfText_setPosition(sf_text, (sfVector2f){view.x - 235 * game->win.ratio,
    view.y + 235 * game->win.ratio});
    sfRenderWindow_drawText(game->win.dow, sf_text, NULL);
    is_extension_display_text_end_game(game, view, sf_text);
    management_highscore(game, 1);
    sfFont_destroy(sf_font);
    sfText_destroy(sf_text);
    sfSleep(sfSeconds(5.0));
}
