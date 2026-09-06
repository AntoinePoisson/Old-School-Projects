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
void nbr_hard_link(struct stat sb);
void size(struct stat sb);
char total(flag_t *flag, int cas);
void uid(struct stat sb);
void gid(struct stat sb);
void gestion_type(struct stat sb);
void is_extension_my_time_two(char *stockage, int cas);
void is_extension_my_time(char *time, char *stockage, int i);
void my_time(struct stat sb);
void permission(struct stat sb);

static void is_extension_my_stat(struct stat sb, int nbr, char *av)
{
    permission(sb);
    nbr_hard_link(sb);
    uid(sb);
    gid(sb);
    size(sb);
    my_time(sb);
    name(av, nbr, sb);
}

char my_stat(char *av, int nbr, flag_t *flag)
{
    struct stat sb;
    char *link = av;

    if (nbr != -42 && nbr != -24 && nbr != 1)
        link = link_directory(av, 4, flag);
    stat(link, &sb);
    if (nbr < 0 && nbr != -42) {
        is_extension_my_stat(sb, nbr, av);
    }
    if (nbr == 1 || nbr == -42)
        return (is_type(sb));
    if (nbr == 2 || nbr == 6)
        return (total(flag, nbr));
    if (nbr == 3 || nbr == 4 || nbr == 5)
        check_lenght_size(sb, nbr);
    return ('0');
}
