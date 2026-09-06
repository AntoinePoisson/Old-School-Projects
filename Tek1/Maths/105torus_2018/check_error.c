/*
** EPITECH PROJECT, 2019
** check_error.c
** File description:
** check_error.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void is_flag_h(void)
{
    printf("USAGE\n\t./105torus opt a0 a1 a2 a3 a4 n\n\n");
    printf("DESCRIPTION\n\topt\tmethod option:\n");
    printf("\t\t\t1 for the bisection method\n");
    printf("\t\t\t2 for Newton’s method\n");
    printf("\t\t\t3 for the secant method\n");
    printf("\ta[0-4]\tcoefficients of the equation\n");
    printf("\tn\tprecision (the application of the polynomial to the");
    printf(" solution should\n");
    printf("\t\tbe smaller than 10ˆ-n)\n");
    exit(0);
}

int check_error(int ac, char *av[])
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        is_flag_h();
    if (ac != 8) {
        write(2, "Invalid nbr argument.\n", 22);
        return (84);
    }
    for (int i = 1; i < 8; i++)
        for (int i_two = 0; av[i][i_two] != '\0'; i_two++)
            if (!(av[i][i_two] >= '0' && av[i][i_two] <= '9'))
                if (av[i][0] != '-' || i == 7 || i_two != 0) {
                    write(2, "Invalid argument.\n", 18);
                    return (84);
                }
    if (!(av[1][0] >= '1' && av[1][0] <= '3' && av[1][1] == '\0')) {
        write(2, "Invalid argument.\n", 18);
        return (84);
    }
    return (0);
}
