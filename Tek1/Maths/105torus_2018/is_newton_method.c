/*
** EPITECH PROJECT, 2019
** is_newton_method.c
** File description:
** is_newton_method
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

double calcul_funct_x(char *av[], double x);
double calcul_deri_funct_x(char *av[], double x);

void is_extension_newton(char *av[], double x_zero, int i, int cas)
{
    if (cas == 1) {
        if (i != 0)
            printf("x = %.*f\n", atoi(av[7]), x_zero);
        else
            printf("x = %.*f\n", 1, x_zero);
    }
    else {
        printf("Division by zero.\n");
        exit(84);
    }
}

void is_newton_method(char *av[])
{
    double x_zero = 0.5;
    double derive = 0;
    double funct = 0;
    double save = 0;
    int limit = 1;

    for (int i = 0; i < 4 || limit == 1; i++) {
        if (round(save * pow(10, atoi(av[7]))) == round(x_zero *
                pow(10, atoi(av[7]))))
            limit = 0;
        else {
            is_extension_newton(av, x_zero, i, 1);
                if ((derive = ((4 * (atoi(av[6]) * pow(x_zero, 3))) +
                        (3 * (atoi(av[5]) * pow(x_zero, 2))) +
                        (2 * (atoi(av[4]) * x_zero)) + atoi(av[3]))) == 0)
                    is_extension_newton(av, x_zero, i, 0);
            funct = calcul_deri_funct_x(av, x_zero);
            save = x_zero;
            x_zero = (save - (funct / derive));
        }
    }
}
