/*
** EPITECH PROJECT, 2018
** rush3
** File description:
** the core of rush3
*/

#include "rush3.h"

int is_extension(int a, int size_line_x, int size_line_y)
{
    for (int i = 0; i <= 5; i++) {
        if (i == a) {
            my_display_rush(a, size_line_x, size_line_y);
            if (a != 5)
                my_putstr(" || ");
            a++;
        }
    }
    write(1, "\n", 1);
    return (345);
}

int is_case_simple(char first_charac, int size_line_x, int size_line_y)
{
    int result = 0;
    int a = 3;

    if (first_charac == 'o') {
        my_display_rush(1, size_line_x, size_line_y);
        write(1, "\n", 1);
        return (1);
    }
    if (first_charac == '*' || first_charac == '/') {
        my_display_rush(2, size_line_x, size_line_y);
        write(1, "\n", 1);
        return (2);
    }
    if (size_line_x == 1 || size_line_y == 1) {
        if (is_extension(a, size_line_x, size_line_y) == 345)
            return (345);
    }
    return (0);
}

int is_square(char buff[], char size_first_line[], int size_line_x, int size_line_y)
{
    int i = 0;

    for (i = 0; size_first_line[i] != '\0'; i++);
    if (size_first_line[i - 1] == 'A') {
        my_display_rush(3, size_line_x, size_line_y);
        write(1, "\n", 1);
        return (3);
    }
    for (i = 0; buff[i] != '\0'; i++);
    if (buff[i - 2] == 'C') {
        my_display_rush(4, size_line_x, size_line_y);
        write(1, "\n", 1);
        return (4);
    }
    if (buff[i - 2] == 'A') {
        my_display_rush(5, size_line_x, size_line_y);
        write(1, "\n", 1);
        return (5);
    }
    return (84);
}

int rush3(char buff[])
{
    int size_line_y = 0;
    int size_line_x = 0;
    char size_first_line[my_strlen(buff)];
    char first_charac = '\0';

    for (int i = 0; buff[i] != '\0'; i++) {
        if (i == 0)
            first_charac = buff[i];
        if (buff[i] == '\n')
            size_line_y++;
        if (size_line_y == 0) {
            size_first_line[i] = buff[i];
            size_first_line[i + 1] = '\0';
        }
    }
    size_line_x = my_strlen(size_first_line);
    if (is_case_simple(first_charac, size_line_x, size_line_y) != 0)
        return (0);
    if (is_square(buff, size_first_line, size_line_x, size_line_y) == 84)
        return (84);
    return (0);
}
