/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** management_client
*/

#include "server.h"

static bool check_can_exec_cmd(client_t *client, char **cmd);
static bool exec_cmd(client_t *client, char **cmd);
static bool switch_directory(int index_cmd, char *path_client,
    char *path_server, bool before);
static char *check_if_crlf(client_t *client, char *buffer);

int management_client(client_t *client)
{
    char buffer[MAX_LINE] = {0};
    char *res = NULL;
    char **cmd = NULL;
    int code = 0;

    if (read(client->socket, buffer, MAX_LINE) < 0)
        return (RETURN_ERROR);
    if ((res = check_if_crlf(client, buffer)) == NULL)
        return (RETURN_ERROR);
    cmd = check_commands(res, &code);
    if (code != 0) {
        reply_server(code, client->socket, NULL);
        return (RETURN_ERROR);
    }
    if (!check_can_exec_cmd(client, cmd))
        return (RETURN_ERROR);
    return (!exec_cmd(client, cmd) ? RETURN_ERROR : RETURN_SUCCESS);
}

static bool check_can_exec_cmd(client_t *client, char **cmd)
{
    if (strcmp(cmd[0], "USER") && strcmp(cmd[0], "PASS") &&
        strcmp(cmd[0], "QUIT") && strcmp(cmd[0], "NOOP")
        && strcmp(cmd[0], "HELP")) {
        if (!(client->login_user && client->login_password)) {
            reply_server(530, client->socket, NULL);
            return (false);
        }
    }
    return (true);
}

static bool exec_cmd(client_t *client, char **cmd)
{
    server_t *server = get_struct_server();
    bool res = false;
    bool stop = false;
    int i = 0;

    for (; list_commands[i].name && stop == false; i++)
        if (strcmp(list_commands[i].name, cmd[0]) == 0 && stop == false) {
            stop = true;
            break;
        }
    if (stop == false)
        return (false);
    if (switch_directory(i, client->path_current, server->path, true))
        return (false);
    res = list_commands[i].fnct(client, cmd[1]) == RETURN_SUCCESS ?
    false : true;
    stop = true;
    if (switch_directory(i, client->path_current, server->path, false))
        return (false);
    return (res);
}

static bool switch_directory(int index_cmd, char *path_client,
    char *path_server, bool before)
{
    if (list_commands[index_cmd].change_directory == false)
        return (false);
    if (before && chdir(path_client) == -1)
        return (true);
    if (!before && chdir(path_server) == -1)
        return (true);
    return (false);
}

static char *check_if_crlf(client_t *client, char *buffer)
{
    char *res = buffer;

    if (client->buff_cmd) {
        res = calloc(strlen(client->buff_cmd) + strlen(buffer) + 1, 1);
        strcpy(res, client->buff_cmd);
        strcpy(&res[strlen(client->buff_cmd)], buffer);
        free(client->buff_cmd);
        client->buff_cmd = strdup(res);
    }
    if (checker_crlf(buffer)) {
        free(client->buff_cmd);
        client->buff_cmd = NULL;
        return (res);
    }
    if (!client->buff_cmd && strlen(buffer) != 0)
        client->buff_cmd = strdup(buffer);
    return (NULL);
}