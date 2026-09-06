/*
** EPITECH PROJECT, 2018
** my_isneg
** File description:
** Display, if the number is positif or negatif.
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0)
        return (1);
    else
        return (0);
}

int my_str_isnum(char const *s)
{
    int i = 0;

    i += (s[0] == '-' || s[0] == '+') ? 1 : 0;
    for (; s[i] != '\0'; i++)
        if (s[i] < '0' || s[i] > '9')
            return (-1);
    return (0);
}
