/*
** EPITECH PROJECT, 2020
** main_function
** File description:
** main_function
*/

#include "header.h"

bool realloc_page(node_t *max_size, head_t **head)
{
    size_t besoin = (char *)max_size - (char *)(*head)->limit;
    size_t multiplicateur = 2;

    while (multiplicateur * SIZE_PAGE <= besoin) {
        multiplicateur += 2;
    }
    if (sbrk(SIZE_PAGE * multiplicateur) == (void *)-1) {
        write(2, "Error alloc page\n", 12);
        return (false);
    }
    (*head)->limit = (node_t *)sbrk(0);
    return (true);
}

void *alloc_new_node(head_t **head, size_t alloc_size)
{
    node_t *save = (*head)->tail;
    node_t *new_node = !save ? ((node_t *)&(**head) + sizeof(head_t *)) :
        (&(*save) + sizeof(node_t *) + save->size);

    if (((*head)->limit - (new_node + sizeof(node_t *) + alloc_size)) <= 0)
        if (!realloc_page(new_node + sizeof(node_t *) + alloc_size, head))
            return (NULL);
    new_node->size = alloc_size;
    new_node->is_free = false;
    new_node->next = NULL;
    if (!save) {
        new_node->prev = NULL;
        (*head)->list = new_node;
        (*head)->tail = new_node;
        return ((*head)->list + sizeof(node_t *));
    }
    new_node->prev = save;
    save->next = new_node;
    (*head)->tail = new_node;
    return (new_node + sizeof(node_t *));
}

void *malloc(size_t size)
{
    head_t **head = get_start(true);
    size_t alloc_size = convertion_parameter(size);
    int index = 0;

    if (!head || size <= 0 || alloc_size <= 0) {
        return (NULL);
    }
    if ((index = research_space_in_list(alloc_size, head)) >= 0) {
        return (reload_memory_same_size(head, index));
    }
    return (alloc_new_node(head, alloc_size));
}

void free(void *ptr)
{
    head_t **head = get_start(false);
    node_t *save = NULL;

    if (!ptr || !head || !(*head)->list) {
        return;
    }
    save = (*head)->list;
    while (save && save + sizeof(node_t *) != ptr) {
        save = save->next;
    }
    if (!save) {
        return;
    }
    save->is_free = true;
}

void *calloc(size_t nmemb, size_t size)
{
    void *result = NULL;
    char *transformation = NULL;

    result = malloc(nmemb * size);
    if (!result)
        return (NULL);
    transformation = (char *)result;
    for (size_t count = 0; count < nmemb; count++) {
        transformation[count] = 0;
    }
    return (result);
}