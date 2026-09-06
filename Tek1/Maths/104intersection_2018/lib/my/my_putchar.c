/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** D1, Display a number of ASCII's table
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
    return;
}
