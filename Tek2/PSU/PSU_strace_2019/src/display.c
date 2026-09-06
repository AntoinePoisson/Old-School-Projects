/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** display
*/

#include "strace.h"
#include "syscall.h"

bool flag_s;

void display_sys_call(struct user_regs_struct regs, int *size,
strace_t *trace, char * const *env)
{
    static bool first = true;
    static bool ret = true;
    static int nbr_charac = 0;
    flag_s = trace->verbose;

    if (trace->execve || regs.orig_rax == 59) {
        nbr_charac = display_execve(trace, env);
    } else if (!ret || first) {
        display_sys_call_param(regs, tab_64[regs.rax], &nbr_charac);
        fflush(stdout);
    }
    if (ret || first) {
        display_sys_call_ret(regs, tab_64[regs.orig_rax],
        nbr_charac + 1, false);
        nbr_charac = 0;
    }
    *size = nbr_charac;
    first = false;
    ret = !ret;
}

void print_ret(bool unknown, long long value,
    type_param_t type, bool cas)
{
    if (cas)
        fprintf(stdout, " ");
    if (type == INT) {
        fprintf(stdout, unknown ? "= ?" : flag_s ? "= %lld" :
        "= 0x%llx", value < 0 ? -1 : value);
        if (!unknown && value < 0 && value > -128) {
            fflush(stdout);
            fprintf(stdout, " %s (%s)\n", tab_errno[-value - 1].type_name,
            tab_errno[-value - 1].message);
        } else
            fprintf(stdout, "\n");
    }
    else if (type == PTR || type == LONG)
        fprintf(stdout, unknown? "= ?\n" : "= 0x%llx\n", value);
    else
        fprintf(stdout, "= 0\n");
}

void display_sys_call_param(struct user_regs_struct regs,
    tab_syscall_t element, int *nbr_charac)
{
    *nbr_charac = fprintf(stdout, "%s(", element.sys_name);
    if (0 < element.nbr_param)
        *nbr_charac += print_param(regs.rdi, element.param_type[0], true);
    if (1 < element.nbr_param)
        *nbr_charac += print_param(regs.rsi, element.param_type[1], false);
    if (2 < element.nbr_param)
        *nbr_charac += print_param(regs.rdx, element.param_type[2], false);
    if (3 < element.nbr_param)
        *nbr_charac += print_param(regs.r10, element.param_type[3], false);
    if (4 < element.nbr_param)
        *nbr_charac += print_param(regs.r8, element.param_type[4], false);
    if (5 < element.nbr_param)
        *nbr_charac += print_param(regs.r9, element.param_type[5], false);
}

int print_param(long long value, type_param_t type, bool first)
{
    unsigned int size = 0;

    if ((type == STR && !value) || (type == PTR && !value))
        size = fprintf(stdout, first ? "NULL"  : ", NULL");
    if (type == INT)
        size = fprintf(stdout, flag_s ? first ? "%lld" : ", %lld" :
        first ? "0x%llx" : ", 0x%llx", value);
    if (type == PTR && value)
        size = fprintf(stdout, first ? "0x%llx" : ", 0x%llx", value);
    if (type == STR && value)
        size = display_str_param(first, value);
    if (type == MOD)
        size = fprintf(stdout, flag_s ? first ? "%lld" : ", %lld" :
        first ? "0x%llx" : ", 0x%llx", value);
    return (size);
}

int display_execve(strace_t *trace, char * const *env)
{
    int size_display = 0;
    int count_env = 0;

    size_display = fprintf(stdout, "execve(\"%s\", [", trace->path);
    for (int i = 0; trace->program_arguments[i]; i++) {
        size_display += fprintf(stdout, i ? ", \"%s\"" : "\"%s\"",
            trace->program_arguments[i]);
    }
    for (int i = 0; env && env[i]; i++, count_env++) {
    }
    size_display += fprintf(stdout, "], %p /* %d vars */", env, count_env);
    trace->execve = false;
    return (size_display);
}