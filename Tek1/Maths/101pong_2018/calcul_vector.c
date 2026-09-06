/*
** EPITECH PROJECT, 2018
** operator_vector
** File description:
** function for operate vector
*/

#include "101pong.h"

coordinate_t *create_vector(float x, float y, float z)
{
    coordinate_t *vector = malloc(sizeof(*vector));

    if (vector == NULL)
        exit(EXIT_ERROR);
    vector->x = x;
    vector->y = y;
    vector->z = z;
    return (vector);
}

coordinate_t *somme_vector(coordinate_t *vector_1, coordinate_t *vector_2)
{
    coordinate_t *somme = malloc(sizeof(*somme));

    if (somme == NULL)
        exit(EXIT_ERROR);
    if (!(vector_1->x == 0 && vector_1->y == 0 && vector_1->z == 0)) {
        somme->x = vector_1->x + vector_2->x;
        somme->y = vector_1->y + vector_2->y;
        somme->z = vector_1->z + vector_2->z;
    } else {
        free(somme);
        return (vector_1);
    }
    return (somme);
}

coordinate_t *difference_vector(coordinate_t *vector_1, coordinate_t *vector_2)
{
    coordinate_t *difference = malloc(sizeof(*difference));

    if (difference == NULL)
        exit(EXIT_ERROR);
    difference->x = vector_2->x - vector_1->x;
    difference->y = vector_2->y - vector_1->y;
    difference->z = vector_2->z - vector_1->z;
    return (difference);
}

coordinate_t *produit_vector_real(float R, coordinate_t *vector)
{
    coordinate_t *produit = malloc(sizeof(*produit));

    if (produit == NULL)
        exit(EXIT_ERROR);
    produit->x = vector->x * R;
    produit->y = vector->y * R;
    produit->z = vector->z * R;
    return (produit);
}
