/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** parser_input
*/

#include "client.h"

static char *checker_cmd(char *cmd, int index);
static char *speciale_case_cmd(char *cmd);
static int checker_cmd_index(char *cmd);

char *parser_commandes(char *cmd)
{
    int i = 0;

    if (cmd == NULL || strlen(cmd) <= 1)
        return (NULL);
    while (cmd[0] == ' ' || cmd[0] == '\t')
        cmd = &cmd[1];
    cmd = speciale_case_cmd(cmd);
    i = checker_cmd_index(cmd);
    if (i == -1)
        return (NULL);
    cmd = checker_cmd(cmd, i);
    return (cmd);
}

static char *speciale_case_cmd(char *cmd)
{
    int nbr = 0;

    if (strncmp("/create", cmd, 7) != 0)
        return (cmd);
    for (int i = 0; cmd[i] && cmd[i] != '\n'; i++)
        if (cmd[i] == '"')
            nbr++;
    if (nbr % 2 != 0)
        return (cmd);
    nbr = 0;
    for (int i = 0; cmd[i] && cmd[i] != '\n'; i++) {
        if (cmd[i] == '"')
            nbr++;
        if (nbr == 1 && (cmd[i] == ' ' || cmd[i] == '\t'))
            cmd[i] = '|';
    }
    return (cmd);
}

static char *checker_cmd(char *cmd, int index)
{
    int nbr = 0;

    for (int i = 0; cmd[i] && cmd[i] != '\n'; i++) {
        if (cmd[i] == '\t')
            cmd[i] = ' ';
        if (cmd[i] == '"') {
            cmd[i] = ' ';
            nbr++;
        }
        if (nbr % 2 == 0 && cmd[i] != ' ' && i >= index)
            return (NULL);
    }
    if (nbr % 2 != 0)
        return (NULL);
    return (cmd);
}

static int checker_cmd_index(char *cmd)
{
    int index = 0;

    if (cmd[0] != '/')
        return (-1);
    for (;;) {
        if (!cmd[index] || cmd[index] == '"')
            return (-1);
        if (cmd[index] == ' ' || cmd[index] == '\t' ||
            cmd[index] == '\n') {
            return (index);
        }
        index++;
    }
    return (-1);
}
