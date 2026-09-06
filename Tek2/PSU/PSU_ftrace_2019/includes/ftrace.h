/*
** EPITECH PROJECT, 2019
** PSU_strace_2019
** File description:
** ftrace.hpp
*/

#ifndef FTRACE_HPP
#define FTRACE_HPP

    // Includes Systeme
#include <sys/time.h>
#include <sys/resource.h>
#include <ctype.h>
#include <sys/syscall.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>

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

#include <sys/mman.h>
#include <elf.h>
#include <fcntl.h>

#include "syscall.h"


    // Structure
typedef struct funct_s
{
    char *name;
    struct funct_s *next;
} funct_t;

typedef struct strace_f {
    pid_t pid;

    Elf64_Ehdr *ehdr;
    Elf64_Shdr *shdr;
    Elf64_Sym *start;
    Elf64_Sym *end;
    char *strtab;
    int shnum;
    char **program_arguments;
    char *av_one;
    bool tab_sym;
    unsigned short opcode;
    funct_t *list;
} ftrace_t;


    // Prototype
int ftrace(int ac, char *av[], char *env[]);
ftrace_t *get_struct(void);
bool check_arg(int ac, char **av, char **env, ftrace_t *ftrace);
bool check_tab_sym(ftrace_t *ftrace, char *path);
bool loop(ftrace_t *ftrace, char **env);
int destroy_structure(ftrace_t *ftrace);
void print_execve_cmd(ftrace_t *ftrace, char **env);
bool condition_loop(int wstatus, bool condition);
void display_syscall(struct user_regs_struct *regs, tab_syscall_t element);
void display_return_syscall(struct user_regs_struct *regs, bool unknown);
void handle_signaux(siginfo_t *signal);
char **set_program(char *binary, char **av);
char **my_str_to_word_array(char const *str, char const *delimiter);
funct_t *handle_display_function(ftrace_t *ftrace,
    struct user_regs_struct *regs);
funct_t *handle_return_funct(ftrace_t *ftrace);

#endif