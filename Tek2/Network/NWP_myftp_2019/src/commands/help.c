/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** help
*/

#include "server.h"

static char *get_message(char *param);
static char *get_message_two(char *param);

int help(client_t *client, char *param)
{
    if (param) {
        reply_server(214, client->socket, get_message(param));
    } else {
        reply_server(214, client->socket, "Help message");
    }
    return (RETURN_SUCCESS);
}

static char *get_message(char *param)
{
    if (strcasecmp(param, "USER") == 0)
        return ("Specify user for authentication");
    if (strcasecmp(param, "PASS") == 0)
        return ("Specify password for authentication");
    if (strcasecmp(param, "CWD") == 0)
        return ("Change working directory");
    if (strcasecmp(param, "CDUP") == 0)
        return ("Change working directory to parent directory");
    if (strcasecmp(param, "QUIT") == 0)
        return ("Disconnection");
    if (strcasecmp(param, "DELE") == 0)
        return ("Delete file on the server");
    if (strcasecmp(param, "PWD") == 0)
        return ("Print working directory");
    if (strcasecmp(param, "PASV") == 0)
        return ("Enable \"passive\" mode for data transfer");
    if (strcasecmp(param, "PORT") == 0)
        return ("Enable \"active\" mode for data transfer");
    return (get_message_two(param));
}

static char *get_message_two(char *param)
{
    if (strcasecmp(param, "HELP") == 0)
        return ("List available commands");
    if (strcasecmp(param, "NOOP") == 0)
        return ("Do nothing");
    if (strcasecmp(param, "RETR") == 0)
        return ("Download file from server to client");
    if (strcasecmp(param, "STOR") == 0)
        return ("Upload file from client to server");
    if (strcasecmp(param, "LIST") == 0)
        return ("List files in the current working directory ");
    return ("Help message");
}