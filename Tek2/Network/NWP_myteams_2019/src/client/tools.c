/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** tools
*/

#include "client.h"

int check_args(const char *av1, int ac)
{
    if (ac != 3)
        THROW(USAGE_MESS);
    if (!av1)
        THROW(USAGE_MESS);
    if (strcmp(av1, USAGE_FLAG) == 0)
        RET_USAGE();
    return Ok;
}

int is_num(char c)
{
    if (c < 48 || c > 57)
        return 84;
    return (0);
}

int check_code(char *buff)
{
    if (is_num(buff[0]) == 84 || is_num(buff[1]) == 84 ||
        is_num(buff[2]) == 84)
        return 84;
    return 1;
}

int go_to_code(char **tab, char **tab_no_code, char *buff)
{
    if (buff) {
    }
    for (int i = 0; list_commands_code[i].code; i++) {
        if (strcmp(tab[0], list_commands_code[i].code) == 0) {
            list_commands_code[i].fnct(tab_no_code);
        }
    }
    return (0);
}