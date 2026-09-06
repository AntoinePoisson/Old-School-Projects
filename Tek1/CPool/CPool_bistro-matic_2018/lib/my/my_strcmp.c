/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** Day06 task05 my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int s1nbr = 0;
    int s2nbr = 0;

    if (s1[0] == '\0' || s2[0] == '\0')
        return (0);
    else {
        for (int i = 0; s1[i] != '\0'; i = i + 1)
            s1nbr = s1nbr + s1[i];
        for (int i = 0; s2[i] != '\0'; i = i + 1)
            s2nbr = s2nbr + s2[i];
    }
    return (s1nbr - s2nbr);
}
