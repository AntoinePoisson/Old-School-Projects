/*
** EPITECH PROJECT, 2019
** PSU_strace_2019
** File description:
** main.c
*/

#include "strace.h"

static bool __attribute__ ((noinline)) __attribute__ ((nonnull(1)))
my_strisnum(const char *str)
{
    if (strlen(str) < 1)
        return (false);
    for (__u_int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return (false);
    return (true);
}

static inline program_status_t __attribute__ ((always_inline))
help_message(const program_status_t status)
{
    if (status == STRACE_EXIT_ERROR)
        fprintf(stderr, "USAGE: ./strace [-s] [-p <pid>|<command>]\n");
    else
        fprintf(stdout, "USAGE: ./strace [-s] [-p <pid>|<command>]\n");
    return (status);
}

static inline program_status_t __attribute__ ((always_inline))
pid_message(void)
{
    fprintf(stderr, "No PID provided after '-p'\n");
    return (STRACE_EXIT_ERROR);
}

static program_status_t __attribute__ ((noinline)) parse_arguments
(const int ac, const char **av, char * const *env, strace_t *strace)
{
    for (int32_t i = 1; av[i]; i++) {
        if (!strcmp(av[i], "--help") || !strcmp(av[i], "-h"))
            return (help_message(STRACE_EXIT_NORMALLY));
        if (!strncmp(av[i], "-", 1)
        && strcmp(av[i], "-s") && strcmp(av[i], "-p"))
            return (help_message(STRACE_EXIT_ERROR));
        if (!strcmp(av[i], "-s") && (strace->verbose || !av[i + 1]))
            return (help_message(STRACE_EXIT_ERROR));
        else if (!strcmp(av[i], "-s")) {
            strace->verbose = true;
            continue;
        }
        if (!strcmp(av[i], "-p")
        && (!av[i + 1] || ac - 1 > i + 1 || !my_strisnum(av[i + 1])))
            return (pid_message());
        else if (!strcmp(av[i], "-p"))
            return (pid_exists(av[i + 1], strace));
        return (exists_in_path(&av[i], env, strace));
    }
    return (STRACE_EXIT_ERROR);
}

int main(const int ac, const char **av, char * const *env)
{
    strace_t strace = {-1, false, true, NULL, NULL};
    program_status_t program_status;

    if (ac == 1) {
        fprintf(stdout, "strace: must have PROG [ARGS] or -p PID\n");
        fprintf(stdout, "Try 'strace -h' for more information.\n");
        return (0);
    }
    program_status = parse_arguments(ac, av, env, &strace);
    if (program_status != STRACE_CONTINUE)
        return ((program_status == STRACE_EXIT_NORMALLY) ? 0 : 84);
    program_status = check_nbr_bit(&strace);
    if (program_status != STRACE_CONTINUE)
        return ((program_status == STRACE_EXIT_NORMALLY) ? 0 : 84);
    return (fork_strace(&strace, env));
}