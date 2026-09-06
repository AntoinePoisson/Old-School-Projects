/*
** EPITECH PROJECT, 2018
** pop
** File description:
** pile management
*/

#include <stddef.h>
#include "my.h"

char pop(pile_t *pile)
{
    char charac_delete = 'n';

    if (pile != NULL && pile->first != NULL) {
        charac_delete = pile->first->data;
        pile->first = pile->first->next;
    }
    return (charac_delete);
}
