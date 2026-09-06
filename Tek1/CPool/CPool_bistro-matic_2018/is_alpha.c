/*
** EPITECH PROJECT, 2018
** is_alpha
** File description:
** returns 1 if the character is alpha, else 0
*/

int is_alpha(char c)
{
    if (c > 96 && c < 123)
        return (1);
    return (0);
}
