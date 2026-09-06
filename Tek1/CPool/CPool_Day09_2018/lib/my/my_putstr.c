/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** Write a function that displays,onetoone, the characters of a string
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int carac = 0;

    for (carac = 0; str[carac] != '\0'; carac = carac + 1)
        my_putchar(str[carac]);
    return (0);
}
