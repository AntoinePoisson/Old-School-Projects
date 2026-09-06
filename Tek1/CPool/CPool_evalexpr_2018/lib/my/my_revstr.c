/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** Day06 task03 my_revstr
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    char str2;

    while (i < j) {
        str2 = str[j];
        str[j] = str[i];
        str[i] = str2;
        i = i + 1;
        j = j - 1;
    }
    return (str);
}
