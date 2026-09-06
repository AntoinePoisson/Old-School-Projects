/*
** EPITECH PROJECT, 2018
** my_strncpy
** File description:
** Day06 task02 my_strncpy
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int len = my_strlen(src);

    if (n > len) {
        i = 0;
        while (i < n) {
            if (i <= len)
                dest[i] = src[i];
            if (i > len)
                dest[i] = '\0';
            i = i + 1;
        }
    }
    if (n <= len) {
        for (i; src[i] != '\0'; i = i + 1)
            if (i < n)
                dest[i] = src[i];
        dest[i] = '\0';
    }
    return (dest);
}
