/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** lemin
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "ftrace.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(ftrace, test_no_params, .init = redirect_all_stdout)
{
    cr_assert_eq(ftrace(0, NULL, NULL), 84);
}

Test(ftrace, test_help, .init = redirect_all_stdout)
{
    char **av = malloc(sizeof(char *) * 3);

    av[0] = strdup("ftrace");
    av[1] = strdup("--help");
    av[2] = NULL;
    cr_assert_eq(ftrace(2, av, NULL), 0);
}

Test(ftrace, test_wrong_relative_binary, .init = redirect_all_stdout)
{
    char **av = malloc(sizeof(char *) * 3);

    av[0] = strdup("ftrace");
    av[1] = strdup("./hello_ftrace");
    av[2] = NULL;
    cr_assert_eq(ftrace(2, av, NULL), 84);
}

Test(ftrace, test_wrong_binary_format, .init = redirect_all_stdout)
{
    char **av = malloc(sizeof(char *) * 3);

    av[0] = strdup("ftrace");
    av[1] = strdup("hello_ftrace");
    av[2] = NULL;
    cr_assert_eq(ftrace(2, av, NULL), 84);
}

Test(ftrace, test_wrong_path_binary, .init = redirect_all_stdout)
{
    char **av = malloc(sizeof(char *) * 3);
    char **env = malloc(sizeof(char *) * 3);

    av[0] = strdup("ftrace");
    av[1] = strdup("hello_ftrace");
    av[2] = NULL;
    env[0] = strdup("HELLO=NULL");
    env[1] = strdup("PATH=/:/");
    env[2] = NULL;
    cr_assert_eq(ftrace(2, av, env), 84);
}

Test(ftrace, test_not_binary, .init = redirect_all_stdout)
{
    char **av = malloc(sizeof(char *) * 3);

    av[0] = strdup("ftrace");
    av[1] = strdup("../");
    av[2] = NULL;
    cr_assert_eq(ftrace(2, av, NULL), 84);
}