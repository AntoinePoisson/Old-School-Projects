/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** d1, display a number of ascii's table
*/

#include <unistd.h>

extern int return_printf;

void my_putchar(char c)
{
    write(1, &c, 1);
    return_printf++;
    return;
}
