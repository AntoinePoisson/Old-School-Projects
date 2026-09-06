/*
** EPITECH PROJECT, 2018
** mprintf
** File description:
** mprintf.h
*/

#ifndef MPRINTF_H
#define MPRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct arg_s {
    unsigned int nb;
    unsigned int value;
    char c;
} arg_t;

static const int NB_FUNCT = 14;
static const char STRING_INDEX[] = "rsStdiuobxXfpl";
static const char flags[17][2] = {"%d", "%i", "%c", "%o", "%u", "%b", "%X",
                                "%x", "%S", "%s", "%t", "%f", "%p", "%%",
                                "%h", "%l", "%r"};

void mp_check_funct(char flag, va_list *list, int (*array_ptr[NB_FUNCT])());
int mp_convert_nb(arg_t arg);
int mp_mput_double(double nb);
int mp_disp_rev(char *str);
int mp_double_array(char const **str);
void mp_mput(char c);
int mp_mputhexa(char const *str);
int mp_mput_long(long long nb);
int mp_mput_nbr(int nb);
int mp_mputstr(char const *s);
int mp_mput_un(unsigned int nb);
char *mp_mrevstr(char *s);
int mp_mstrcmp(char const *s1, char const *s2);
int mp_mstrlen(char const *s);
int mp_disp_adress(void const *point);
int mprintf(char const *str, ...);

#endif
