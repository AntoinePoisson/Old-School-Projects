/*
** EPITECH PROJECT, 2019
** is_secant_method.c
** File description:
** is_secant_method
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

double calcul_funct_x(char *av[], double x);
double calcul_deri_funct_x(char *av[], double x);

void is_extension_second(char *av[], double save, int cas, int i)
{
    if (cas == 1) {
        if (i != 0)
            printf("x = %.*f\n", atoi(av[7]), save);
        else
            printf("x = %g\n", save);
    } else {
        printf("Divised by 0\n");
        exit(84);
    }
}

void is_secant_method(char *av[])
{
    double x_zero = 0;
    double x_one = 1;
    double save = 0;
    double result = 0;
    double result_two = 0;
    int limit = 1;

    for (int i = 0; i < 5 || limit == 1; i++) {
        result = (calcul_funct_x(av, x_one) * (x_one - x_zero));
        result_two = (calcul_funct_x(av, x_one) - calcul_funct_x(av, x_zero));
        if (result_two == 0)
            is_extension_second(av, save, 0, i);
        save = x_one - (result / result_two);
        if (round(save * pow(10, atoi(av[7]))) == round(x_one *
                pow(10, atoi(av[7]))))
            limit = 0;
        x_zero = x_one;
        x_one = save;
        is_extension_second(av, save, 1, i);
    }
}
