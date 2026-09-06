/*
** EPITECH PROJECT, 2018
** create
** File description:
** create
*/

#ifndef IS_MENU_TWO_H
#define IS_MENU_TWO_H

#include "include_csfml.h"
#include "struct.h"
#include <stdlib.h>
#define ERROR 84

void is_extension_menu_ext(variable_t *sf);
void create_menu_sprite_and_texture(variable_t *sf);
void create_menu_bg(variable_t *sf);
void is_extension_menu_three(variable_t *sf);
int is_extension_menu_two(variable_t *sf, int seconds);
void is_extension_menu_close(variable_t *sf);
int my_putstr (char const *str);
void open_window(variable_t *sf);

#endif