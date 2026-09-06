/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** tool_cmd
*/

#include "my_teams.h"

static int search_commands(char *cmd, bool is_online);
static int check_commands_param(char **cmd, int nbr_param);
static char **parse_commands(char *cmd);

char **check_right_commands(client_t *client, char *cmd, bool is_online)
{
    int nbr_param = 0;
    char **res = NULL;

    if ((res = parse_commands(cmd)) == NULL) {
        reply_server(567, client->socket, NULL, client->id);
        return (NULL);
    }
    if ((nbr_param = search_commands(res[0], is_online)) <= -10) {
        if (nbr_param == -20) {
            reply_server(405, client->socket, NULL, client->id);
        } else {
            reply_server(500, client->socket, NULL, client->id);
        }
        return (NULL);
    }
    if (check_commands_param(res, nbr_param) != 0) {
        reply_server(504, client->socket, NULL, client->id);
        return (NULL);
    }
    return (res);
}

static int search_commands(char *cmd, bool is_online)
{
    for (u_int8_t i = 0; list_commands[i].name; i++) {
        if (strcmp(cmd, list_commands[i].name) == 0 &&
            list_commands[i].must_be_log && !is_online)
            return (-20);
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