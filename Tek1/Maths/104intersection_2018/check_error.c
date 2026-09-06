/*
** EPITECH PROJECT, 2018
** check_error.c
** File description:
** check_error
*/

#include <stdlib.h>
#include <stdio.h>

void option_h(void)
{
    printf("USAGE\n");
    printf("\t./104intersection opt xp yp zp xv yv zv p\n\n");
    printf("DESCRIPTION\n");
    printf("\topt\t\tsurface option: 1 for a sphere, 2 for a cylinder, 3 for"
        " a cone\n");
    printf("\t(xp, yp, zp)\tcoordinates of a point by which the light ray"
        " passes through\n");
    printf("\t(xv, yv, zv)\tcoordinates of a vector parallel to the light"
        " ray\n");
    printf("\tP\t\tparameter: radius of the sphere, radius of the cylinder,"
        " or\n");
    printf("\t   \t\tangle formed by the cone and the Z-axis\n");
}

int check_error_two(char *av[])
{
    if ((av[1][0] == '1' && av[1][1] == '\0') || (av[1][0] == '2' &&
        av[1][1] == '\0'))
        if (atof(av[8]) <= 0) {
            printf("Invalid Argument.\n");
            exit(84);
        }
    if (av[1][0] == '3' && av[1][1] == '\0')
        if (atof(av[8]) <= 0 || atof(av[7]) >= 180) {
            printf("Invalid Argument.\n");
            exit(84);
        }
    return (0);
}

int check_error(int ac, char *av[])
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        option_h();
        exit(0);
    }
    if (ac != 9 || !((av[1][0] == '1' && av[1][1] == '\0') || (av[1][0] == '2'
        && av[1][1] == '\0') || (av[1][0] == '3' && av[1][1] == '\0'))) {
        printf("Invalid Argument.\n");
        exit(84);
    }
    for (int i = 2; i <= 8; i++)
        for (int i_two = 0; av[i][i_two] != '\0'; i_two++)
            if (!((av[i][i_two] >= '0' && av[i][i_two] <= '9') ||
                (av[i][i_two] == '-'))) {
                printf("Invalid Argument.\n");
                exit(84);
            }
    return (check_error_two(av));
}
