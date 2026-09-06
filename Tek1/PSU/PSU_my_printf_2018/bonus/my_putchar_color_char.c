/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** D1, Display a number of ASCII's table
*/

#include <unistd.h>

extern int return_printf;

void my_putchar_color_char(char c)
{
    write(1, "\033[1;31m", 7);
    write(1, &c, 1);
    write(1, "\033[0m", 4);
    return_printf++;
    return;
}
