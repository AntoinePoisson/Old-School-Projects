/*
** EPITECH PROJECT, 2018
** my_strupcase
** File description:
** D6, function that puts every letter of every word in uppercase.
*/

char *is_capitalize(char *str, int i)
{
    int continuer = 0;
    int a = 0;

    for (a = i; str[a] != '\0' && continuer == 0; a++) {
        if (str[a] >= 'a' && str[a] <= 'z') {
            str[a] = str[a] - 32;
            continuer = 1;
        }
    }
    return (str);
}

char *my_strupcase(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            is_capitalize(str, i);
    }
    return (str);
}
