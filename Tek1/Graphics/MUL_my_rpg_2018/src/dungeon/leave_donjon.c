/*
** EPITECH PROJECT, 2018
** leave_donjon.c
** File description:
** leave_donjon
*/

#include "my_rpg.h"

int check_leave_donjon(game_t *game)
{
    int count = 0;
    sfVector2f posi = sfSprite_getPosition(game->sprite->player);

    for (item_t *save = game->item; save && save->f; save = save->next,
        count++);
    if (count == 7 && game->var.go_to_end)
        return (1);
    if (posi.x >= 1263 * 4.2 && posi.x <= 1361 * 4.2 && posi.y >= 1508
        * 4.2 && posi.y <= 1567 * 4.2)
        return (1);
    if (game->player.hp <= 0)
        return (1);
    return (0);
}

void end_transition(game_t *game, sfSprite *sprite, int cas)
{
    sfIntRect rect = (sfIntRect){0, 0, 1600, 900};

    for (int i = 19 + cas; i;) {
        if (sfClock_getElapsedTime(game->clock->end_game).microseconds
            / 1000000.0 >= 0.042) {
            sfSprite_setTextureRect(sprite, rect);
            sfRenderWindow_drawSprite(game->win.dow, sprite, NULL);
            if (!(i == 19 && cas == 1))
                sfRenderWindow_display(game->win.dow);
            rect.left += 1600;
            if (rect.left >= 8000) {
                rect.left = 0;
                rect.top += 900;
            }
            i -= 1;
            sfClock_restart(game->clock->end_game);
        }
    }
    display_text_end_game(game);
}

void delete_backup(void)
{
    int fd = open(".safe", O_CREAT | O_RDWR | O_TRUNC);

    if (fd != -1)
        close(fd);
}

void leave_donjon(game_t *game)
{
    int count = 0;
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture =
    sfTexture_createFromFile("assets/img/other/end_game.png", NULL);

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){1.2, 1.3});
    sfSprite_setPosition(sprite, (sfVector2f){
        sfView_getCenter(game->view.view).x - 960,
        sfView_getCenter(game->view.view).y - 540});
    game->clock->end_game = sfClock_create();
    game->var.quit_donjon = 1;
    for (item_t *s = game->item; s && s->f; s = s->next, count++);
    if (game->player.hp <= 0 || count != 7)
        end_transition(game, sprite, 0);
    else
        end_transition(game, sprite, 1);
    sfClock_destroy(game->clock->end_game);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    delete_backup();
}
