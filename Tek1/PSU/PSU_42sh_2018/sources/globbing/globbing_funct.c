/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** funct to handle globbing
*/

#include "my_shell.h"

void globbing_qmark(glob_t **list, char *str, int i)
{
    if (str[i + 1])
        for (glob_t *tmp = *list; tmp; tmp = tmp->next)
            if (tmp->status == false)
                tmp->pc++;
    return;
}

void globbing_star(glob_t **list, char *str, int i)
{
    if (str[i + 1] && str[i + 1] != '*' && str[i + 1] != '?'
    && str[i + 1] != '{' && str[i + 1] != '[') {
        for (glob_t *tmp = *list; tmp; tmp = tmp->next)
            if (tmp->status == false)
                for (; tmp->name[tmp->pc]
                && tmp->name[tmp->pc] != str[i + 1]; tmp->pc++)
                    if (tmp->name[tmp->pc] == '\0')
                        tmp->status = true;
    } else if (str[i + 1] && (str[i + 1] == '*' || str[i + 1] == '?'
    || str[i + 1] == '{' || str[i + 1] == '[')) {
        for (glob_t *tmp = *list; tmp; tmp = tmp->next)
            if (tmp->status == false)
                tmp->pc++;
    }
    return;
}

void globbing_hook(glob_t **list, char *str, int i)
{
    if (str[i] != '[' || str[i + 2] != '-' || str[i + 4] != ']'
    || str[i + 1] > str[i + 3])
        for (glob_t *tmp =*list; tmp; tmp = tmp->next)
            tmp->status = true;
    for (glob_t *tmp = *list; tmp; tmp = tmp->next) {
        if (tmp->status == false) {
            if (tmp->name[tmp->pc] < str[i + 1]
            || tmp->name[tmp->pc] > str[i + 3]) {
                tmp->status = true;
            } else
                tmp->pc++;
        }
    }
}

void find_char(glob_t **list, char *str, int j)
{
    for (glob_t *tmp = *list; tmp; tmp = tmp->next) {
        if (tmp->status == false) {
            if (tmp->name[tmp->pc] != str[j]) {
                tmp->status = true;
            } else
                tmp->pc++;
        }
    }
}
