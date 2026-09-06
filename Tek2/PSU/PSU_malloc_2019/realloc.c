/*
** EPITECH PROJECT, 2020
** reeallocc
** File description:
** reeallocc
*/

#include "header.h"

static node_t *find_node(head_t **head, void *ptr)
{
    node_t *my_node = (*head)->list;

    while (my_node && my_node + sizeof(node_t *) != ptr) {
        my_node = my_node->next;
    }
    if (!my_node)
        return (NULL);
    return (my_node);
}

static void *my_memocpy(node_t *my_node, void *new_alloc, void *ptr,
    size_t size_alloc)
{
    size_t *tmp = ptr;
    size_t *test = new_alloc;

    for (size_t size = 0; size * sizeof(size_t) < my_node->size &&
        size * sizeof(size_t) < size_alloc; size++) {
        test[size] = tmp[size];
    }
    free(ptr);
    return (new_alloc);
}

void *realloc(void *ptr, size_t size)
{
    void *new_alloc = NULL;
    node_t *my_node = NULL;
    head_t **head = get_start(true);

    if (!ptr)
        return (malloc(size));
    my_node = find_node(head, ptr);
    if (my_node && size == 0) {
        free(ptr);
        return (NULL);
    }
    if (my_node && size <= my_node->size)
        return (ptr);
    new_alloc = malloc(size);
    if (my_node == NULL)
        return (new_alloc);
    return (my_memocpy(my_node, new_alloc, ptr, size));
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    size_t calul = size * nmemb;

    if (calul > INT_MAX)
        return (NULL);
    return (realloc(ptr, size * nmemb));
}