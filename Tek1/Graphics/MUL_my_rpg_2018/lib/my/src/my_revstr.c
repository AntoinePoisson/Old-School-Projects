/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** reverses a string
*/

char *my_revstr(char *str)
{
    int i = 0;
    int a = 0;
    char c = 0;

    for (;str[i]; i++);
    i -= 1;
    for (; i >= a; i--, a++) {
        c = str[a];
        str[a] = str[i];
        str[i] = c;
    }
    return (str);
}
