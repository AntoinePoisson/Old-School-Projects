/*
** EPITECH PROJECT, 2018
** struct
** File description:
** struct
*/

#ifndef STRUCT_H
#define STRUCT_H

#include "csfml.h"

typedef struct list_bg_s
{
    int offset;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect rect;
    struct list_bg_s *next;
} list_bg_t;

typedef struct list_bird_s
{
    sfVector2f position;
    sfIntRect rect;
    struct list_bird_s *next;
} list_bird_t;

typedef struct list_obj_s
{
    sfVector2f position;
    sfIntRect rect;
    struct list_obj_s *next;
} list_obj_t;

typedef struct vector2f_s
{
    sfVector2f dino;
    sfVector2f select;
    sfVector2f end_level;
    sfVector2f message_score;
    sfVector2f score;
    sfVector2f health_point;
    sfVector2f heal;
    sfVector2f portal;
    sfVector2f bg_highscore;
    sfVector2f message_highscore;
    sfVector2i twoi;
} vector2f_t;

typedef struct sprite_s
{
    sfSprite *bird;
    sfSprite *dino;
    sfSprite *cactus;
    sfSprite *end_level;
    sfSprite *health_point;
    sfSprite *heal;
    sfSprite *win;
    sfSprite *loss;
    sfSprite *menu;
    sfSprite *select;
    sfSprite *play;
    sfSprite *highscore;
    sfSprite *quit;
    sfSprite *portal;
    sfSprite *bg_highscore;
} sprite_t;

typedef struct texture_s
{
    sfTexture *bird;
    sfTexture *dino;
    sfTexture *cactus;
    sfTexture *end_level;
    sfTexture *health_point;
    sfTexture *heal;
    sfTexture *win;
    sfTexture *loss;
    sfTexture *menu;
    sfTexture *select;
    sfTexture *play;
    sfTexture *highscore;
    sfTexture *quit;
    sfTexture *portal;
    sfTexture *bg_highscore;
} texture_t;

typedef struct var_norm_s
{
    int level;
    int obstacle_touch;
    int health_point;
    int score;
    int nbr_obstacle;
    int nbr_obstacle_past;
    int god_mode;
    int hitbox_mode;
    int infinity_mode;
    int bird_mode;
    int bonus_mode;
    int speed_background;
    int quit_game;
    int menu;
    int offset_dino;
    int offset_bird;
    int slow_dino;
    int dino_jump;
    float dino_sinus;
    int dino_down_two;
    int dino_down;
} var_norm_t;

typedef struct music_s
{
    sfMusic *bg_game;
    sfMusic *bg_menu;
    sfMusic *jump;
    sfMusic *loss;
    sfMusic *win;
} music_t;

typedef struct text_s
{
    sfText *score;
    sfText *text_highscore;
    sfFont *font_highscore;
    sfFont *font_score;
} text_t;

typedef struct clocker_s
{
    sfClock *menu;
    sfClock *game;
} clocker_t;

typedef struct my_time_s
{
    sfTime menu;
    sfTime game;
} my_time_t;

typedef struct rect_s
{
    sfIntRect dino;
    sfIntRect heal;
    sfIntRect portal;
    sfIntRect health_point;
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
    struct list_bg_s *bg;
    struct list_obj_s *obj;
    struct list_bird_s *bird;
} variable_t;

#endif
