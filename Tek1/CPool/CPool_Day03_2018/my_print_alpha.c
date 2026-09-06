/*
** EPITECH PROJECT, 2018
** my_print_alpha
** File description:
** Beginning with a displays the lowercase alphabet in ascending order.
*/

int my_print_alpha(void)
{
    char alphabet = 97;

    while (alphabet <= 122) {
        my_putchar(alphabet);
        alphabet = alphabet + 1;
    }
    return (0);
}
