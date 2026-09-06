/*
** EPITECH PROJECT, 2018
** is_extension_101pong
** File description:
** extension of 101pong
*/

#include "include/101pong.h"

void is_extension_check_errors(int ac, coordinate_t *vector_1,
                               coordinate_t *vector_2, char *av[])
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        case_option_h();
    if (ac != 8) {
        write(2, "The number of arguments is insufficient", 39);
        write(2, "\n", 1);
        exit(EXIT_ERROR);
    }
    if (vector_1 == NULL || vector_2 == NULL) {
        write(2, "Can not allocate memory", 23);
        write(2, "\n", 1);
        exit(EXIT_ERROR);
    }
}

void check_errors(int ac, coordinate_t *vector_1, coordinate_t *vector_2,
                  char *av[])
{
    is_extension_check_errors(ac, vector_1, vector_2, av);
    for (int counter = 1; counter < ac; counter++) {
        for (int i = 0; av[counter][i] != '\0'; i++) {
            if (!(av[counter][i] >= '0' && av[counter][i] <= '9' ||
                  av[counter][i] == '.' || av[counter][i] == '-')) {
                write(2, "Invalid input", 13);
                write(2, "\n", 1);
                exit(UNVALID_CHARAC);
            }
            if (!(av[7][0] >= '0' && av[7][0] <= '9')) {
                write(2, "Invalid input", 13);
                write(2, "\n", 1);
                exit(UNVALID_CHARAC);
            }
        }

    }
}
