/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** reply_server
*/

#include "my_teams.h"

static int check_right_param(int code, int socket, char *message,
    char *id);
static char *create_message(char *message, char *message_in_list);

static int wait_for_write(int sock)
{
    fd_set wset;
    struct timeval out = {3, 0};

    FD_ZERO(&wset);
    FD_SET(sock, &wset);
    return select(FD_SETSIZE, NULL, &wset, NULL, &out);
}

bool reply_server(int code, int socket, char *message, char *current_user_id)
{
    int index = check_right_param(code, socket, message, current_user_id);

    if (index < -1)
        return (index == -2 ? true : false);
    if (index == -1)
        return (false);
    if (message == NULL) {
        message = list_reply[index].message;
    } else if ((message = create_message(message,
        list_reply[index].message)) == NULL)
        return (false);
    if (wait_for_write(socket) > 0)
        if (write(socket, message, strlen(message)) == -1)
            return (false);
    return (true);
}

static int check_right_param(int code, int socket, char *message,
    char *id)
{
    if (socket <= 0 || !id || strlen(id) == 0)
        return (-1);
    for (int i = 0; list_reply[i].message; i++) {
        if (list_reply[i].code == code && list_reply[i].fnct != NULL)
            return (-1);
        if (list_reply[i].code == code) {
            if (strstr(list_reply[i].message, "%s") && !message)
                return (-1);
            return (i);
        }
    }
    return (-1);
}

static char *create_message(char *message, char *message_in_list)
{
    int size = (strlen(message) + strlen(message_in_list) + 1);
    char *result = malloc(size);

    if (result == NULL)
        return (NULL);
    memset(result, '\0', size);
    sprintf(result, message_in_list, message);
    return (result);
}
