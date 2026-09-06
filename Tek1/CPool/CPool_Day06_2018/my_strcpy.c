/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** copie function in the other function
*/

char *my_strcpy(char *dest, char const *src)
{
    int a = 0;

    for (a = 0; src[a] != '\0'; a++)
        dest[a] = src[a];
    dest[a] = '\0';
    return (dest);
}
