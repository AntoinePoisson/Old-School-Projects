/*
** EPITECH PROJECT, 2018
** rush3.h
** File description:
** all header
*/

#ifndef BUFF_SIZE
#include <unistd.h>
#define BUFF_SIZE 10000

int main();
int my_putstr(char const *str);
int my_put_nbr(int nb);
void my_display_rush(int a, int b, int c);
int my_strlen(char const *str);
int rush3(char buff[]);
int is_case_simple(char first_charac, int size_line_x, int size_line_y);
int is_square(char buff[], char size_first_line[], int size_line_x, int size_line_y);

#endif
