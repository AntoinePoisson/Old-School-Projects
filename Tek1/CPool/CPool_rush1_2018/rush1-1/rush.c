/*
** EPITECH PROJECT, 2018
** rush1-1
** File description:
** rush1-1
*/

void my_putchar(char c);
void invalid_size();

void first_line_y(int x)
{
    int a = 1;

    for (a = 1; a <= x; a++) {
        if (a == 1 || a == x)
            my_putchar('o');
        else
            my_putchar('-');
    }
}

void line(int x, int y)
{
    int a = 1;
    int i = 1;

    while (i < (y - 1)) {
        while (a <= x) {
            if (a == 1 || a == x)
                my_putchar('|');
            else
                my_putchar(' ');
            a = a + 1;
        }
        a = 1;
        my_putchar('\n');
        i = i + 1;
    }
}

void first_line_x(int y)
{
    int a = 1;

    for (a = 1; a <= y; a = a + 1) {
        if (a == 1 || a == y) {
              my_putchar('o');
              my_putchar('\n');
        }
        else {
            my_putchar('|');
            my_putchar('\n');        }
    }
}

void rush(int x, int y)
{
    if (x <= 0 || y <= 0) {
        invalid_size();
    }
    if (x == 1 && y == 1) {
        my_putchar('o');
        my_putchar('\n');
    }
    if (y == 1 && x > 1) {
        first_line_y(x);
        my_putchar('\n');
    }
    if (x == 1 && y > 1)
        first_line_x(y);
    if (x > 1 && y > 1) {
          first_line_y(x);
          my_putchar('\n');
          line(x, y);
          first_line_y(x);
          my_putchar('\n');
    }
}


