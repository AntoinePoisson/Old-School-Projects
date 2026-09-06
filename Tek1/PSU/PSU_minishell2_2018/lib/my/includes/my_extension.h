/*
** EPITECH PROJECT, 2018
** my_extension.h
** File description:
** header my extension
*/

#ifndef MY_EXTENSION_H
#define MY_EXTENSION_H

#include <stdarg.h>
#include <stddef.h>

int my_strlen(char const *str);
void my_putchar(char c);
int my_put_nbr(int nb);
unsigned int my_unsigned_putnbr(int nb);
int my_put_adress(long nb);
int my_put_long(long nb);
int my_put_nbr_base(int nb, char *base);
int my_putstr(char const *str);
int is_extension_printf_four(char *str, int i, va_list ap, int previous);
int is_flag_h_tag(char *str, int i, va_list ap);
int is_flag_espace(char *str, int i);
int is_flag_posi(char *str, int i);
int is_extension_flag_neg(char *str, int i);
int is_flag_neg(char *str, int i);
int is_extension_printf_four_0(char *str, int i, va_list ap);
void is_extension_of_extension_three(long lon);
int is_extension_printf_three(char *str, int i, va_list ap);
int is_extension_printf_two(char *str, int i, va_list ap);
int is_extension_printf_0(char *str, int i, va_list ap);

#endif
