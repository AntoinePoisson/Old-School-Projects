/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** d3 function that displays the number given as a parameter
*/

void my_putchar(char c);

int my_put_adress(long nb)
{
    long quotient = 0;
    long reste = 0;

    if (nb >= 0) {
        quotient = nb % 16;
        reste = nb / 16;
        if (reste != 0)
            my_put_adress(reste);
        if (quotient <= 9)
            my_putchar(quotient + '0');
        if (quotient > 9)
            my_putchar(quotient + 87);
    }
    if (nb < 0)
        my_put_adress(-nb);
    return (0);
}
