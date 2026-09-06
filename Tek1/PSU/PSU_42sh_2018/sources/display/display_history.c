/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** display history
*/

#include <stdlib.h>
#include "my_shell.h"

static int reverse_list(history_t **list)
{
    history_t *reverse = NULL;
    history_t *head = NULL;

    while (*list != NULL) {
        reverse = malloc(sizeof(*reverse));
        if (reverse == NULL)
            return (84);
        reverse->cmd = (*list)->cmd;
        reverse->hour = (*list)->hour;
        reverse->index = (*list)->index;
        reverse->next = head;
        head = reverse;
        *list = (*list)->next;
    }
    *list = reverse;
    return (0);
}

int size_history(history_t *history)
{
    int i = 0;

    for (history_t *tmp = history; tmp; tmp = tmp->next, i++);
    return (i);
}

int display_history(history_t *history, char flag, int nb)
{
    int size = size_history(history);
    history_t *tmp = NULL;

    if (flag != 1)
        reverse_list(&history);
    tmp = history;
    if (flag == 3 && nb <= size)
        for (int i = 0; tmp && (size - i) != nb; i++, tmp = tmp->next);
    for (; tmp; tmp = tmp->next) {
        if (flag != 2)
            my_printf("%u   %s   ", tmp->index, tmp->hour);
        my_printf("%s\n", tmp->cmd);
    }
    return (0);
}

int clean_history(history_t **history)
{
    history_t *delete = NULL;

    while (*history != NULL) {
        delete = *history;
        *history = (*history)->next;
        free(delete->cmd);
        free(delete->hour);
        free(delete);
    }
    return (0);
}
