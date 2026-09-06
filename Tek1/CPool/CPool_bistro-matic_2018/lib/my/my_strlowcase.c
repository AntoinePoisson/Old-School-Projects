/*
** EPITECH PROJECT, 2018
** my_strlowcase
** File description:
** Day06 task08 my_strlowcase
*/

char *my_strlowcase(char *str)
{
    if (str[0] == '\0')
        return (0);
    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] = str[i] + 32;
    }
    return (str);
}
