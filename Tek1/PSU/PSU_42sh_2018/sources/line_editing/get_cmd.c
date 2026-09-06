/*
** EPITECH PROJECT, 2019
** sucide
** File description:
** sucide
*/

#include "my_shell.h"
#include <term.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int call_termcap(char const *str)
{
    char *tmp = tgetstr(str, NULL);

    if (tmp == NULL)
        return (84);
    write(STDOUT_FILENO, tmp, strlen(tmp));
    return (0);
}

char *display_line(char *cmd)
{
    call_termcap("dl");
    display();
    if (cmd != NULL)
        printf("%s", cmd);
    fflush(stdout);
    return (cmd);
}

char *get_charac(int buf, char *cmd)
{
    char tmp[2] = {buf, '\0'};
    int actions[5] = {4, 9, 12, 21, 127};
    int (*ar[5])(char **cmd) = {null_touch, auto_comp, clear_scr,
        del_line, del_char};

    for (int a = 0; a ^ 5; a++)
        if (buf == actions[a]) {
            ar[a](&cmd);
            break;
        }
    if (buf > 31 && buf < 127)
        cmd = (cmd == NULL) ? my_strdup(tmp) : my_strcat(cmd, tmp);
    return (display_line(cmd));
}

char *move_into_history(char *cmd, int buf, history_t *history, size_t *index)
{
    history_t *tmp = history;

    if (history == NULL)
        return (cmd);
    if (buf == 4283163)
        *index = (*index > 1) ? *index - 1 : *index;
    else
        *index = (*index < history->index) ? *index + 1 : *index;
    while (tmp && tmp->index ^ *index)
        tmp = tmp->next;
    return (tmp == NULL) ? (NULL) : (my_strdup(tmp->cmd));
}

char *get_cmd(char **env, history_t *history)
{
    struct termios save;
    struct termios newt;
    char *cmd = NULL;
    int buf = 0;
    size_t index = history ? history->index + 1: 0;

    display();
    if (isatty(0) == 0 || new_term(&save, &newt, env) == 84)
        return (get_next_line(0));
    for (buf = 0; read(STDIN_FILENO, &buf, sizeof(int)) != -1; buf = 0) {
        if (buf == 4283163 || buf == 4348699)
            cmd = move_into_history(cmd, buf, history, &index);
        if (buf == 10 || ((cmd = get_charac(buf, cmd)) == NULL && buf == 4))
            break;
    }
    if (buf ^ 4)
        write(STDOUT_FILENO, "\n", 1);
    if (tcsetattr(STDIN_FILENO, TCSANOW, &save) == -1)
        return (NULL);
    return (buf == 10 && cmd == NULL) ? (my_strdup("\0")) : (cmd);
}
