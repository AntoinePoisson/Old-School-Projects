/*
** EPITECH PROJECT, 2018
** my_sort_int_array
** File description:
** Day08 task03 my_sort_int_array
*/

void my_putchar(char c);
int my_putstr(char const *str);

int my_show_word_array(char *const *tab)
{
    for (int i = 0; tab[i] != 0; i = i + 1) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return (0);
}
