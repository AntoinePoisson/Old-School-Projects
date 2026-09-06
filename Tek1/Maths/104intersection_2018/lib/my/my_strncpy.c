/*
** EPITECH PROJECT, 2018
** my_strncpy
** File description:
** D6, function that copies n characters from a string into another.
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int a = 0;

    if (dest[0] == '\0' || src[0] == '\0')
        return (0);
    for (a = 0; src[a] != '\0'; a++) {
        if (a <= n) {
            dest[a] = src[a];
            if (src[a] == '\0')
                a = n;
        }
    }
    return (dest);
}
