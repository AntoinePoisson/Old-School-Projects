/*
** EPITECH PROJECT, 2018
** my_rev_list
** File description:
** Write a function named my_rev_list that reverses the order of the list’s elements.
*/

#include "include/mylist.h"
#include <stdlib.h>

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *top = NULL;
    linked_list_t *mid = *begin;
    linked_list_t *bot = NULL;

    if (begin == NULL)
        return;
    while (mid != NULL) {
        bot = mid->next;
        mid->next = top;
        top = mid;
        mid = bot;
    }
    *begin = top;
    return;
}
