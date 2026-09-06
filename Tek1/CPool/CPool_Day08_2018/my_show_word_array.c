/*
** EPITECH PROJECT, 2018
** my_show_word_array
** File description:
** Write function that displays the content of an array
*/

void my_putchar(char c);
int my_putstr(char const *str);

int my_show_word_array(char * const *tab)
{
    int i = 0;

    for (i = 0; tab[i] != '\0'; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return (0);
}

