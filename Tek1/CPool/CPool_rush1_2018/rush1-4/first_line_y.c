/*
** EPITECH PROJECT, 2018
** first_line_y
** File description:
** first_line_y
*/

void my_putchar(char c);

void first_line_y(int x)
{
    int a = 1;

    for (a = 1; a <= x; a = a + 1) {
        if (a == x)
            my_putchar('C');
        if (a == 1)
            my_putchar('A');
        if(a > 1 && a < x)
            my_putchar('B');
    }
}
