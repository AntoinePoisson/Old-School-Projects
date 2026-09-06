/*
** EPITECH PROJECT, 2019
** lib
** File description:
** is_num.c
*/

int is_num(char const *s)
{
    int i = 0;

    i += (s[0] == '-') ? 1 : 0;
    for (; s[i] != '\0'; i++) {
        if (s[i] == '}' && s[i + 1] == '\0')
            return (0);
        if (s[i] < '0' || s[i] > '9')
            return (-1);
    }
    return (0);
}
