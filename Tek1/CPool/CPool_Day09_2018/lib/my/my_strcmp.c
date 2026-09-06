/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** Reproduce the behavior of the strcmp function.
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int a = 0;

    while (s1[i] == s2[i]) {
        if (s1[i] == '\0' && s2[i] == '\0')
            return (0);
        i++;
    }
    return ('s1[i]' - 's2[i]');
}
