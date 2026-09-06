/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** tools for struct
*/

#include <fcntl.h>
#include "my_rpg.h"

int my_strncmp(char const *s1, char const *s2, int const n)
{
    int a = 0;

    while (a < n && s1[a] == s2[a] && s1[a] && s2[a])
        a += 1;
    return (s1[a] - s2[a]);
}

char *create_file1(int *fd, char *file)
{
    int flag = O_CREAT | O_RDWR | O_APPEND;

    *fd = open(file, flag, 0664);
    if (*fd == -1) {
        my_putstr("Can't create or open\n");
        return (NULL);
    }
    return (file);
}

char *create_file2(int *fd, char *file)
{
    int flag = O_CREAT | O_RDWR | O_TRUNC;

    *fd = open(file, flag, 0664);
    if (*fd == -1) {
        my_putstr("Can't create or open\n");
        return (NULL);
    }
    return (file);
}

char **tab_realloc(char **tab)
{
    char **tmp = NULL;
    int i = 0;

    for (; tab[i]; i++);
    tmp = my_malloc(sizeof(char *) * (i + 2), 2);
    for (i = 0; tab[i]; i++)
        tmp[i] = tab[i];
    free(tab);
    return (tmp);
}

char **fill_tab(int fd)
{
    char *line;
    char **tab = malloc(sizeof(char *) * 2);
    int i = 0;

    if (!tab)
        return (NULL);
    tab[1] = NULL;
    if (fd == -1)
        return (NULL);
    line = get_next_line(fd);
    tab[i] = line;
    while (line) {
        line = get_next_line(fd);
        tab = tab_realloc(tab);
        tab[++i] = line;
    }
    close(fd);
    return (tab);
}
