/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** save file
*/

#include "my_rpg.h"

void write_in_file_five(int fd, game_t *game)
{
    write(fd, "\nspeed_move=", 12);
    write(fd, my_itoa(game->player.speed_move, 0),
    my_strlen(my_itoa(game->player.speed_move, 0)));
    write(fd, "\nspeed_attack=", 14);
    write(fd, my_itoa(game->player.speed_attack, 0),
    my_strlen(my_itoa(game->player.speed_attack, 0)));
    write(fd, "\narmor=", 7);
    write(fd, my_itoa(game->player.armor, 0),
    my_strlen(my_itoa(game->player.armor, 0)));
    write(fd, "\nattack_basic=", 14);
    write(fd, my_itoa(game->player.attack_basic, 0),
    my_strlen(my_itoa(game->player.attack_basic, 0)));
    write(fd, "\nattack_spell=", 14);
    write(fd, my_itoa(game->player.attack_spell, 0),
    my_strlen(my_itoa(game->player.attack_spell, 0)));
    write(fd, "\nanimation=", 11);
    write(fd, my_itoa(game->player.animation, 0),
    my_strlen(my_itoa(game->player.animation, 0)));
}

void write_in_file_four(int fd, game_t *game)
{
    write(fd, "\nhp=", 4);
    write(fd, my_itoa(game->player.hp, 0),
    my_strlen(my_itoa(game->player.hp, 0)));
    write(fd, "\nmana=", 6);
    write(fd, my_itoa(game->player.mana, 0),
    my_strlen(my_itoa(game->player.mana, 0)));
    write(fd, "\ngold=", 6);
    write(fd, my_itoa(game->player.mana, 0),
    my_strlen(my_itoa(game->player.mana, 0)));
    write(fd, "\nxp=", 4);
    write(fd, my_itoa(game->player.xp, 0),
    my_strlen(my_itoa(game->player.xp, 0)));
    write(fd, "\nregen_hp=", 10);
    write(fd, my_itoa(game->player.regen_hp, 0),
    my_strlen(my_itoa(game->player.regen_hp, 0)));
    write(fd, "\nregen_mana=", 12);
    write(fd, my_itoa(game->player.regen_mana, 0),
    my_strlen(my_itoa(game->player.regen_mana, 0)));
    write_in_file_five(fd, game);
}

void write_in_file_third(int fd, game_t *game)
{
    write(fd, "\ngame->var.player_speed=", 24);
    write(fd, my_itoa(game->var.player_speed, 0),
    my_strlen(my_itoa(game->var.player_speed, 0)));
    write(fd, "\ngame->var.player_xp=", 21);
    write(fd, my_itoa(game->var.player_xp, 0),
    my_strlen(my_itoa(game->var.player_xp, 0)));
    write(fd, "\ngame->var.spell_range=", 23);
    write(fd, my_itoa(game->var.spell_range, 0),
    my_strlen(my_itoa(game->var.spell_range, 0)));
    write(fd, "\ngame->var.spell_speed=", 23);
    write(fd, my_itoa(game->var.spell_speed, 0),
    my_strlen(my_itoa(game->var.spell_speed, 0)));
    write(fd, "\ngame->var.spell_dmg=", 21);
    write(fd, my_itoa(game->var.spell_dmg, 0),
    my_strlen(my_itoa(game->var.spell_dmg, 0)));
    write(fd, "\nstatus=", 8);
    write(fd, my_itoa(game->player.status, 0),
    my_strlen(my_itoa(game->player.status, 0)));
    write_in_file_four(fd, game);
}

void write_in_file_two(int fd, game_t *game)
{
    write(fd, "\nscore=", 7);
    write(fd, my_itoa(game->var.score, 0),
    my_strlen(my_itoa(game->var.score, 0)));
    write(fd, "\ntime=", 6);
    write(fd, my_itoa(game->var.time, 0),
    my_strlen(my_itoa(game->var.time, 0)));
    write(fd, "\nkill=", 6);
    write(fd, my_itoa(game->var.kill, 0),
    my_strlen(my_itoa(game->var.kill, 0)));
    write(fd, "\nmove=", 6);
    write(fd, my_itoa(game->var.move, 0),
    my_strlen(my_itoa(game->var.move, 0)));
    write(fd, "\ngame->var.player_hp=", 21);
    write(fd, my_itoa(game->var.player_hp, 0),
    my_strlen(my_itoa(game->var.player_hp, 0)));
    write(fd, "\ngame->var.player_mana=", 23);
    write(fd, my_itoa(game->var.player_mana, 0),
    my_strlen(my_itoa(game->var.player_mana, 0)));
    write_in_file_third(fd, game);
}

void write_in_file(int fd, game_t *game)
{
    write(fd, "quit_beach=", 11);
    write(fd, my_itoa(game->var.quit_beach, 0),
    my_strlen(my_itoa(game->var.quit_beach, 0)));
    write(fd, "\nquit_donjon=", 13);
    write(fd, my_itoa(game->var.quit_donjon, 0),
    my_strlen(my_itoa(game->var.quit_donjon, 0)));
    write(fd, "\nlevel=", 7);
    write(fd, my_itoa(game->var.level, 0),
    my_strlen(my_itoa(game->var.level, 0)));
    write(fd, "\nfullscreen=", 12);
    write(fd, my_itoa(game->var.fullscreen, 0),
    my_strlen(my_itoa(game->var.fullscreen, 0)));
    write(fd, "\nchara=", 7);
    write(fd, my_itoa(game->var.chara, 0),
    my_strlen(my_itoa(game->var.chara, 0)));
    write(fd, "\npotion=", 8);
    write(fd, my_itoa(game->var.potion, 0),
    my_strlen(my_itoa(game->var.potion, 0)));
    write_in_file_two(fd, game);
}
