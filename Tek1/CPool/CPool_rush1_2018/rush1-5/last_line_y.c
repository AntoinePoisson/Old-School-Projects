/*
** EPITECH PROJECT, 2018
** last_line_y
** File description:
** last_line_y
*/

void my_putchar(char c);

void last_line_y(int x)
{
    int a = 1;

    for (a = 1; a <= x; a = a + 1) {
        if (a == x)
            my_putchar('A');
        if (a == 1)
             my_putchar('C');
        if(a > 1 && a < x)
            my_putchar('B');
    }
}
