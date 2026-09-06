/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** lemin
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "zappy.h"

void redirect_all_stdout(void);

Test(server_start, test_params_work, .init = redirect_all_stdout)
{
    char **av = malloc(sizeof(char) * 11);
    char **env = malloc(sizeof(char) * 2);

    env[0] = strdup("PATH:0");
    env[1] = NULL;
    av[0] = strdup("-p");
    av[1] = strdup("4202");
    av[2] = strdup("-x");
    av[3] = strdup("10");
    av[4] = strdup("-y");
    av[5] = strdup("10");
    av[6] = strdup("-n");
    av[7] = strdup("name1");
    av[8] = strdup("-c");
    av[9] = strdup("2");
    av[10] = NULL;
    cr_assert_eq(server_start(10, av, env), 84);
}