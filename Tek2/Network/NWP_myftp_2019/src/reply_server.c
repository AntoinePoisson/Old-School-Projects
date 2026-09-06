/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** reply_server
*/

#include "server.h"

static int check_right_param(int code, int socket, char *message);
static char *create_message(char *message, char *message_in_list);

bool reply_server(int code, int socket, char *message)
{
    int index = check_right_param(code, socket, message);

    if (index == -1)
        return (false);
    if (message == NULL) {
        message = list_reply[index].message;
    } else if ((message = create_message(message,
        list_reply[index].message)) == NULL)
        return (false);
    if (write(socket, message, strlen(message)) == -1)
        return (false);
    return (true);
}

static int check_right_param(int code, int socket, char *message)
{
    if (socket <= 0)
        return (-1);
    for (int i = 0; list_reply[i].message; i++) {
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