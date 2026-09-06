/*
** EPITECH PROJECT, 2018
** my_putstr_color_int
** File description:
** D4, function that displays, one to one, the characters of a string
*/

void my_putchar_color_int(char c);

int my_putstr_color_int(char const *str)
{
    int carac = 0;

    for (carac = 0; str[carac] != '\0'; carac = carac + 1)
        my_putchar_color_int(str[carac]);
    return (0);
}
