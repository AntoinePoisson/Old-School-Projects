/*
** EPITECH PROJECT, 2018
** 101pong
** File description:
** 101pong
*/

#include "101pong.h"

void case_option_h(void)
{
    printf("USAGE\n      ./101pong x0 y0 z0 x1 y1 z1 n\n\nDESCRIPTION\n");
    printf("       x0   ball abscissa at time t - 1\n");
    printf("       y0   ball ordinate at time t - 1\n");
    printf("       z0   ball altitude at time t - 1\n");
    printf("       x1   ball abscissa at time t\n");
    printf("       z1   ball ordinate at time t\n");
    printf("       y1   ball altitude at time t\n");
    printf("       ");
    printf("n    time shift (greater than or equal to zero, integer)\n");
    exit(0);
}

void display_result(coordinate_t *vector_1, coordinate_t *vector_2, int n)
{
    printf("The velocity vector of the ball is:\n");
    printf("(%.2f, %.2f, %.2f)\n", vector_1->x, vector_1->y, vector_1->z);
    printf("At time t + %d, ball coordinates will be:\n", n);
    printf("(%.2f, %.2f, %.2f)\n", vector_2->x, vector_2->y, vector_2->z);
}

void vector_angle(coordinate_t *vector)
{
    float result = sqrt(powf(vector->x, 2) + powf(vector->y, 2) +
                        powf(vector->z, 2));

    if (result == 0) {
        printf("The ball won’t reach the bat.\n");
        exit(EXIT_ERROR);
    }
    result = acos(vector->z / result);
    result = 90 - (result) * 180 /M_PI;
    result = fabs(result);
    if (result > 0 && result <= 90) {
        printf("The incidence angle is:\n");
        printf("%.2f degrees\n", result);
    }
    else
        printf("The ball won’t reach the bat.\n");
}
