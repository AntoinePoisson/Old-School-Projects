/*
** EPITECH PROJECT, 2019
** analyze_tetriminos.c
** File description:
** analyzation of tetriminos directory
*/

#include "my_tetris.h"

int size_list(options_t *opt)
{
    int size = 0;
    tetrimino_t *tetri = opt->map;

    for (; tetri; tetri = tetri->next) {
        size++;
    }
    return (size);
}

int swap_node(tetrimino_t **one, tetrimino_t **two)
{
    int row = (*one)->row;
    int col = (*one)->col;
    int color = (*one)->color;
    char *name = (*one)->name;
    char **data = (*one)->tetrimino;

    (*one)->row = (*two)->row;
    (*one)->col = (*two)->col;
    (*one)->color = (*two)->color;
    (*one)->name = (*two)->name;
    (*one)->tetrimino = (*two)->tetrimino;
    (*two)->row = row;
    (*two)->col = col;
    (*two)->color = color;
    (*two)->name = name;
    (*two)->tetrimino = data;
    return (0);
}

int stat_size(char const *filepath)
{
    struct stat sb;

    if (lstat(filepath, &sb) == -1)
        return (0);
    return (sb.st_size);
}

int add_node(options_t *opt)
{
    tetrimino_t *new_node = malloc(sizeof(tetrimino_t));

    if (!new_node)
        return (84);
    new_node->name = NULL;
    new_node->tetrimino = NULL;
    new_node->color = -1;
    new_node->row = -1;
    new_node->col = -1;
    new_node->next = opt->map;
    opt->map = new_node;
    return (0);
}

int free_node(options_t *opt)
{
    if (opt->map == NULL || opt->map->next == NULL) {
        opt->map = NULL;
    } else {
        opt->map = opt->map->next;
    }
    return (0);
}