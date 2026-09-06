/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** handle inhibitors
*/

#include <stdlib.h>
#include <stddef.h>
#include "my_shell.h"

char hex_to_char(char *str)
{
    unsigned short j = 0;
    char new = 0x00;
    char *hexa = "0123456789ABCDEF";

    if (str == NULL || str[0] == '\0')
        return (0);
    for (j = 0; hexa[j] != str[0]; j++);
    new |= j;
    new <<= 4;
    for (j = 0; hexa[j] != str[1]; j++);
    new |= j;
    return (new);
}

char *change_backslash(char *str)
{
    char *temp;

    for (int i = 0; str[i]; i++) {
        if (my_strncmp(&str[i], "echo", 3) == 0) {
            for (; str[i] && str[i] != '|' && str[i] != ';' && str[i] != '&'
            && str[i] != '(' && str[i] != '<' && str[i] != '>'
            && str[i] != '`' && str[i] != ')'; i++);
            i--;
        }
        if (str[i] == '\\' && str[i + 2]) {
            temp = str;
            str = my_malloc(sizeof(char) * (my_strlen(temp) - 1));
            str = my_strncat(str, temp, i);
            str[i] = hex_to_char(&temp[i + 1]);
            str = my_strcat(str, &temp[i + 3]);
            free(temp);
        }
    }
    return (str);
}

char *convert_dec_to_hexa(int nbr)
{
    char *new = malloc(sizeof(char) * 3);
    int t = nbr;
    int i = 0;
    int c = 0;

    for (i = t, c = 0, t %= 16; i > 0; i /= 16, t %= 16, t = i, c++)
        if (t <= 9)
            new[c] = t + '0';
        else
            new[c] = t + 55;
    new[2] = '\0';
    return (my_revstr(new));
}

char *add_hexa(char *str, int i)
{
    char *hex = NULL;
    char *temp;

    hex = convert_dec_to_hexa(str[i]);
    temp = str;
    str = my_malloc(sizeof(char) *
    (my_strlen(hex) + my_strlen(str) + 1));
    str = my_strncat(str, temp, i);
    str = my_strcat(str, hex);
    str = my_strcat(str, &temp[i + 1]);
    free(hex);
    free(temp);
    return (str);
}

char *find_backslash(char *str)
{
    int i;

    for (i = 0; str[i]; i++) {
        if (my_strncmp(&str[i], "echo", 3) == 0) {
            for (; str[i] && str[i] != '|' && str[i] != ';' && str[i] != '&'
            && str[i] != '(' && str[i] != '<' && str[i] != '>'
            && str[i] != '`' && str[i] != ')'; i++);
            i--;
        }
        if (str[i] == '\\' && str[++i]) {
            str = add_hexa(str, i);
        }
    }
    str[i] = '\0';
    return (str);
}
