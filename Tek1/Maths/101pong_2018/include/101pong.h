/*
** EPITECH PROJECT, 2018
** 101pong
** File description:
** Header of 101pong
*/

#ifndef PONG_H
#define PONG_H

#define EXIT_ERROR 84
#define UNVALID_CHARAC 84

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct coordinate_s
{
    float x;
    float y;
    float z;
} coordinate_t;

void is_extension_check_errors(int ac, coordinate_t *vector_1, coordinate_t
                               *vector_2, char *av[]);
void check_errors(int ac, coordinate_t *vector_1, coordinate_t *vector_2,
                  char *av[]);
int my_compute_square_root(int nb);
int my_compute_power_rec(int nb, int p);
int my_strlen(char const *str);
float my_getfloat(char const *str);
int my_getnbr(char const *str);
coordinate_t *create_vector(float x, float y, float z);
coordinate_t *somme_vector(coordinate_t *vector_1, coordinate_t *vector_2);
coordinate_t *difference_vector(coordinate_t *vector_1, coordinate_t *vector_2);
coordinate_t *produit_vector_real(float R, coordinate_t *vector);
void case_option_h(void);
void display_result(coordinate_t *vector_1, coordinate_t *vector_2, int n);
void vector_angle(coordinate_t *vector);

#endif
