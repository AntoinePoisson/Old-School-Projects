/*
** EPITECH PROJECT, 2018
** main of 101pong
** File description:
** main
*/

#include "include/101pong.h"

int main(int ac, char *av[])
{
    coordinate_t *vector_1 = malloc(sizeof(*vector_1));
    coordinate_t *vector_2 = malloc(sizeof(*vector_2));
    coordinate_t *result_diff = malloc(sizeof(*result_diff));

    check_errors(ac, vector_1, vector_2, av);
    vector_1 = create_vector(my_getfloat(av[1]), my_getfloat(av[2]),
                             my_getfloat(av[3]));
    vector_2 = create_vector(my_getfloat(av[4]), my_getfloat(av[5]),
                             my_getfloat(av[6]));
    vector_1 = difference_vector(vector_1, vector_2);
    result_diff = produit_vector_real(my_getnbr(av[7]), vector_1);
    vector_2 = somme_vector(result_diff, vector_2);
    display_result(vector_1, vector_2, my_getnbr(av[7]));
    if (my_getfloat(av[6]) >= 0 && my_getfloat(av[3]) >= 0 && my_getfloat(av[3])
        >= my_getfloat(av[6]) || my_getfloat(av[6]) <= 0 && my_getfloat(av[3])
        <= 0 && my_getfloat(av[3]) >= my_getfloat(av[6]))
        vector_angle(vector_1);
    else
        printf("The ball won’t reach the bat.\n");
    return (0);
}
