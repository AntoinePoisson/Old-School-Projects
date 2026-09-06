/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** handle_server
*/

#include "client.h"

static void management_reveice_cmd(char *cmd)
{
    char **multi = management_multi_cmd(cmd);

    for (int i = 0; multi && multi[i]; i++) {
        print_buff(multi[i]);
    }
}

int loop(int client)
{
    fd_set readfds;
    char buff[9096] = {0};

    while (!end(0)) {
        reset_select(&readfds, client);
        if (!end(0) && FD_ISSET(client, &readfds)) {
            memset(buff, 0, 9096);
            if (read(client, buff, 9096) < 0)
                THROW("failed to read server response");
            if (strlen(buff) == 0)
                return Ok;
            management_reveice_cmd(buff);
        }
        if (read_stdin(&readfds, client) == Err)
            break;
    }
    return Ok;
}

int setup_server(struct sockaddr_in *server, const char *port, const char *ip)
{
    char *end = NULL;

    errno = 0;
    server->sin_family = AF_INET;
    if (inet_pton(AF_INET, ip, &server->sin_addr) != 1)
        THROW("failed to set server address");
    server->sin_port = htons(strtol(port, &end, 10));
    return (errno || *end);
}

int my_teams_client(const char *ip, const char *port)
{
    int client = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;

    if (setup_server(&server, port, ip) != Ok || client < 0)
        THROW("bad port number");
    if (connect(client, (struct sockaddr *)&server, sizeof(server)) < 0)
        THROW("connection failed");
    signal(SIGINT, (void (*)(int))end);
    loop(client);
    close(client);
    return 0;
}