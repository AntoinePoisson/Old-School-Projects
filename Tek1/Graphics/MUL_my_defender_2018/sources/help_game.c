/*
** EPITECH PROJECT, 2018
** help_game.c
** File description:
** help_game
*/

#include "my_lib.h"
#include "defender.h"

int count_nbr_enemy(variable_t *sf)
{
    int count = 0;
    enemy_t *enemy = sf->enemy;

    for (; enemy; enemy = enemy->next)
        if (enemy->status != 0)
            count++;
    return (count);
}

static void management_board_time(variable_t *sf, float time)
{
    int total = WAIT_WAVE / 60;
    float result = 0;

    if (sf->var_norm.wave == 1)
        total = WAIT_WAVE * 5 / 60;
    result = (time / total * 1.0) * 100.0;
    if (result <= 20 && result >= 0)
        sf->rect.board_time.top = 2289;
    if (result <= 40 && result > 20)
        sf->rect.board_time.top = 2350;
    if (result <= 60 && result > 40)
        sf->rect.board_time.top = 2411;
    if (result <= 80 && result > 60)
        sf->rect.board_time.top = 2472;
    if (result <= 100 && result > 80)
        sf->rect.board_time.top = 2533;
    sfSprite_setPosition(sf->sprite.resources, (sfVector2f) {1335, 411});
    sfSprite_setTextureRect(sf->sprite.resources, sf->rect.board_time);
    sfRenderWindow_drawSprite(sf->win.dow, sf->sprite.resources, NULL);
}

static void display_timer(variable_t *sf)
{
    int time = sf->var_norm.time_wave / 60;
    int minute = 0;
    char *result = NULL;
    sfVector2f posi = {1365, 365};

    management_board_time(sf, time * 1.0);
    if (time >= 60) {
        minute = time / 60;
        time %= 60;
    }
    result = my_strcat(my_itoa(minute, 0), " : ");
    result = my_strcat(result, my_itoa(time, 0));
    sfText_setPosition(sf->text.text_money, posi);
    sfText_setString(sf->text.text_money, result);
    sfRenderWindow_drawText(sf->win.dow, sf->text.text_money, NULL);
}

static void display_text_help(variable_t *sf)
{
    char *hdv = "Please put\n Town Hall\n  on map !";
    sfVector2f posi = {1307, 287};

    if (sf->vector.hdv.x == 0) {
        sfText_setPosition(sf->text.text_money, posi);
        sfText_setString(sf->text.text_money, hdv);
        sfRenderWindow_drawText(sf->win.dow, sf->text.text_money, NULL);
        return;
    }
    display_timer(sf);
}

void display_help_in_game(variable_t *sf)
{
    sfVector2f posi = {1430, 525};
    int count_enemy = count_nbr_enemy(sf);
    char *result = my_itoa(count_enemy, 0);

    display_text_help(sf);
    sfText_setPosition(sf->text.text_money, posi);
    sfText_setString(sf->text.text_money, result);
    sfRenderWindow_drawText(sf->win.dow, sf->text.text_money, NULL);
}
