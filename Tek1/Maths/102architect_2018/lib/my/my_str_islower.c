/*
** EPITECH PROJECT, 2018
** my_str_islower
** File description:
** D6, function return 1 if she contains only lower alpha.
*/

int my_strlen(char const *str);

int my_str_islower(char const *str)
{
    int i = 0;
    int chekage = 0;
    int size = my_strlen(str);

    if (str[0] == '\0')
        return (1);
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            chekage++;
    }
    if (chekage == size)
        return (1);
    return (0);
}
