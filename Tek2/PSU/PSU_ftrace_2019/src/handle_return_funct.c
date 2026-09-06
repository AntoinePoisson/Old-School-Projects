/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** handle_return_funct
*/

#include "ftrace.h"

static funct_t *destroy_last_node(ftrace_t *ftrace);

funct_t *handle_return_funct(ftrace_t *ftrace)
{
    if (ftrace->list == NULL)
        return (ftrace->list);
    if (ftrace->list->next == NULL) {
        fprintf(stdout, "Leaving function %s\n", ftrace->list->name);
        free(ftrace->list);
        ftrace->list = NULL;
        return (ftrace->list);
    }
    return (destroy_last_node(ftrace));
}

static funct_t *destroy_last_node(ftrace_t *ftrace)
{
    funct_t *save = ftrace->list;

    while (ftrace->list->next->next) {
        ftrace->list = ftrace->list->next;
    }
    fprintf(stdout, "Leaving function %s\n", ftrace->list->next->name);
    free(ftrace->list->next);
    ftrace->list->next = NULL;
    ftrace->list = save;
    return (save);
}