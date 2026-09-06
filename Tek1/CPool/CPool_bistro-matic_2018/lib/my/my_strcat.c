/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** Day07 task02 my_strcat
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlen(dest);
    int j = 0;

    for (j; src[j] != '\0'; j = j + 1)
        dest[j + i] = src[j];
    dest[j + i] = '\0';
    return (dest);
}
