/*
** EPITECH PROJECT, 2018
** initialization
** File description:
** initialization
*/

#include <stddef.h>
#include <stdlib.h>
#include "my_list.h"
#include "my_lib.h"

char *check_error(char *av[], int ac, char *size_max);

char *compare_size(char *size_max, char *element)
{
    int size_element = my_strlen(element);
    int neg = 0;

    if (element[0] == '-')
        size_element--;
    if (my_getnbr(size_max) < size_element)
        return (my_itoa(size_element, neg));
    return (size_max);
}

int add_node(control_list_t **l_a, char *av)
{
    linked_list_t *element = NULL;

    if ((*l_a) != NULL) {
        element = malloc(sizeof(*element));
        if (element != NULL) {
            element->data = av;
            element->previous = NULL;
            (*l_a)->head->previous = element;
            element->next = (*l_a)->head;
            (*l_a)->head = element;
        }
    }
    else
        return (0);
    return (1);
}

char *is_init(control_list_t **l_a, char *av[])
{
    char *size_max = compare_size("0", av[(*l_a)->length - 1]);

    size_max = check_error(av, (*l_a)->length, size_max);
    if (size_max[0] == '-' && size_max[1] == '\0')
        return ("-1");
    for (int i = (*l_a)->length - 1; i > 0; i--)
        if (add_node(&(*l_a), av[i]) == 0)
            return ("-1");
    (*l_a)->tail->next = (*l_a)->head;
    (*l_a)->head->previous = (*l_a)->tail;
    return (size_max);
}
