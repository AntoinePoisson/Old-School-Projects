/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_struct.h"

int check_error(int ac, char *av[]);
equa_parametric_t *calcul_equa_parametric(char *av[]);
void intersection_line_and_sphere(equa_parametric_t *equa_parametric,
    char *av[]);
void intersection_line_and_cylinder(equa_parametric_t *equa_parametric,
    char *av[]);
void intersection_line_and_cone(equa_parametric_t *equa_parametric,
    char *av[]);

int main(int ac, char *av[])
{
    int i = check_error(ac, av);
    equa_parametric_t *line = calcul_equa_parametric(av);

    if (atoi(av[1]) == 1)
        intersection_line_and_sphere(line, av);
    if (atoi(av[1]) == 2)
        intersection_line_and_cylinder(line, av);
    if (atoi(av[1]) == 3)
        intersection_line_and_cone(line, av);
    return (i);
}
