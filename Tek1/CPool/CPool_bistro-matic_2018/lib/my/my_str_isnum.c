/*
** EPITECH PROJECT, 2018
** my_str_isnum
** File description:
** D6, function that returns 1 if she contains only digits.
*/

int my_strlen(char const *str);

int my_str_isnum(char const *str)
{
    int check = 0;

    if (str[0] == '\0')
        return (1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            check++;
    }
    if (check == my_strlen(str))
        return (1);
    return (0);
}

int my_str_isnum_or_parenth(char const *str)
{
    int check = 0;

    if (str[0] == '\0')
        return (1);
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= '0' && str[i] <= '9') ||
            str[i] == '(' || str[i] == ')')
            check++;
    }
    if (check == my_strlen(str))
        return (1);
    return (0);
}
