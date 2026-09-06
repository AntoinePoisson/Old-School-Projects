/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** edit array
*/

#include <stdlib.h>
#include "my_shell.h"

int tab_len(char **tab)
{
    int count = 0;

    for (;tab && tab[count]; count++);
    return (count);
}

char **my_realloc_tab(char **tab, int add)
{
    int size = tab_len(tab) + 1 + add;
    char **dest = malloc(sizeof(char *) * size);
    int i = 0;

    if (dest == NULL)
        return (NULL);
    for (i = 0; tab[i]; i++)
        dest[i] = tab[i];
    dest[i] = NULL;
    dest[i + 1] = NULL;
    free(tab);
    return (dest);
}

char **linked_to_array(glob_t *list, char **tab, int i)
{
    char **new = my_malloc_two_d(1);
    int j;
    int k;

    for (j = 0, k = 0; tab[j]; j++)
        if (j == i) {
            for (glob_t *tmp = list; tmp; tmp = tmp->next)
                if (tmp->status == false) {
                    new = my_realloc_tab(new, 1);
                    new[k] = my_strdup(tmp->name);
                    k++;
                }
        } else {
            new = my_realloc_tab(new, 1);
            new[k] = my_strdup(tab[j]);
            k++;
        }
    return (new);
}

char **edit_tab(glob_t **list, char **tab, int i)
{
    char **new = NULL;
    int count = 0;

    for (glob_t *tmp = *list; tmp; tmp = tmp->next)
        if (tmp->status == false)
            count++;
    if (!count) {
        my_printf("%s: No match.\n", tab[0]);
        return (NULL);
    } else
        new = linked_to_array(*list, tab, i);
    for (glob_t *tmp = *list; tmp; tmp = *list) {
        free(tmp->name);
        *list = tmp->next;
        free(tmp);
    }
    return (new);
}
