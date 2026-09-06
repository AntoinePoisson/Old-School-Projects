/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** reply_server
*/

#include "zappy.h"

static int check_right_param(int code, int socket, char *message);
static char *create_message(char *message, char *message_in_list, bool *in_fun);
static int wait_for_write(int sock);

bool reply_server(int code, int socket, char *message)
{
    int index = check_right_param(code, socket, message);
    bool in_function = false;

    if (index == -1)
        return (false);
    if (message == NULL) {
        message = list_reply[index].message;
    } else if ((message = create_message(message,
        list_reply[index].message, &in_function)) == NULL)
        return (false);
    if (wait_for_write(socket) > 0 &&
        write(socket, message, strlen(message)) == -1)
        return (false);
    if (in_function)
        free(message);
    return (true);
}

static int check_right_param(int code, int socket, char *message)
{
    if (socket <= 0)
        return (-1);
    for (int i = 0; list_reply[i].message; i++)
        if (list_reply[i].code == code) {
            if (strstr(list_reply[i].message, "%s") && !message)
                return (-1);
            return (i);
        }
    return (-1);
}

static char *create_message(char *message, char *message_in_list, bool *in_func)
{
    int size = (strlen(message) + strlen(message_in_list) + 1);
    char *result = malloc(size);

    if (result == NULL)
        return (NULL);
    memset(result, '\0', size);
    sprintf(result, message_in_list, message);
    *in_func = true;
    return (result);
}

static int wait_for_write(int sock)
{
    fd_set wset;
    struct timeval out = {0, 100};

    FD_ZERO(&wset);
    FD_SET(sock, &wset);
    return select(FD_SETSIZE, NULL, &wset, NULL, &out);
}