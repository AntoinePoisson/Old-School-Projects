/*
** EPITECH PROJECT, 2018
** intersection_line_and_cone
** File description:
** intersection_line_and_cone
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
    *equa_parametri)
{
    var_t *var = malloc(sizeof(*var));
    int nbr_solve = solve_equa_second(a, b, c, var);

    if (nbr_solve == 1) {
        printf("1 intersection point:\n");
        equa_parametric(equa_parametri, var->solve_equa_one);
        display_result_one(equa_parametri);
    }
    if (nbr_solve == 2) {
        printf("2 intersection points:\n");
        equa_parametric(equa_parametri, var->solve_equa_one);
        display_result_two(equa_parametri, var);
    }
    if (nbr_solve == 0)
        display_result_zero();
    if (nbr_solve != 1 && nbr_solve != 2 && nbr_solve != 0)
        display_result_inf();
}

void intersection_line_and_cone(equa_parametric_t *equa_parametric,
    char *av[])
{
    float tan_root = (tan(atof(av[8]) * M_PI / 180) * tan(atof(av[8])
        * M_PI / 180));
    float a = (powf(equa_parametric->vector.x, 2) +
        powf(equa_parametric->vector.y, 2) - (tan_root *
        powf(equa_parametric->vector.z, 2)));
    float b = 2 * ((equa_parametric->vector.x * equa_parametric->point.x) +
        (equa_parametric->vector.y * equa_parametric->point.y) - (tan_root *
        equa_parametric->vector.z * equa_parametric->point.z));
    float c = (powf(equa_parametric->point.x, 2) +
        powf(equa_parametric->point.y, 2) - (tan_root *
        powf(equa_parametric->point.z, 2)));

    first_display(av);
    calcul_if_intersection(a, b, c, equa_parametric);
}
