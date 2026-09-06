/*
** EPITECH PROJECT, 2019
** convert_list
** File description:
** convert a list of int in 2D tab of int
*/

#include "lem_in.h"

int tab_len(int **tab)
{
    int count = 0;

    for (; tab && tab[count][0] != -1; count++);
    return (count);
}

int **my_realloc_tab_int(int **tab)
{
    int size = tab_len(tab) + 2;
    int **dest = malloc(sizeof(int *) * size);
    int i = 0;

    if (dest == NULL)
        return (NULL);
    for (i = 0; tab[i][0] != -1; i++)
        dest[i] = tab[i];
    if ((dest[i] = malloc(sizeof(int) * 1)) == NULL)
        return (NULL);
    dest[i][0] = -1;
    free(tab);
    return (dest);
}

int **convert_list(int **tab_path, path_t *path)
{
    int line = 0;
    int i = 0;
    int j = 0;

    if (!tab_path || (tab_path = my_realloc_tab_int(tab_path)) == NULL)
        return (NULL);
    for (i = 0; tab_path && tab_path[i][0] != -1; i++);
    for (path_t *temp = path; temp; temp = temp->next, line++);
    if ((tab_path[i] = malloc(sizeof(int) * (line + 1))) == NULL)
        return (NULL);
    for (path_t *temp2 = path; temp2; temp2 = temp2->next, j++) {
        tab_path[i][j] = temp2->index;
    }
    tab_path[i][j] = -1;
    if ((tab_path[i + 1] = malloc(sizeof(int) * 1)) == NULL)
        return (NULL);
    tab_path[i + 1][0] = -1;
    return (tab_path);
}
