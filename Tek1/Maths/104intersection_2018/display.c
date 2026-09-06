/*
** EPITECH PROJECT, 2018
** display
** File description:
** display answer
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_struct.h"

equa_parametric_t *equa_parametric(equa_parametric_t *equa_parametri,
    float coefficient);

void first_display(char *av[])
{
    if (av[1][0] == '1')
        printf("Sphere of radius %s\n", av[8]);
    if (av[1][0] == '2')
        printf("Cylinder of radius %s\n", av[8]);
    if (av[1][0] == '3')
        printf("Cone with a %s degree angle\n", av[8]);
    printf("Line passing through the point (%s, %s, %s) "
        "and parallel to the vector (%s, %s, %s)\n", av[2], av[3], av[4], av[5]
        , av[6], av[7]);
}

void display_result_zero(void)
{
    printf("No intersection point.\n");
}

void display_result_one(equa_parametric_t *equa_parametri)
{
    printf("(%.3f,", equa_parametri->x);
    printf(" %.3f,", equa_parametri->y);
    printf(" %.3f)\n", equa_parametri->z);
}

void display_result_two(equa_parametric_t *equa_parametri, var_t *var)
{
    printf("(%.3f,", equa_parametri->x);
    printf(" %.3f,", equa_parametri->y);
    printf(" %.3f)\n", equa_parametri->z);
    equa_parametric(equa_parametri, var->solve_equa_two);
    printf("(%.3f,", equa_parametri->x);
    printf(" %.3f,", equa_parametri->y);
    printf(" %.3f)\n", equa_parametri->z);
}

void display_result_inf(void)
{
    printf("There is an infinite number of intersection points.\n");
    exit(0);
}
