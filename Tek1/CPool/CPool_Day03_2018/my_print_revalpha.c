/*
** EPITECH PROJECT, 2018
** my_print_revalpha
** File description:
** Beginning with z displays the lowercase alphabet in descending order
*/

int my_print_revalpha(void)
{
    char alphabet = 122;

    while (alphabet >= 97) {
        my_putchar(alphabet);
        alphabet = alphabet - 1;
    }
    return (0);
}
