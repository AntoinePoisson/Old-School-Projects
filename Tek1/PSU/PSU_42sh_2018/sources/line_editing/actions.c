/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** actions of touch
*/

#include "my_shell.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int clear_scr(char **cmd)
{
    call_termcap("cl");
    display();
    if (*cmd != NULL) {
    }
    return (0);
}

int null_touch(char **cmd)
{
    if (*cmd != NULL && *(*cmd) != '\0')
        write(STDOUT_FILENO, "\n", 1);
    if (*cmd != NULL && *(*cmd) == '\0') {
        free(*cmd);
        *cmd = NULL;
    }
    return (0);
}

int del_char(char **cmd)
{
    if (*cmd != NULL && *(*cmd + 1))
        printf("\b \b ");
    if (*cmd != NULL && (*cmd)[0] != '\0')
        *(*cmd + strlen(*cmd) - 1) = '\0';
    return (0);
}

int del_line(char **cmd)
{
    call_termcap("dl");
    display();
    if (*cmd != NULL)
        *(*cmd) = '\0';
    return (0);
}

int auto_comp(char **cmd)
{
    if (*cmd != NULL) {
    }
    return (0);
}
