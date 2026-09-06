/*
** EPITECH PROJECT, 2019
** is_bisection_method.c
** File description:
** is_bisection_method
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calcul_funct_x(char *av[], double x);

void is_bisection_method(char *av[])
{
    double a = 0;
    double b = 1;
    double c = 0;
    int limit = 1;

    for (int i = 1; i < 21 || limit == 1; i++) {
        c = ((a + b) / 2);
        if ((calcul_funct_x(av, a) * calcul_funct_x(av, c)) < 0)
            b = c;
        else
            a = c;
        if (round(a * pow(10, atoi(av[7]))) == round(b * pow(10, atoi(av[7]))))
            return;
        if (i <= atoi(av[7]))
            printf("x = %.*f\n", i, c);
        else
            printf("x = %.*f\n", atoi(av[7]), c);
    }
}
