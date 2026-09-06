/*
** EPITECH PROJECT, 2018
** my_strncpy
** File description:
** Day06 task02 my_strncpy
*/

int my_strlen(char const *src);

char *modify_dest(char *dest, char const *src, int n)
{
    int len = my_strlen(src);
    int i = 0;

    while (i = 0 < n) {
        if (i <= len)
            dest[i] = src[i];
        if (i > len)
            dest[i] = '\0';
        i = i + 1;
    }
    return (dest);
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int len = my_strlen(src);

    if (n > len) {
        dest = modify_dest(dest, src, n);
        return (dest);
    }
    for (i = 0; src[i] != '\0'; i = i + 1)
        if (i < n)
            dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
