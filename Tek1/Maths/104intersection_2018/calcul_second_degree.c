/*
** EPITECH PROJECT, 2018
** calcul_second_degre
** File description:
** calcul_equa_second_degre
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_struct.h"

void display_result_inf(void);

float delta(float a, float b, float c)
{
    float result = powf(b, 2);
    float sub = (-4 * a * c);

    result = result + sub;
    return (result);
}

int nbr_solve_equa_two(float a, float b, float c)
{
    int delt = delta(a, b, c);

    if (delt < 0)
        return (0);
    if (delt == 0)
        return (1);
    if (delt > 0)
        return (2);
    return (84);
}

void is_ext_solve_equa_second(float a, float b, float c, var_t *var)
{
    var->solve_equa_one = ((-b + sqrtf(delta(a, b, c))) / (2 * a));
    var->solve_equa_two = ((-b - sqrtf(delta(a, b, c))) / (2 * a));
}

int exceptionnal_case_calcul(float a, float b, float c, var_t *var)
{
    if (a == 0) {
        var->solve_equa_one = (((-c)/(b)));
        return (1);
    }
    return (0);
}

int solve_equa_second(float a, float b, float c, var_t *var)
{
    int nbr_solv = nbr_solve_equa_two(a, b, c);

    if (a == 0 && b == 0 && c == 0)
        display_result_inf();
    if ((a == 0 && b != 0 && c != 0) || (a == 0 && b == 0 && c != 0))
        return (exceptionnal_case_calcul(a, b, c, var));
    if (nbr_solv == 2) {
        is_ext_solve_equa_second(a, b, c, var);
        return (2);
    }
    if (nbr_solv == 1) {
        var->solve_equa_one = ((-b) / (a * 2));
        return (1);
    }
    if (nbr_solv == 0)
        return (0);
    return (84);
}
