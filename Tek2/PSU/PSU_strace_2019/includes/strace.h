/*
** EPITECH PROJECT, 2019
** PSU_strace_2019
** File description:
** strace.hpp
*/

#ifndef STRACE_HPP
#define STRACE_HPP


#include <sys/time.h>
#include <sys/resource.h>
#include <ctype.h>
#include <sys/syscall.h> 
#include <sys/user.h>
#include <sys/wait.h>

#include <math.h>
#include <libelf.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>

#include "syscall.h"

typedef enum {
    STRACE_CONTINUE,
    STRACE_EXIT_NORMALLY,
    STRACE_EXIT_ERROR
} program_status_t;

typedef struct strace_s {
    pid_t pid;
    bool verbose;
    bool execve;
    char **program_arguments;
    char *path;
} strace_t;

char *my_concat(const char *path, const char *file);

program_status_t __attribute__ ((noinline)) __attribute__ ((nonnull(1, 3)))
exists_in_path(const char **av, char * const *env, strace_t *strace);

program_status_t __attribute__ ((noinline)) __attribute__ ((nonnull(1, 2)))
pid_exists(const char *pid, strace_t *strace);

int fork_strace(strace_t *trace, char * const *env);
program_status_t check_nbr_bit(strace_t *strace);


void display_sys_call(struct user_regs_struct regs, int *size,
strace_t *trace, char * const *env);

void print_ret(bool unknown, long long value,
    type_param_t type, bool cas);

void display_sys_call_param(struct user_regs_struct regs,
    tab_syscall_t element, int *nbr_charac);

int print_param(long long value, type_param_t type, bool first);

void display_sys_call_ret(struct user_regs_struct regs,
    tab_syscall_t element, int nbr_charac, bool unknown);

int display_str_param(bool first, long long value);

int display_execve(strace_t *trace, char * const *env);

bool cond_loop(int wstatus, struct user_regs_struct regs,
    int size_display, bool condition);

int print_special(char c);

strace_t *get_strace(strace_t *strace);


#endif