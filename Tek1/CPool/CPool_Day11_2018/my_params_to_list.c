/*
** EPITECH PROJECT, 2018
** my_params_to_list
** File description:
** Write a function named my_params_to_list that creates a new list from the command line arguments.
*/

#include "include/mylist.h"
#include <stdlib.h>

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    int i = 0;
    linked_list_t *rev;
    linked_list_t *element;

    for (i = 0; i < ac; i++) {
        element = malloc(sizeof(*element));
        element->data = av[i];
        element->next = rev;
        rev = element;
    }
    return (rev);
}
