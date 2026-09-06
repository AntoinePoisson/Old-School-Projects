/*
** EPITECH PROJECT, 2018
** translation
** File description:
** translation
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

int trans(char *str_one, char *str_two, char *str_three, char *str_four)
{
    float calc1;
    float calc2;

    calc1 = atoi(str_one) + atoi(str_three);
    calc2 = atoi(str_two) + atoi(str_four);
    printf("Translation along vector (%d, %d)\n", atoi(str_three),
            atoi(str_four));
    printf("1.00 0.00 %.2f\n", atof(str_three));
    printf("0.00 1.00 %.2f\n", atof(str_four));
    printf("0.00 0.00 1.00\n");
    printf("(%d, %d) => (%.2f, %.2f)\n",
        atoi(str_one), atoi(str_two), calc1, calc2);
    exit(0);
}
