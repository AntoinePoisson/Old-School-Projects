/*
** EPITECH PROJECT, 2019
** my_stat
** File description:
** my_stat
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my_shell.h"

static char is_type(struct stat sb)
{
    switch (sb.st_mode & S_IFMT) {
        case S_IFDIR:
            return ('d');
        case S_IFREG:
            return ('f');
        case S_IFLNK:
            return ('l');
        default:
            return ('e');
    }
    return ('e');
}

static char is_permission(char const *dir)
{
    if (access(dir, R_OK) == -1)
        return ('e');
    return ('x');
}

char my_stat(char const *dir, int cas)
{
    struct stat sb;

    if (dir == NULL)
        return ('e');
    if (stat(dir, &sb) == -1)
        return ('e');
    if (cas == 0)
        return (is_type(sb));
    if (cas == 1)
        return (is_permission(dir));
    return ('e');
}
