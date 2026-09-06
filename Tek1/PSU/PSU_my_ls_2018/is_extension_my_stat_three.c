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

void gestion_type(struct stat sb)
{
    char type = is_type(sb);

    if (type == 'f')
        write(1, "-", 1);
    if (type == 'l')
        write(1, "l", 1);
    if (type == 'd')
        write(1, "d", 1);
    if (type != 'l' && type != 'd' && type != 'f')
        write(1, "-", 1);
}

void is_extension_my_time_two(char *stockage, int cas)
{
    if (cas == 1) {
        if (my_strlen(stockage) == 1)
            write(1, " ", 1);
        my_putstr(stockage);
    }
}

void is_extension_my_time(char *time, char *stockage, int i)
{
    int count = 0;

    for (int i_two = 0; count != 2; i_two++, i++) {
        if (time[i] == ':')
            count++;
        if (count != 2) {
            stockage[i_two] = time[i];
            stockage[i_two + 1] = '\0';
        }
    }
    my_putstr(stockage);
    for (; time[i - 1] != ' '; i++);
    for (int i_two = 0; time[i] != '\n'; i++, i_two++) {
        stockage[i_two] = time[i];
        stockage[i_two + 1] = '\0';
    }
}

void my_time(struct stat sb)
{
    char *time = ctime(&sb.st_mtime);
    char stockage[my_strlen(time)];
    int i = 0;

    write(1, " ", 1);
    for (; time[i] != ' '; i++);
    for (; !(time[i] >= 'A' && time[i] <= 'Z'); i++);
    for (int i_two = 0; time[i] != ' '; i++, i_two++) {
        stockage[i_two] = time[i];
        stockage[i_two + 1] = '\0';
    }
    my_putstr(stockage);
    write(1, " ", 1);
    for (; !(time[i] >= '0' && time[i] <= '9'); i++);
    for (int i_two = 0; time[i] != ' '; i++, i_two++) {
        stockage[i_two] = time[i];
        stockage[i_two + 1] = '\0';
    }
    is_extension_my_time_two(stockage, 1);
    is_extension_my_time(time, stockage, i);
}

void permission(struct stat sb)
{
    gestion_type(sb);
    my_putstr((sb.st_mode & S_IRUSR) ? "r" : "-");
    my_putstr((sb.st_mode & S_IWUSR) ? "w" : "-");
    my_putstr((sb.st_mode & S_IXUSR) ? "x" : "-");
    my_putstr((sb.st_mode & S_IRGRP) ? "r" : "-");
    my_putstr((sb.st_mode & S_IWGRP) ? "w" : "-");
    my_putstr((sb.st_mode & S_IXGRP) ? "x" : "-");
    my_putstr((sb.st_mode & S_IROTH) ? "r" : "-");
    my_putstr((sb.st_mode & S_IWOTH) ? "w" : "-");
    my_putstr((sb.st_mode & S_IXOTH) ? "x" : "-");
}