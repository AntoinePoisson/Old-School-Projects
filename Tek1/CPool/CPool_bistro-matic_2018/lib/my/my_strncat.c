/*
** EPITECH PROJECT, 2018
** my_strncat
** File description:
** Day07 task02 my_strncat
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = my_strlen(dest);

    for (int j = 0; src[j] != '\0' && j < nb; j = j + 1) {
        dest[j + i] = src[j];
    }
    return (dest);
}
