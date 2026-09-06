/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** pid exists
*/

#include "strace.h"

program_status_t check_nbr_bit(strace_t *strace)
{
    if (strace) {
    }
    return (STRACE_CONTINUE);
}

program_status_t __attribute__ ((noinline)) __attribute__ ((nonnull(1, 2)))
pid_exists(const char *pid, strace_t *strace)
{
    struct stat sts;
    char *tmp = my_concat("/proc/", pid);

    if (!tmp) {
        fprintf(stderr, "Memory error occured!\n");
        return (STRACE_EXIT_ERROR);
    }
    if (stat(tmp, &sts) == -1 && errno == ENOENT) {
        fprintf(stderr, "The given pid doesn't exists\n");
        free(tmp);
        return (STRACE_EXIT_ERROR);
    }
    free(tmp);
    strace->pid = atoi(pid);
    strace->execve = false;
    return (STRACE_CONTINUE);
}