/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** handle globbing
*/

#include <string.h>
#include <stdlib.h>
#include "my_shell.h"

void add_node(glob_t **list, char *str)
{
    glob_t *temp = malloc(sizeof(glob_t));

    temp->name = str;
    temp->pc = 0;
    temp->status = false;
    temp->next = *list;
    *list = temp;
}

glob_t *open_all_dir(char *str)
{
    DIR *dir = NULL;
    struct dirent *dirent = NULL;
    glob_t *list = NULL;

    if ((dir = opendir(str)) == NULL)
        exit(84);
    while ((dirent = readdir(dir)) != NULL)
        if (dirent->d_name[0] != '.')
            add_node(&list, my_strdup(dirent->d_name));
    closedir(dir);
    free(str);
    return (list);
}

char *find_path(char *str)
{
    char *path;
    int i;
    int j;

    for (i = 0; str[i] && str[i] != '*' && str[i] != '?'
    && str[i] != '{' && str[i] != '['; i++);
    for (j = i; j > 0; j--)
        if (str[j] == '/') {
            path = malloc(sizeof(char) * (j + 1));
            path[j] = '\0';
            path = strncpy(path, str, j);
            return (path);
        }
    path = malloc(sizeof(char) * 2);
    path[0] = '.';
    path[1] = '\0';
    return (path);

}

char *begin_word(char *str, char c)
{
    char *rtn;
    int i;

    for (i = my_strlen(str); str[i] != c; i--);
    rtn = malloc(sizeof(char) * (i + 2));
    if (!rtn)
        exit(84);
    rtn = strncpy(rtn, str, i + 1);
    rtn[i + 1] = '\0';
    return (rtn);
}

char **find_globbing(char **tab)
{
    char **new = NULL;

    if (new == NULL)
        return (tab);
    return (new);
}
