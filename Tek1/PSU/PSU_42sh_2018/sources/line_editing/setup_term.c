/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** setup term with ncurse
*/

#include "my_shell.h"
#include <term.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char *get_term(char **env)
{
    char *res = NULL;

    if (env == NULL)
        return (NULL);
    while (*env && strncmp(*env, "TERM=", 5) && env++);
    res = *env;
    if (res != NULL) {
        while (*res != '=' && *(res++) != '\0');
        res++;
    }
    return (res);
}

int new_term(struct termios *save, struct termios *newt, char **env)
{
    char *term = get_term(env);

    if (term == NULL || tgetent(NULL, term) ^ 1)
        return (84);
    if (tcgetattr(STDIN_FILENO, save) == -1 ||
        tcgetattr(STDIN_FILENO, newt) == -1)
        return (84);
    newt->c_lflag &= ~(ICANON | ECHO);
    if (tcsetattr(STDIN_FILENO, TCSANOW, newt) == -1)
        return (84);
    return (0);
}
