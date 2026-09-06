/*
** EPITECH PROJECT, 2020
** tool
** File description:
** tool
*/

#include "header.h"

int research_space_in_list(size_t size, head_t **head)
{
    node_t *save = (*head)->list;
    int index = 0;
    int small_index = -1;
    size_t small_size = -1;

    for (; save; index++) {
        if (save->is_free && save->size >= size) {
            if ((save->size < small_size) || (small_index == -1)) {
                small_size = save->size;
                small_index = index;
            }
        }
        save = save->next;
    }
    if (small_index != -1)
        return (small_index);
    return (-1);
}

void *reload_memory_same_size(head_t **head, int index)
{
    node_t *save = (*head)->list;

    for (int i = 0; i < index && save; i++) {
        save = save->next;
    }
    if (!save)
        return (NULL);
    save->is_free = false;
    return (save + sizeof(node_t *));
}

size_t convertion_parameter(size_t size)
{
    size_t i = 0;

    if (size <= 0)
        return (0);
    while (pow(2, i) < size) {
        i++;
    }
    return (pow(2, i));
}

head_t **get_start(bool activation)
{
    static head_t *list = NULL;
    void *ptr = NULL;

    if (list == NULL && activation) {
        ptr = sbrk(SIZE_PAGE * 2);
        if (ptr == (void *)-1) {
            write(2, "Error Start\n", 12);
            return (NULL);
        }
        list = ptr;
        list->list = NULL;
        list->tail = NULL;
        list->limit = sbrk(0);
        list->nbr_page = 2;
    }
    return (&list);
}