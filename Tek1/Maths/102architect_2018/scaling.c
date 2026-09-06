/*
** EPITECH PROJECT, 2018
** scal
** File description:
** scal
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

int scal(char *str_one, char *str_two, char *str_four, char *str_five)
{
    float calc1;
    float calc2;

    calc1 = atoi(str_one) * atoi(str_four);
    calc2 = atoi(str_two) * atoi(str_five);
    printf("Scaling by factors %d and %d\n", atoi(str_four), atoi(str_five));
    printf("%.2f 0.00 0.00\n", atof(str_four));
    printf("0.00 %.2f 0.00\n", atof(str_five));
    printf("0.00 0.00 1.00\n");
    printf("(%d, %d) => (%.2f, %.2f)\n",
            atoi(str_one), atoi(str_two), calc1, calc2);
    exit(0);
}
