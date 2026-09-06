/*
** EPITECH PROJECT, 2019
** NWP_myteams_2019
** File description:
** unit_tests.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my_teams.h"
#include "data_base.h"

Test(server, my_teams_server)
{
    server_t server;

    server.sock.fd = -1;
    cr_assert_eq(my_teams_server("nop"), Err);
    cr_expect_eq(handle_new_client(&server), Err);
}

Test(server, init_server)
{
    server_t server;

    cr_assert_eq(init_server(&server, "8085"), Ok);
    cr_assert_eq(server.sock.len, sizeof(struct sockaddr_in));
    cr_assert_neq(server.sock.fd, 0);
    cr_assert_eq(close_server(&server, Ok), Ok);
}

Test(server, read_data_from_client)
{
    client_t client;

    client.socket = -1;
    cr_expect_eq(read_data_from_client(NULL, &client), Err);
    client.socket = open("./tests/input.txt", O_RDONLY);
    cr_expect_eq(read_data_from_client(NULL, &client), Ok);
    disconnect(NULL, &client);
}

Test(tools, my_str_to_word_array)
{
    char **tmp = my_str_to_word_array("a b c");

    cr_assert_eq(my_str_to_word_array(NULL), NULL);
    cr_assert_str_eq(tmp[0], "a");
    cr_assert_str_eq(tmp[1], "b");
    cr_assert_str_eq(tmp[2], "c");
}

Test(tools, reply_server)
{
    cr_assert_eq(reply_server(0, 0, NULL, NULL), false);
}

Test(tools, management_multi_cmd)
{
    char **cmd = management_multi_cmd("/login\n/logout\n");

    cr_assert_eq(management_multi_cmd(""), NULL);
    cr_assert_str_eq(cmd[0], "/login\n");
    cr_assert_str_eq(cmd[1], "/logout\n");
}