/*
** EPITECH PROJECT, 2019
** display_skill.c
** File description:
** display skill
*/

#include "my_rpg.h"

void display_skill_(game_t *game)
{
    skill_t *save = game->skill;
    int limit = game->var.slot_skill_four;

    if (limit < 0)
        limit *= -1;
    if (game->var.slot_skill_four != 20) {
        for (int i = 0; save && i < limit - 1 && save->next;
            i++, save = save->next);
        if (save == NULL)
            return;
        sfSprite_setPosition(game->sprite->skill, (sfVector2f){
            sfView_getCenter(game->view.view).x + 857,
            sfView_getCenter(game->view.view).y + 436});
        sfSprite_setTextureRect(game->sprite->skill, save->rect);
        sfRenderWindow_drawSprite(game->win.dow, game->sprite->skill, NULL);
    }
}

void display_skill_three(game_t *game)
{
    skill_t *save = game->skill;
    int limit = game->var.slot_skill_three;

    if (limit < 0)
        limit *= -1;
    if (game->var.slot_skill_three != 20) {
        for (int i = 0; save && i < limit - 1 && save->next;
            i++, save = save->next);
        if (save == NULL)
            return (display_skill_(game));
        sfSprite_setPosition(game->sprite->skill, (sfVector2f){
            sfView_getCenter(game->view.view).x + 857,
            sfView_getCenter(game->view.view).y + 324});
        sfSprite_setTextureRect(game->sprite->skill, save->rect);
        sfRenderWindow_drawSprite(game->win.dow, game->sprite->skill, NULL);
    }
    display_skill_(game);
}

void display_skill_two(game_t *game)
{
    skill_t *save = game->skill;
    int limit = game->var.slot_skill_two;

    if (limit < 0)
        limit *= -1;
    if (game->var.slot_skill_two != 20) {
        for (int i = 0; save && i < limit - 1 && save->next;
            i++, save = save->next);
        if (save == NULL)
            return (display_skill_three(game));
        sfSprite_setPosition(game->sprite->skill, (sfVector2f){
            sfView_getCenter(game->view.view).x + 857,
            sfView_getCenter(game->view.view).y + 212});
        sfSprite_setTextureRect(game->sprite->skill, save->rect);
        sfRenderWindow_drawSprite(game->win.dow, game->sprite->skill, NULL);
    }
    display_skill_three(game);
}

void display_skill(game_t *game)
{
    skill_t *save = game->skill;
    int limit = game->var.slot_skill_one;

    if (limit < 0)
        limit *= -1;
    if (game->var.slot_skill_one != 20) {
        for (int i = 0; save && i < limit - 1 && save->next;
            i++, save = save->next);
        if (save == NULL)
            return (display_skill_two(game));
        sfSprite_setPosition(game->sprite->skill, (sfVector2f){
            sfView_getCenter(game->view.view).x + 857,
            sfView_getCenter(game->view.view).y + 100});
        sfSprite_setTextureRect(game->sprite->skill, save->rect);
        sfRenderWindow_drawSprite(game->win.dow, game->sprite->skill, NULL);
    }
    display_skill_two(game);
}