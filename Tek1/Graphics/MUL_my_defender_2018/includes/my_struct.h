/*
** EPITECH PROJECT, 2019
** my_struct.c
** File description:
** all headers of my struct
*/

#ifndef MY_STRUCT_H
#define MY_STRUCT_H

#ifndef EXIT_SUCCESS
# define EXIT_SUCCESS 0
#endif

#ifndef EXIT_ERROR
# define EXIT_ERROR 84
#endif

#include "csfml.h"

typedef struct data_s
{
    int status;
    int hp;
    int level;
    int damage;
    int move_speed;
    sfIntRect rect;
    sfVector2f position;
} data_t;

typedef struct enemy_s
{
    int status;
    int hp;
    int damage;
    int move_speed;
    int slow_animation;
    float coef_x;
    float coef_y;
    sfIntRect rect;
    sfVector2f posi;
    struct enemy_s *next;
} enemy_t;

typedef struct obj_s
{
    int id;
    struct data_s *data;
    struct obj_s *next;
} obj_t;

typedef struct build_s
{
    int id;
    struct data_s *data;
    struct build_s *next;
} build_t;

typedef struct vector2f_s
{
    sfVector2f select;
    sfVector2f message_score;
    sfVector2f score;
    sfVector2f bg_highscore;
    sfVector2f message_highscore;
    sfVector2f hdv;
    sfVector2i twoi;
} vector2f_t;

typedef struct sprite_s
{
    sfSprite *end_level;
    sfSprite *win;
    sfSprite *loss;
    sfSprite *menu;
    sfSprite *bg_menu;
    sfSprite *select;
    sfSprite *play;
    sfSprite *highscore;
    sfSprite *quit;
    sfSprite *bg_highscore;
    sfSprite *bg_game;
    sfSprite *resources;
    sfSprite *pause_menu;
} sprite_t;

typedef struct texture_s
{
    sfTexture *end_level;
    sfTexture *win;
    sfTexture *loss;
    sfTexture *menu;
    sfTexture *bg_menu;
    sfTexture *select;
    sfTexture *play;
    sfTexture *highscore;
    sfTexture *quit;
    sfTexture *bg_highscore;
    sfTexture *bg_game;
    sfTexture *resources;
    sfTexture *pause_menu;
} texture_t;

typedef struct var_norm_s
{
    int effet;
    int quit_game;
    int quit_menu;
    int level;
    int nbr_node_list_obj;
    int nbr_node_list_build;
    int take_build;
    int kill;
    int id_of_take_build;
    int nbr_enemy;
    int mode_debug;
    int wave;
    int money;
    int time_wave;
    int reparation;
    int acceleration;
    int timer;
} var_norm_t;

typedef struct music_s
{
    sfMusic *trampo;
    sfMusic *bombe;
    sfMusic *canon;
    sfMusic *attak;
    sfMusic *bg;
    sfMusic *loss;
} music_t;

typedef struct text_s
{
    sfText *text_money;
    sfText *score;
    sfText *text_highscore;
    sfFont *font_highscore;
    sfFont *font_score;
    sfFont *font_money;
} text_t;

typedef struct clocker_s
{
    sfClock *menu;
    sfClock *game;
    sfClock *animation;
} clocker_t;

typedef struct my_time_s
{
    sfTime menu;
    sfTime game;
    sfTime animation;
} my_time_t;

typedef struct rect_s
{
    sfIntRect board_time;
    sfIntRect end_level;
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
    struct obj_s *obj;
    struct build_s *build;
    struct enemy_s *enemy;
} variable_t;

#endif
