/*
** EPITECH PROJECT, 2018
** intersection_line_and_cylinder
** File description:
** intersection_line_and_cylinder
*/

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "my_struct.h"

int solve_equa_second(float a, float b, float c, var_t *var);
equa_parametric_t *equa_parametric(equa_parametric_t *equa_parametri,
    float coefficient);
void first_display(char *av[]);
void display_result_zero(void);
void display_result_one(equa_parametric_t *equa_parametri);
void display_result_two(equa_parametric_t *equa_parametri, var_t *var);
void display_result_inf(void);
void calcul_if_intersection(float a, float b, float c, equa_parametric_t
    *equa_parametri);

void intersection_line_and_cylinder(equa_parametric_t *equa_parametric,
    char *av[])
{
    float a = (powf(equa_parametric->vector.x, 2) +
        powf(equa_parametric->vector.y, 2));
    float b = 2 * (equa_parametric->vector.x * equa_parametric->point.x +
        equa_parametric->vector.y * equa_parametric->point.y);
    float c = ((powf(atof(av[8]), 2) * -1) + powf(equa_parametric->point.x, 2)
        + powf(equa_parametric->point.y, 2));
    first_display(av);
    calcul_if_intersection(a, b, c, equa_parametric);
}
