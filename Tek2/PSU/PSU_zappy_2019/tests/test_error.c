/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** lemin
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "zappy.h"
#include <string.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(server_start, test_no_params, .init = redirect_all_stdout)
{
    cr_assert_eq(server_start(0, NULL, NULL), 84);
}

Test(server_start, test_params_bullshit, .init = redirect_all_stdout)
{
    char **av = malloc(sizeof(char) * 5);

    av[0] = strdup("zappy_server");
    av[1] = strdup("zappy_server");
    av[2] = strdup("zappy_server");
    av[3] = strdup("zappy_server");
    av[4] = NULL;
    cr_assert_eq(server_start(4, av, NULL), 84);
}

Test(server_start, test_params_0_player, .init = redirect_all_stdout)
{
    char **av = malloc(sizeof(char) * 11);
    char **env = malloc(sizeof(char) * 2);

    env[0] = strdup("PATH:0");
    env[1] = NULL;
    av[0] = strdup("-p");
    av[1] = strdup("4201");
    av[2] = strdup("-x");
    av[3] = strdup("10");
    av[4] = strdup("-y");
    av[5] = strdup("10");
    av[6] = strdup("-n");
    av[7] = strdup("name1");
    av[8] = strdup("-c");
    av[9] = strdup("0");
    av[10] = NULL;
    cr_assert_eq(server_start(10, av, env), 84);
}
