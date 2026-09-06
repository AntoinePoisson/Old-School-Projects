/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** D6, Reproduce the behavior of the my_strcmp function.
*/

int check_alpha(char charac)
{
    if (charac >= 65 && charac <= 90)
        return (charac + 32);
    return (charac);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    char a;

    while (1) {
        if (check_alpha(s1[i]) != check_alpha(s2[i]))
            break;
        if (s1[i] == '\0' && s2[i] == '\0')
            return (0);
        i++;
    }
    a = check_alpha(s1[i]) - check_alpha(s2[i]);
    return (a);
}
