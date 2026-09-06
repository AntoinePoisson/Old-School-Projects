/*
** EPITECH PROJECT, 2019
** choose_skill.c
** File description:
** choose skill
*/

#include "my_rpg.h"

void fill_struct_skill(game_t *game, skill_t *result)
{
    if (game->var.slot_skill_one == 20){
        game->var.slot_skill_one = result->number;
        return;
    }
    if (game->var.slot_skill_two == 20){
        game->var.slot_skill_two = result->number;
        return;
    }
    if (game->var.slot_skill_three == 20){
        game->var.slot_skill_three = result->number;
        return;
    }
    if (game->var.slot_skill_four == 20){
        game->var.slot_skill_four = result->number;
        return;
    }
}

void make_choose(game_t *game)
{
    skill_t *one = random_skill_(game);
    skill_t *two = random_skill_(game);
    int choose = -1;

    if (one == NULL || two == NULL)
        return (make_choose(game));
    while (sfRenderWindow_isOpen(game->win.dow) && choose < 0) {
        display_skill_tree(game, one, two);
        player_input(game, &choose);
    }
    sfRenderWindow_setMouseCursorVisible(game->win.dow, 0);
    if (choose == 1) {
        fill_struct_skill(game, one);
        management_skill(game, one->number);
    }
    if (choose == 2) {
        fill_struct_skill(game, two);
        management_skill(game, two->number);
    }
}

void transition_game_to_skill(game_t *game, sfSprite *sprite)
{
    sfIntRect rect = (sfIntRect){0, 0, 1600, 900};

    for (int i = 17; i;) {
        if (sfClock_getElapsedTime(game->clock->end_game).microseconds
            / 1000000.0 >= 0.042) {
            sfSprite_setTextureRect(sprite, rect);
            sfRenderWindow_drawSprite(game->win.dow, sprite, NULL);
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
    make_choose(game);
}

void choose_skill(game_t *game)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture =
    sfTexture_createFromFile("assets/img/other/end_game.png", NULL);

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){1.2, 1.3});
    sfSprite_setPosition(sprite, (sfVector2f){
        sfView_getCenter(game->view.view).x - 960,
        sfView_getCenter(game->view.view).y - 540});
    game->clock->end_game = sfClock_create();
    transition_game_to_skill(game, sprite);
    sfClock_destroy(game->clock->end_game);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

void check_choose_skill(game_t *game)
{
    if (game->player.xp >= game->var.player_xp &&
        sfRenderWindow_isOpen(game->win.dow) &&
        game->var.slot_skill_four == 20) {
        choose_skill(game);
        game->player.xp = 0;
    }
}