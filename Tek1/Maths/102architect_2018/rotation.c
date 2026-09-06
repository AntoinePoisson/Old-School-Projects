/*
** EPITECH PROJECT, 2018
** rotation
** File description:
** rotation
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

int rotation(char *str_one, char *str_two, char *str_four)
{
    double x = 0;
    double y = 0;
    float result = 0;
    float result2 = 0;

    y = sin((atoi(str_four) * M_PI) /180);
    x = cos((atoi(str_four) * M_PI) / 180);
    result = (x * atof(str_one)) + (-y * atof(str_two));
    result2 = (y * atof(str_one)) + (x * atof(str_two));
    printf("Rotation by a %d degree angle\n", atoi(str_four));
    printf("%.2f %.2f 0.00\n", x, -y);
    printf("%.2f %.2f 0.00\n", y, x);
    printf("0.00 0.00 1.00\n");
    printf("(%d, %d) => (%.2f, %.2f)\n",
            atoi(str_one), atoi(str_two), result, result2);
    exit(0);
}
