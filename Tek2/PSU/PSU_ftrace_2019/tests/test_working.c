/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** lemin
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ftrace.h"

void redirect_all_stdout(void);

Test(ftrace, test_relative, .init = redirect_all_stdout)
{
    char **av = malloc(sizeof(char *) * 4);

    av[0] = strdup("ftrace");
    av[1] = strdup("./ftrace");
    av[2] = strdup("--help");
    av[3] = NULL;
    cr_assert_eq(ftrace(3, av, NULL), 0);
}

extern char **environ;

Test(ftrace, test_path, .init = redirect_all_stdout)
{
    char **av = malloc(sizeof(char *) * 4);

    av[0] = strdup("ftrace");
    av[1] = strdup("cat");
    av[2] = strdup("ok");
    av[3] = NULL;
    cr_assert_eq(ftrace(3, av, environ), 0);
}