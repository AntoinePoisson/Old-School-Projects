/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** D7,function that concatenates two strings
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int a = 0;

    for (i = 0; dest[i] != '\0'; i++);
    for (a = 0; src[a] != '\0'; a++) {
        dest[i] = src[a];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
