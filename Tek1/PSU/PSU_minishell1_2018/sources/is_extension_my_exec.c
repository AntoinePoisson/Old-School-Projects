/*
** EPITECH PROJECT, 2019
** is_extension_my_exec.c
** File description:
** is_extension_my_exec
*/

#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "my_struct.h"
#include "gnl.h"
#include "my_lib.h"

void display(void);
int display_env(var_t *var);
int my_exit(var_t *var, char *arg_nbr);
int my_cd(var_t *var);
int my_unsetenv(var_t *var);
int my_setenv(var_t *var);
void destroy_arg_two_d(var_t *var);
char my_stat(char const *dir, int cas);
int research_signal(int signal, int w);
int research_signal_two(int signal, int w);
int research_signal_three(int signal, int w);
int research_signal_ext_one(int signal, int w);
int research_signal_ext_two(int signal, int w);

int check_type_bin(var_t *var)
{
    if (my_stat(var->arg_two_d[0], 0) == 'd') {
        write(2, var->arg_two_d[0], my_strlen(var->arg_two_d[0]));
        write(2, ": Permission denied.\n", 21);
        return (1);
    }
    return (0);
}

int print_signal(char *str, int wstatus)
{
    write(2, str, my_strlen(str));
    if (!(WCOREDUMP(wstatus) == 0))
        write(2, " (core dumped)", 14);
    write(2, "\n", 1);
    return (1);
}

int check_echec_exec(int signal, int wstatus)
{
    if (research_signal(signal, wstatus) == 1)
        return (0);
    if (research_signal_two(signal, wstatus) == 1)
        return (0);
    if (research_signal_three(signal, wstatus) == 1)
        return (0);
    if (research_signal_ext_one(signal, wstatus) == 1)
        return (0);
    if (research_signal_ext_two(signal, wstatus) == 1)
        return (0);
    if (WCOREDUMP(wstatus) != 0)
        write(2, "(core dumped)\n", 14);
    return (0);
}
