/*
** EPITECH PROJECT, 2020
** drawing.c
** File description:
** day01
*/

#include "drawing.h"

void draw_square(uint32_t **img, const point_t *origin, size_t size,
    uint32_t color)
{
    for (unsigned int i = 0; i != size; i++) {
        for (unsigned int i_two = 0; i_two != size; i_two++) {
            img[origin->x + i][origin->y + i_two] = color;
        }
    }
}