/*
** EPITECH PROJECT, 2018
** calcul_equa_parametric
** File description:
** calcul_equa_parametric
*/

#include <stdlib.h>
#include "my_struct.h"

equa_parametric_t *equa_parametric(equa_parametric_t *equa_parametric,
    float coefficient)
{
    equa_parametric->x = (equa_parametric->point.x + coefficient *
        equa_parametric->vector.x);
    equa_parametric->y = (equa_parametric->point.y + coefficient *
        equa_parametric->vector.y);
    equa_parametric->z = (equa_parametric->point.z + coefficient *
        equa_parametric->vector.z);
    return (equa_parametric);
}

equa_parametric_t *calcul_equa_parametric(char *av[])
{
    equa_parametric_t *result = malloc(sizeof(*result));

    result->point.x = atof(av[2]);
    result->point.y = atof(av[3]);
    result->point.z = atof(av[4]);
    result->vector.x = atof(av[5]);
    result->vector.y = atof(av[6]);
    result->vector.z = atof(av[7]);
    result->coefficient = atof(av[8]);
    return (result);
}
