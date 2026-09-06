/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** loop
*/

#include "ftrace.h"

static bool loop_track(ftrace_t *ftrace, siginfo_t signal, int wstatus,
    struct user_regs_struct regs);
static void check_opcode(ftrace_t *ftrace, bool *instruct,
    struct user_regs_struct *regs);

bool loop(ftrace_t *ftrace, char **env)
{
    int wstatus = 0;
    struct user_regs_struct regs;
    siginfo_t signal;

    if ((ftrace->pid = fork()) == -1) {
        perror("fork");
        return (false);
    }
    if (ftrace->pid == 0) {
        ptrace(PT_TRACE_ME, 0, NULL, NULL);
        if (execve(ftrace->program_arguments[0],
            ftrace->program_arguments, env) == -1)
            return (false);
        return (true);
    }
    print_execve_cmd(ftrace, env);
    if (loop_track(ftrace, signal, wstatus, regs) == false)
        return (true);
    return (true);
}

static bool loop_track(ftrace_t *ftrace, siginfo_t signal, int wstatus,
    struct user_regs_struct regs)
{
    if (waitpid(ftrace->pid, &wstatus, 0) == -1 &&
        !condition_loop(wstatus, false))
        return (true);
    for (bool op = false; condition_loop(wstatus, true)
        ; op = false, signal.si_signo = 0) {
        if (ptrace(PTRACE_GETREGS, ftrace->pid, 0, &regs) == -1)
            return (false);
        check_opcode(ftrace, &op, &regs);
        if (ptrace(PTRACE_GETSIGINFO, ftrace->pid, NULL, &signal) == -1)
            exit(84);
        if (ptrace(PTRACE_SINGLESTEP, ftrace->pid, 0, 0) == -1 ||
            waitpid(ftrace->pid, &wstatus, 0) == -1)
            return (false);
        if (!condition_loop(wstatus, true))
            break;
        if (op)
            display_return_syscall(&regs, false);
        handle_signaux(&signal);
    }
    return (true);
}

static void check_opcode(ftrace_t *trac, bool *instruct,
    struct user_regs_struct *regs)
{
    errno = 0;
    trac->opcode = ptrace(PTRACE_PEEKTEXT, trac->pid, regs->rip, 0);
    if (errno) {
        perror("ptrace_peektext");
        exit(84);
    }
    errno = 0;
    trac->list = handle_display_function(trac, regs);
    if ((trac->opcode == 0xCB) || (trac->opcode == 0xCA) || (trac->opcode ==
        0xCF) || (trac->opcode == 0xC2) || (trac->opcode == 0xC3))
        trac->list = handle_return_funct(trac);
    if (trac->opcode == 0x050F && regs->rax < 367) {
        *instruct = true;
        display_syscall(regs, tab_64[regs->rax]);
        return;
    }
}