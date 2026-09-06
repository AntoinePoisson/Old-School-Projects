/*
** EPITECH PROJECT, 2019
** NWP_myteams_2019
** File description:
** get_cmd.c
*/

#include "my_teams.h"

static int read_data(int fd, char buff[DEFAULT_MESSAGE_LENGTH])
{
    for (size_t i = 0; i < DEFAULT_MESSAGE_LENGTH; i++)
        buff[i] = 0;
    return read(fd, buff, DEFAULT_MESSAGE_LENGTH);
}

static int interpret(client_t *client, char *buff)
{
    char **cmd = NULL;

    if (!buff) return Ok;
    for (int i = 0; buff[i]; i++)
        if (buff[i] == '\r' || buff[i] == '\n' ||
            !(buff[i] >= ' ' && buff[i] <= '|')) {
            buff[i] = '\n';
            buff[i + 1] = '\0';
            break;
        }
    cmd = check_right_commands(client, buff, client->login_password);
    if (cmd == NULL) return Ok;
    for (int i = 0; list_commands[i].name; i++)
        if (strcmp(list_commands[i].name, cmd[0]) == 0) {
            list_commands[i].fnct(client, &cmd[1]);
            return Ok;
        }
    reply_server(500, client->socket, NULL, client->id);
    return Ok;
}

int read_data_from_client(server_t *server, client_t *client)
{
    char buff[DEFAULT_MESSAGE_LENGTH + 5000] = {0};
    char **cmd = NULL;

    switch (read_data(client->socket, buff)) {
        case -1: THROW("failed to read data from client");
        case 0: disconnect(server, client);
                break;
        default:
            cmd = management_multi_cmd(buff);
            for (int i = 0; cmd && cmd[i]; i++)
                interpret(client, cmd[i]);
    }
    return Ok;
}