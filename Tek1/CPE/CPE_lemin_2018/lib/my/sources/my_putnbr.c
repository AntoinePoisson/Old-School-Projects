/*
** EPITECH PROJECT, 2018
** my_putnbr
** File description:
** D3, function that displays the number given as a parameter
*/

void my_putchar(char c);

int my_putnbr(int nb)
{
    int quotient = 0;
    int reste = 0;

    if (nb >= 0) {
        quotient = nb % 10;
        reste = nb / 10;
        if (reste != 0)
            my_putnbr(reste);
        my_putchar(quotient + '0');
    }
    if (nb < 0) {
        my_putchar(45);
        my_putnbr(-nb);
    }
    return (0);
}
