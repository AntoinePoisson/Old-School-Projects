/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** display_inventory.c
*/

#include "my_rpg.h"

void display_item_of_inventory(game_t *game)
{
    sfVector2f view = sfView_getCenter(game->view.view);
    int i = 0;

    for (item_t *s = game->item; s; s = s->next, i += 140) {
        if (s->f) {
            s->rect.top = 148;
            sfSprite_setTextureRect(game->sprite->item, s->rect);
            sfSprite_setPosition(game->sprite->item, (sfVector2f){
            view.x - 340 * game->win.ratio + i,
            view.y + 310 * game->win.ratio});
            sfRenderWindow_drawSprite(game->win.dow, game->sprite->item, NULL);
            s->rect.top = -35;
        }
    }
}

static void display_inventory(game_t *game)
{
    sfRenderWindow_drawSprite(game->win.dow, game->sprite->inventory, NULL);
    sfRenderWindow_drawText(game->win.dow, game->text.player_hp, NULL);
    sfRenderWindow_drawText(game->win.dow, game->text.player_hp_max, NULL);
    sfRenderWindow_drawText(game->win.dow, game->text.player_mana, NULL);
    sfRenderWindow_drawText(game->win.dow, game->text.player_mana_max, NULL);
    sfRenderWindow_drawText(game->win.dow, game->text.player_regen_hp, NULL);
    sfRenderWindow_drawText(game->win.dow, game->text.player_regen_mana, NULL);
    sfRenderWindow_drawText(game->win.dow, game->text.player_gold, NULL);
    sfRenderWindow_drawText(game->win.dow, game->text.player_armor, NULL);
    sfRenderWindow_drawText(game->win.dow, game->text.player_move_speed, NULL);
    sfRenderWindow_drawText(game->win.dow,
    game->text.player_attack_speed, NULL);
    sfRenderWindow_drawText(game->win.dow,
    game->text.player_basic_attack, NULL);
    sfRenderWindow_drawText(game->win.dow,
    game->text.player_spell_attack, NULL);
    display_item_of_inventory(game);
}

void print_inventory(game_t *game)
{
    if (game->var.disp_inventory) {
        set_pos_inventory(game);
        set_pos_text_stats(game);
        set_string_stats(game);
        display_inventory(game);
    }
}
