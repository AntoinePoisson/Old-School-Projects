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
int check_lenght_size(struct stat sb, int nbr);
char *find_name(char *file);
char is_type(struct stat sb);
void display_link(char *av, struct stat sb);
void name(char *av, int nbr, struct stat sb_two);

void nbr_hard_link(struct stat sb)
{
    my_putstr(" ");
    my_put_long(sb.st_nlink);
}

void size(struct stat sb)
{
    int size = check_lenght_size(sb, 4);

    my_putstr(" ");
    for (int i = check_lenght_size(sb, 6); i < size; i++)
        my_putstr(" ");
    my_put_long(sb.st_size);
}

char total(flag_t *flag, int cas)
{
    struct stat sb;
    long long result = 0;
    char *link = NULL;
    int nbr = 4;

    if (cas == 6)
        nbr++;
    write(1, "total ", 6);
    for (int i = 0; i < flag->arg->nbr_element; i++)
        if (flag->arg->result[i][0] != '.') {
            link = link_directory(flag->arg->result[i], nbr, flag);
            stat(link, &sb);
            result += sb.st_blocks;
        }
    my_put_long(result / 2);
    write(1, "\n", 1);
    return ('0');
}

void uid(struct stat sb)
{
    struct passwd *pwd;

    my_putstr(" ");
    if ((pwd = getpwuid(sb.st_uid)) != NULL)
        my_putstr(pwd->pw_name);
    else
        my_putstr("Error");
}

void gid(struct stat sb)
{
    struct group *grp;

    my_putstr(" ");
    if ((grp = getgrgid(sb.st_gid)) != NULL)
        my_putstr(grp->gr_name);
    else
        my_putstr("Error");
}