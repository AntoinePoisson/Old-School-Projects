/*
** EPITECH PROJECT, 2019
** tool.c
** File description:
** tool
*/

#include <math.h>
#include <stdlib.h>
#include "my_lib.h"

double calcul_funct_x(char *av[], double x)
{
    double result = (atof(av[6]) * pow(x, 4) + atof(av[5]) *
        pow(x, 3) + atof(av[4]) * pow(x, 2) +
        atof(av[3]) * x + atof(av[2]));

    return (result);
}

double calcul_deri_funct_x(char *av[], double x)
{
    double result = (atof(av[6]) * pow(x, 4) + atof(av[5]) *
        pow(x, 3) + atof(av[4]) * pow(x, 2) +
        atof(av[3]) * x + atof(av[2]));

    return (result);
}
