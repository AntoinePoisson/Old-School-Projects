/*
** EPITECH PROJECT, 2019
** my_stat
** File description:
** my_stat
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>
#include "my_lib.h"
#include "my_struct.h"

int my_put_long(long nb);
char *my_itoa(int, int);
char *link_directory(char *directory, int nbr, flag_t *flag);

int check_lenght_size(struct stat sb, int nbr)
{
    static int size = 0;
    char *size_nbr = NULL;

    if (nbr == 3) {
        size_nbr = my_itoa(sb.st_size, 0);
        if (size < my_strlen(size_nbr))
            size = my_strlen(size_nbr);
    }
    if (nbr == 4) {
        nbr = size;
        return (nbr);
    }
    if (nbr == 5)
        size = 0;
    if (nbr == 6) {
        size_nbr = my_itoa(sb.st_size, 0);
        nbr = my_strlen(size_nbr);
    }
    return (nbr);
}
char *find_name(char *file)
{
    int size = my_strlen(file);
    char *result = malloc(sizeof(char) * size);
    int i_two = 0;

    size--;
    if (size != 1 && file[size] == '/')
        size--;
    for (int i = size; file[i] != '/' && i >= 0; i--, i_two++) {
        result[i_two] = file[i];
    }
    result[i_two] = '\0';
    my_revstr(result);
    return (result);
}

char is_type(struct stat sb)
{
    switch (sb.st_mode & S_IFMT) {
        case S_IFDIR:
            return ('d');
        case S_IFREG:
            return ('f');
        case S_IFLNK:
            return ('l');
        default:
            return ('u');
    }
    return ('e');
}

void display_link(char *av, struct stat sb)
{
    char *buf;
    ssize_t buf_size;

    buf_size = sb.st_size;
    my_putstr(" -> ");
    if (sb.st_size == 0)
        buf_size = 99999999;
    if ((buf = malloc(buf_size)) == NULL) {
        write(2, "Error malloc\n", 13);
        exit (84);
    }
    if (readlink(av, buf, buf_size) == -1) {
        perror("readlink");
        exit (84);
    }
    my_putstr(buf);
    free(buf);
}

void name(char *av, int nbr, struct stat sb_two)
{
    if (nbr == -24)
        av = find_name(av);
    my_putstr(" ");
    my_putstr(av);
    if (is_type(sb_two) == 'l') {
        display_link(av, sb_two);
    }
}
