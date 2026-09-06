/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** fork_strace
*/

#include "../includes/strace.h"
#include "../includes/syscall.h"

pid_t pid;
struct user_regs_struct regs;

int display_str_param(bool first, long long value)
{
    int i = 0;
    int j = 0;

    if (get_strace(NULL)->verbose) {
        i = first ? fprintf(stdout, "\"") : fprintf(stdout, ", \"");
        while (j < 32) {
            char tmp = ptrace(PTRACE_PEEKDATA, pid, value + j);
            if (errno || !tmp)
                break;
            i += print_special(tmp);
            j += 1;
        }
        i += fprintf(stdout, "\"");
        if (j >= 32)
            i += fprintf(stdout, "...");
    } else {
        i = first ? 0 : fprintf(stdout, ", ");
        i += fprintf(stdout, "0x%llx", value);
    }
    return (i);
}

void display_sys_call_ret(struct user_regs_struct regs,
    tab_syscall_t element, int nbr_charac, bool unknown)
{
    fprintf(stdout, ")");
    if (nbr_charac >= 40) {
        print_ret(unknown, regs.rax, element.ret_type, true);
    } else {
        while (nbr_charac < 40) {
            fprintf(stdout, " ");
            nbr_charac++;
        }
        print_ret(unknown, regs.rax, element.ret_type, false);
    }
}

void is_extension_loop(int *n_display, strace_t *trace,
char * const *env, bool *instruct)
{
    static int first = 0;

    if (first == 1)
        *instruct = true;
    else
        first = 1;
    display_sys_call(regs, n_display, trace, env);
}

int loop_trace(int wst, int n_display, strace_t *trace,
char * const *env)
{
    unsigned short opcode = 0;

    if (waitpid(pid, &wst, 0) && cond_loop(wst, regs, n_display, true))
        return (0);
    for (bool instruct = false; !cond_loop(wst, regs, n_display, false);
        instruct = false) {
        ptrace(PTRACE_GETREGS, pid, 0, &regs);
        opcode = ptrace(PTRACE_PEEKTEXT, pid, regs.rip, 0);
        if (opcode == 0x80CD || opcode == 0x050F)
            is_extension_loop(&n_display, trace, env, &instruct);
        if (ptrace(PTRACE_SINGLESTEP, pid, 0, 0) == -1)
            return (84);
        if (waitpid(pid, &wst, 0) && cond_loop(wst, regs, n_display, false))
            break;
        if (instruct) {
            ptrace(PTRACE_GETREGS, pid, 0, &regs);
            display_sys_call(regs, &n_display, trace, env);
        }
    }
    return (0);
}

int fork_strace(strace_t *trace, char * const *env)
{
    int wstatus = 0;
    int size_display = 0;

    get_strace(trace);
    if ((pid = fork()) == -1) {
        perror("fork");
        return (84);
    }
    if (pid == 0) {
        ptrace(PT_TRACE_ME, 0, NULL, NULL);
        if (trace->pid == -1 &&
            execve(trace->path, trace->program_arguments, env) == -1)
            exit(84);
        exit(0);
    } else
        return (loop_trace(wstatus, size_display, trace, env));
}