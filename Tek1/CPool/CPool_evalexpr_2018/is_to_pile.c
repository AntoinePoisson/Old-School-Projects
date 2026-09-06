/*
** EPITECH PROJECT, 2018
** is_to_pile
** File description:
** pile management
*/

#include "my.h"

char is_top_pile(pile *pile)
{
    char stockage = 'n';
    stockage_t *actuel = pile->first;

    if (pile != NULL && pile->first != NULL)
        stockage = actuel->data;
    return (stockage);
}
