/*
** EPITECH PROJECT, 2018
** my_stnrcat
** File description:
** Write a function that concatenates two strings
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int a = 0;

    for (i = 0; dest[i] != '\0'; i++);
    for (a = 0; a < nb; a++) {
        dest[i] = src[a];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}


