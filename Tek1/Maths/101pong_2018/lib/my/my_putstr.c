/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** D4, function that displays, one_to_one, the characters of a string
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int carac = 0;

    for (carac = 0; str[carac] != '\0'; carac = carac + 1)
        my_putchar(str[carac]);
    return (0);
}
