/*
** EPITECH PROJECT, 2019
** 42h
** File description:
** history built-in
*/

#include <stdlib.h>
#include "my_shell.h"

int my_history(history_t *history, char **args, bool *reset)
{
    *reset = false;
    if (*args == NULL)
        return (display_history(history, 0, 0));
    if (my_strcmp(*args, "-r") == 0 && *(args + 1) == NULL)
        return (display_history(history, 1, 0));
    if (my_strcmp(*args, "-h") == 0 && *(args + 1) == NULL)
        return (display_history(history, 2, 0));
    if (my_str_isnum(*args) == 0 && my_getnbr(*args) > 0 && *(args + 1) == NULL)
        return (display_history(history, 3, my_getnbr(*args)));
    if (my_strcmp(*args, "-c") == 0 && *(args + 1) == NULL) {
        *reset = true;
        return (clean_history(&history));
    }
    my_puterror("Usage: history [-chrSLMT] [# number of events].\n");
    return (0);
}

static int only_spcs(char const *cmd)
{
    int i = 0;

    for (; cmd[i] && cmd[i] == ' '; i++);
    return (cmd[i] == '\0') ? (-1) : (0);
}

history_t *add_to_history(history_t *history, char const *cmd, bool reset)
{
    time_t t;
    static size_t index = 1;
    history_t *element = NULL;

    if (only_spcs(cmd) == -1)
        return (history);
    if ((element = malloc(sizeof(*element))) == NULL)
        return (NULL);
    t = time(NULL);
    localtime(&t);
    element->index = index++;
    element->hour = my_strdup(my_str_to_word_array(ctime(&t))[3]);
    if (element->hour == NULL)
        return (NULL);
    *(element->hour + 5) = '\0';
    element->cmd = my_strdup(cmd);
    if (element->cmd == NULL)
        return (NULL);
    element->next = (reset == false) ? history : NULL;
    return (element);
}
