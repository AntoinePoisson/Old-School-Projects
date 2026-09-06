/*
** EPITECH PROJECT, 2018
** my_print_digits
** File description:
** Displays all the digits, on a single line, in ascending order
*/

int my_print_digits(void)
{
    char digits = 48;

    while (digits != 58) {
        my_putchar(digits);
        digits = digits + 1;
    }
    return (0);
}
