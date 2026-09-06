/*
** EPITECH PROJECT, 2019
** my_struct.c
** File description:
** all headers of my struct
*/

#ifndef MY_STRUCT_H
#define MY_STRUCT_H

enum e_colors {
    BLACK,
    WHITE,
    GREEN,
    BLUE,
    CYAN,
    RED,
    YELLOW,
    MAGENTA
};

typedef struct tetrimino_s {
    char *name;
    char **tetrimino;
    int color;
    int row;
    int col;
    struct tetrimino_s *next;
} tetrimino_t;

typedef struct random_obj_s
{
    int posi_spawn;
    tetrimino_t *tetri;
    struct random_obj_s *next;
} random_obj_t;

typedef struct size_map_s {
    unsigned int row;
    unsigned int col;
} size_map_t;

typedef struct keys_s {
    char *left;
    char *right;
    char *turn;
    char *drop;
    char *quit;
    char *pause;
} keys_t;

typedef struct info_s {
    char *hightscore;
    unsigned int score;
    unsigned int lines;
    unsigned int level;
    unsigned int min;
    unsigned int sec;
} info_t;

typedef struct options_s {
    unsigned int level;
    unsigned int speed;
    keys_t keys;
    tetrimino_t *map;
    size_map_t size;
    random_obj_t *obj;
    int level_one;
    int nbr_tetrimino;
    char **plan;
    char **border;
    bool quit;
    bool hide;
    bool debug;
} options_t;

#endif
