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
#include "my_shell.h"

int check_type_bin(variable_t const *var)
{
    if (my_stat(var->arg_two_d[0], 0) == 'd') {
        write(2, var->arg_two_d[0], my_strlen(var->arg_two_d[0]));
        write(2, ": Permission denied.\n", 21);
        return (1);
    }
    return (0);
}

int print_signal(char const *str, int wstatus)
{
    write(2, str, my_strlen(str));
    if (WCOREDUMP(wstatus) != 0)
        write(2, " (core dumped)", 14);
    write(2, "\n", 1);
    return (1);
}

static int return_value_check_echec_exe(variable_t *var, int wstatus, int cas)
{
    if (cas == 0 && wstatus <= 0)
        return (0);
    if (cas == 0 && wstatus == 40704) {
        my_printf("%s: Exec format error. Wrong Architecture.\n",
            var->arg_two_d[0]);
        return (1);
    }
    return (wstatus);
}

int check_echec_exec(variable_t *var, int signal, int wstatus)
{
    int cas = 0;

    if (cas == 0 && research_signal(signal, wstatus) == 1)
        cas = 1;
    if (cas == 0 && research_signal_two(signal, wstatus) == 1)
        cas = 1;
    if (cas == 0 && research_signal_three(signal, wstatus) == 1)
        cas = 1;
    if (cas == 0 && research_signal_ext_one(signal, wstatus) == 1)
        cas = 1;
    if (cas == 0 && research_signal_ext_two(signal, wstatus) == 1)
        cas = 1;
    if (cas == 0 && WCOREDUMP(wstatus) != 0)
        write(2, "(core dumped)\n", 14);
    return (return_value_check_echec_exe(var, wstatus, cas));
}
