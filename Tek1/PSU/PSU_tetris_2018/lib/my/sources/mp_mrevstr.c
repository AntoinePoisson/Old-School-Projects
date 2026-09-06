/*
** EPITECH PROJECT, 2018
** mprintf
** File description:
** mp_mrevstr.c
*/

char *mp_mrevstr(char *s)
{
    int a = 0;
    int b = 0;
    char c;

    for (a = 0; s[a + 1] != 0; a++);
    for (b = 0; a >= b; b++, a--) {
        c = s[a];
        s[a] = s[b];
        s[b] = c;
    }
    return (s);
}
