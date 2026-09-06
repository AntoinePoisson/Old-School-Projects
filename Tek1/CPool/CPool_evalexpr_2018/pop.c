/*
** EPITECH PROJECT, 2018
** pop
** File description:
** pile management
*/

#include "my.h"

char pop(pile *pile)
{
    char charac_delete = 'n';
    stockage_t *charac_pop = pile->first;

    if (pile != NULL && pile->first != NULL) {
        charac_delete = pile->first->data;
        pile->first = pile->first->next;
    }
    return (charac_delete);
}
