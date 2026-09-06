/*
** EPITECH PROJECT, 2018
** my_put.h
** File description:
** all headers of my lib
*/

#ifndef MY_PUT_H
# define MY_PUT_H

#ifndef EXIT_SUCCESS
# define EXIT_SUCCESS 0
#endif

#ifndef EXIT_ERROR
# define EXIT_ERROR 84
#endif

int my_printf(char *str, ...);
void my_putchar(char c);
int my_putnbr(int nb);
int my_putstr(char const *str);
int my_puterror(char const *str);

#endif