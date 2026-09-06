/*
** EPITECH PROJECT, 2018
** push
** File description:
** pile management
*/

#include <stdlib.h>
#include "my.h"

void push(pile_t *pile, char charac)
{
    stockage_t *nw_charac = malloc(sizeof(*nw_charac));

    nw_charac->data = charac;
    nw_charac->next = pile->first;
    pile->first = nw_charac;
}
