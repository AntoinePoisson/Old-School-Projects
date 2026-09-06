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
    int a = 0;

    for (a = 0; a < argc; a++);
    a--;
    for (i = 0; i < argc; i++) {
       my_putstr(argv[a]);
       my_putchar('\n');
       a--;
    }
    return (0);
}
