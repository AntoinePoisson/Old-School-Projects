/*
** EPITECH PROJECT, 2018
** my_list_size
** File description:
** Write a function called my_list_size that returns the number of elements on the list
*/

#include "include/mylist.h"
#include <stddef.h>

int my_list_size(linked_list_t const *begin)
{
    int nbr_element = 0;

    if (begin == NULL)
        return (0);
    while (begin != NULL) {
        nbr_element++;
        begin = begin->next;
    }
    return (nbr_element);
}
