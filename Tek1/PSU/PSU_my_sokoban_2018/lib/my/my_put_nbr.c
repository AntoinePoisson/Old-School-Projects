/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** D3, function that displays the number given as a parameter
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int quotient = 0;
    int reste = 0;

    if (nb >= 0) {
        quotient = nb % 10;
        reste = nb / 10;
        if (reste != 0)
            my_put_nbr(reste);
        my_putchar(quotient + '0');
    }
    if (nb < 0) {
        my_putchar(45);
        my_put_nbr(-nb);
    }
    return (0);
}
