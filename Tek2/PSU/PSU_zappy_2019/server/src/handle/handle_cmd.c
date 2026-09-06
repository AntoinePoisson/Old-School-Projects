/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** handle_cmd
*/

#include "zappy.h"

static int search_commands(char *cmd);
static int check_commands_param(char **cmd, int nbr_param);
static char **parse_commands(char *cmd);

char **check_commands(client_t *client, char *cmd)
{
    int nbr_param = 0;
    char **res = NULL;

    if ((res = parse_commands(cmd)) == NULL) {
        reply_server(501, client->socket, NULL);
        return (NULL);
    }
    if ((nbr_param = search_commands(res[0])) == -10) {
        reply_server(502, client->socket, NULL);
        return (NULL);
    }
    if ((check_commands_param(res, nbr_param)) != 0) {
        reply_server(503, client->socket, NULL);
        return (NULL);
    }
    return (res);
}

static int search_commands(char *cmd)
{
    for (u_int8_t i = 0; list_commands[i].name; i++) {
        if (strcmp(cmd, list_commands[i].name) == 0)
            return (list_commands[i].nbr_param);
    }
    return (-10);
}

static int check_commands_param(char **cmd, int nbr_param)
{
    u_int16_t length = 0;

    while (cmd[length + 1])
        length++;
    if (nbr_param == -1)
        return (0);
    if (length == nbr_param)
        return (0);
    return (1);
}

static char **parse_commands(char *cmd)
{
    char **res = NULL;
    int i = 0;

    for (;;) {
        if (cmd[i] == '\n')
            break;
        if ((cmd[i] == '\n') || (cmd[i] == '\0') || i > 6000) {
            return (NULL);
        }
        ++i;
    }
    cmd[i] = '\0';
    res = my_str_to_word_array(cmd);
    if (!res || !res[0])
        return (NULL);
    return (res);
}