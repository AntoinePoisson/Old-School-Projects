/*
** EPITECH PROJECT, 2018
** my_isneg
** File description:
** Displays either N if the integer passed as parameter is negative, P, if postive or null.
*/

int my_isneg(int n)
{
    if (n < 0)
        my_putchar(78);
    else
        my_putchar(80);
    return (0);
}
