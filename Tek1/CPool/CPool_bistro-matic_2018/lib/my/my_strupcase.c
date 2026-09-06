/*
** EPITECH PROJECT, 2018
** my_strupcase
** File description:
** Day06 task07 my_strupcase
*/

char *my_strupcase(char *str)
{
    if (str[0] == '\0')
        return (0);
    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] = str[i] - 32;
    }
    return (str);
}
