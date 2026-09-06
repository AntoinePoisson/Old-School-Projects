/*
** EPITECH PROJECT, 2019
** choose_skill.c
** File description:
** choose skill
*/

#include "my_rpg.h"

int random_skill(game_t *game)
{
    int choose = rand() % 12;

    if (choose == game->var.slot_skill_one ||
        choose == game->var.slot_skill_two ||
        choose == game->var.slot_skill_three ||
        choose == game->var.slot_skill_four)
        choose = random_skill(game);
    return (choose);
}

skill_t *random_skill_(game_t *game)
{
    int element = random_skill(game);
    skill_t *save = game->skill;

    for (int i = 0; save && i < element - 1; i++, save = save->next);
    return (save);
}

void display_skill_tree_text(game_t *game, skill_t *one, skill_t *two)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font/game.ttf");

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfText_setString(text, one->text);
    sfText_setPosition(text, (sfVector2f){
        sfView_getCenter(game->view.view).x - 458,
        sfView_getCenter(game->view.view).y + 100});
    sfRenderWindow_drawText(game->win.dow, text, NULL);
    sfText_setString(text, two->text);
    sfText_setPosition(text, (sfVector2f){
        sfView_getCenter(game->view.view).x + 500,
        sfView_getCenter(game->view.view).y + 100});
    sfRenderWindow_drawText(game->win.dow, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

void display_skill_tree(game_t *game, skill_t *one, skill_t *two)
{
    sfSprite_setScale(game->sprite->skill, (sfVector2f){2, 2});
    sfRenderWindow_clear(game->win.dow, sfBlack);
    sfSprite_setPosition(game->sprite->skill, (sfVector2f){
        sfView_getCenter(game->view.view).x - 468,
        sfView_getCenter(game->view.view).y - 300});
    sfSprite_setTextureRect(game->sprite->skill, one->rect);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->skill, NULL);
    sfSprite_setPosition(game->sprite->skill, (sfVector2f){
        sfView_getCenter(game->view.view).x + 458,
        sfView_getCenter(game->view.view).y - 300});
    sfSprite_setTextureRect(game->sprite->skill, two->rect);
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->skill, NULL);
    display_skill_tree_text(game, one, two);
    sfRenderWindow_setMouseCursorVisible(game->win.dow, 1);
    sfRenderWindow_display(game->win.dow);
    sfSprite_setScale(game->sprite->skill, (sfVector2f){1, 1});
}

void player_input(game_t *game, int *choose)
{
    sfVector2f mouse;

    mouse.x = sfMouse_getPositionRenderWindow(game->win.dow).x;
    mouse.y = sfMouse_getPositionRenderWindow(game->win.dow).y;
    while (sfRenderWindow_pollEvent(game->win.dow, &game->win.event)) {
        if (game->win.event.type == sfEvtClosed)
            sfRenderWindow_close(game->win.dow);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            if (mouse.x < sfView_getCenter(game->view.view).x)
                *choose = 1;
            else
                *choose = 2;
        }
    }
}