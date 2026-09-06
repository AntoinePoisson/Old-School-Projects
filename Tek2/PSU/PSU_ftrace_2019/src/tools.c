/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** tools
*/

#include "ftrace.h"

ftrace_t *get_struct(void)
{
    static ftrace_t ftrace = {-1, NULL, NULL, NULL,
        NULL, NULL, 0, NULL, NULL, false, 0, NULL};

    return (&ftrace);
}

int destroy_structure(ftrace_t *ftrace)
{
    if (ftrace) {
    }
    return (0);
}

void print_execve_cmd(ftrace_t *ftrace, char **env)
{
    int nbr_env = 0;

    fprintf(stdout, "Syscall execve(\"%s\", [", ftrace->program_arguments[0]);
    fprintf(stdout, "\"%s\"", ftrace->av_one);
    for (int i = 1; ftrace->program_arguments[i]; i++) {
        fprintf(stdout, ", \"%s\"",
            ftrace->program_arguments[i]);
    }
    for (int i = 0; env && env[i]; i++, nbr_env++) {
    }
    fprintf(stdout, "], [/* %d vars */]) = 0\n", nbr_env);
}

bool condition_loop(int wstatus, bool condition)
{
    ftrace_t *ftrace = get_struct();
    struct user_regs_struct regs;

    if (WIFEXITED(wstatus)) {
        if (condition) {
            display_return_syscall(&regs, true);
            while (handle_return_funct(ftrace) != NULL);
            fprintf(stdout, "+++ exited with 0x%x +++\n",
            WEXITSTATUS(wstatus));
            ptrace(PTRACE_KILL, ftrace, NULL, NULL);
        }
        return (false);
    }
    if (WIFSIGNALED(wstatus)) {
        fprintf(stdout, "Receive Signaux\n");
        return (false);
    }
    return (true);
}