/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** handle_signals
*/

#include "ftrace.h"

void handle_signaux(siginfo_t *signal)
{
    if (signal->si_signo == 0 || signal->si_signo == 5)
        return;
    for (int i = 0; tab_ftace_sig[i].message; i++) {
        if (tab_ftace_sig[i].numero == signal->si_signo
            && tab_ftace_sig[i].fatal == false) {
            fflush(stdout);
            fprintf(stdout, "Received signal %s\n", tab_ftace_sig[i].message);
            return;
        }
        if (tab_ftace_sig[i].numero == signal->si_signo
            && tab_ftace_sig[i].fatal == true) {
            fflush(stdout);
            fprintf(stdout, "Received signal %s\n", tab_ftace_sig[i].message);
            exit(0);
        }
    }
}