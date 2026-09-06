/*
** EPITECH PROJECT, 2018
** struct
** File description:
** struct
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct vector2f_s
{
    sfVector2f duck;
    sfVector2f bg_h_o;
    sfVector2f bg_h_t;
    sfVector2f bg_h_o_s;
    sfVector2f bg_h_t_s;
    sfVector2f ghost;
    sfVector2f window_one;
    sfVector2f window_two;
    sfVector2f door_one;
    sfVector2f door_two;
    sfVector2f back;
    sfVector2f girl;
    sfVector2f shoot;
    sfVector2f heal_point;
    sfVector2f text_time;
    sfVector2f text_score;
    sfVector2f play;
    sfVector2f end;
    sfVector2f twof;
    sfVector2i twoi;
} vector2f_t;

typedef struct sprite_s
{
    sfSprite *shoot;
    sfSprite *ghost;
    sfSprite *duck;
    sfSprite *girl;
    sfSprite *back;
    sfSprite *game_over;
    sfSprite *heal_point;
    sfSprite *door_two;
    sfSprite *door_one;
    sfSprite *window_two;
    sfSprite *window_one;
    sfSprite *bg_h_t_s;
    sfSprite *bg_h_o_s;
    sfSprite *bg_h_t;
    sfSprite *bg_h_o;
    sfSprite *bg;
    sfSprite *bg_menu;
    sfSprite *play;
    sfSprite *end;
} sprite_t;

typedef struct texture_s
{
    sfTexture *game_over;
    sfTexture *heal_point;
    sfTexture *shoot;
    sfTexture *ghost;
    sfTexture *bg_h_o;
    sfTexture *bg_h_t;
    sfTexture *bg_h_o_s;
    sfTexture *bg_h_t_s;
    sfTexture *window_one;
    sfTexture *window_two;
    sfTexture *door_one;
    sfTexture *door_two;
    sfTexture *back;
    sfTexture *girl;
    sfTexture *duck;
    sfTexture *bg;
    sfTexture *bg_menu;
    sfTexture *end;
    sfTexture *play;
} texture_t;

typedef struct var_norm_s
{
    float pause_back;
    int acceleration_back;
    int choose_person_b;
    float pause_door_two;
    int acceleration_door_two;
    int choose_person_d_t;
    float pause_door_one;
    int acceleration_door_one;
    int choose_person_d_o;
    float acceleration_duck;
    float pause_window_one;
    float acceleration_ghost;
    int acceleration_window_one;
    float pause_window_two;
    int acceleration_window_two;
    int choose_person;
    int choose_person_w_t;
    int last_position;
    int shoot;
    int heal_point;
    int game;
    int end_game;
    char *char_text_score;
} var_norm_t;

typedef struct music_s
{
    sfMusic *bg;
    sfMusic *shoot;
} music_t;

typedef struct text_s
{
    sfText *time;
    sfText *score;
    sfFont *font;
} text_t;

typedef struct clocker_s
{
    sfClock *duck;
    sfClock *global;
    sfClock *ghost;
    sfClock *menu;
} clocker_t;

typedef struct my_time_s
{
    sfTime global;
    sfTime menu;
} my_time_t;

typedef struct rect_s
{
    sfIntRect duck;
    sfIntRect ghost;
} rect_t;

typedef struct win_s
{
    sfVideoMode mode;
    sfRenderWindow *dow;
} win_t;

typedef struct event_s
{
    sfEvent event;
} event_t;


typedef struct variable_s
{
    event_t event;
    rect_t rect;
    win_t win;
    my_time_t time;
    clocker_t clock;
    text_t text;
    music_t music;
    vector2f_t vector;
    sprite_t sprite;
    texture_t texture;
    var_norm_t var_norm;
} variable_t;

#endif