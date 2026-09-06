/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** main
*/

#include "ftrace.h"

int ftrace(int ac, char *av[], char *env[])
{
    ftrace_t *ftrace = get_struct();

    if (check_arg(ac, av, env, ftrace) == false) {
        fprintf(stderr, "Wrong argument\n");
        return (84);
    }
    if (check_tab_sym(ftrace, ftrace->program_arguments[0]) == false) {
        fprintf(stderr, "Probleme Parsing ELF file\n");
        return (84);
    }
    if (loop(ftrace, env) == false)
        return (84);
    return (destroy_structure(ftrace));
}