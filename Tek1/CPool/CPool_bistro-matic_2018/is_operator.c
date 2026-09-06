/*
** EPITECH PROJECT, 2018
** is_operator
** File description:
** is_operator project bistro-matic
*/

int is_operator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
        return (1);
    return (0);
}
