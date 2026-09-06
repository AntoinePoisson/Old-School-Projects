/*
** EPITECH PROJECT, 2018
** my_print_params
** File description:
** Write a program that displays its arguments.
*/

void my_putchar(char c);

int my_putstr(char const *str);

int main(int argc, char *argv[])
{
    int i = 0;

    for (i = 0; i < argc; i++) {
       my_putstr(argv[i]);
       my_putchar('\n');
    }
    return (0);
}
