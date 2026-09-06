/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** tool
*/

#include "../includes/strace.h"
#include "../includes/syscall.h"

strace_t *get_strace(strace_t *strace)
{
    static strace_t *strace_static = NULL;

    if (strace)
        strace_static = strace;
    return (strace_static);
}

int print_special(char c)
{
    switch (c) {
        case '\a': return (fprintf(stdout, "\\a"));
        case '\b': return (fprintf(stdout, "\\b"));
        case '\t': return (fprintf(stdout, "\\t"));
        case '\n': return (fprintf(stdout, "\\n"));
        case '\v': return (fprintf(stdout, "\\v"));
        case '\f': return (fprintf(stdout, "\\f"));
        case '\r': return (fprintf(stdout, "\\r"));
        default: return (fprintf(stdout, isprint(c) ? "%c" : "\\%03o", c));
    }
}