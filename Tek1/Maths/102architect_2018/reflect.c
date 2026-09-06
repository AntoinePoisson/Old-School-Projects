/*
** EPITECH PROJECT, 2018
** reflect
** File description:
** reflect
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

int reflect(char *str_one, char *str_two, char *str_four)
{
    double x;
    double y;
    float a = 0;
    float b = 0;
    float c = 0;

    a = atof(str_one);
    y = sin((2 * atof(str_four) * M_PI) /180);
    x = cos((2 * atof(str_four) * M_PI) / 180);
    c = (x * a) + (y * atof(str_two));
    b = (y * a) + (-x * atof(str_two));
    printf("Reflection over an axis with an inclinaison angle of %d degrees\n",
        atoi(str_four));
    printf("%.2f %.2f 0.00\n", x, y);
    printf("%.2f %.2f 0.00\n", y, -x);
    printf("0.00 0.00 1.00\n");
    printf("(%d, %d) => (%.2f, %.2f)\n",
        atoi(str_one), atoi(str_two), c, b);
    exit(0);
}
