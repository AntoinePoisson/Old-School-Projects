/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** handle_syscall
*/

#include "ftrace.h"

static void print_param(long long value, type_param_t type, bool first);

void display_syscall(struct user_regs_struct *regs, tab_syscall_t element)
{
    fprintf(stdout, "Syscall %s(", element.sys_name);
    if (0 < element.nbr_param)
        print_param(regs->rdi, element.param_type[0], true);
    if (1 < element.nbr_param)
        print_param(regs->rsi, element.param_type[1], false);
    if (2 < element.nbr_param)
        print_param(regs->rdx, element.param_type[2], false);
    if (3 < element.nbr_param)
        print_param(regs->r10, element.param_type[3], false);
    if (4 < element.nbr_param)
        print_param(regs->r8, element.param_type[4], false);
    if (5 < element.nbr_param)
        print_param(regs->r9, element.param_type[5], false);
    fflush(stdout);
}

void display_return_syscall(struct user_regs_struct *regs, bool unknown)
{
    ftrace_t *ftrace = get_struct();
    tab_syscall_t el;

    ptrace(PTRACE_GETREGS, ftrace->pid, 0, regs);
    fprintf(stdout, ") = ");
    if (!unknown && !(regs->orig_rax < 367)) {
        fprintf(stdout, "0x0\n");
        return;
    }
    el = tab_64[unknown ? 0 : regs->orig_rax];
    if (el.ret_type == INT)
        fprintf(stdout, unknown ? "?\n" : "0x%x\n", (unsigned int)regs->rax);
    else if (el.ret_type == PTR || el.ret_type == LONG)
        fprintf(stdout, unknown ? "?\n" : "0x%x\n", (unsigned int)regs->rax);
    else
        fprintf(stdout, "0x0\n");
}

static void print_param(long long value, type_param_t type, bool first)
{
    if (type == INT || type == PTR || type == STR || type == MOD)
        fprintf(stdout, first ? "0x%x" : ", 0x%x", (unsigned int)value);
}