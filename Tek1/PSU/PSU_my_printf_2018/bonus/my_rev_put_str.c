/*
** EPITECH PROJECT, 2018
** my_rev_put_str
** File description:
** D6, function that reverses a string.
*/

int my_strlen(char const *str);
int my_putstr(char *str);
int my_putstr_color_char(char *str);

void *my_rev_put_str(char *str)
{
    int i = 0;
    int a = 0;
    char str_rev[my_strlen(str)];

    for (i = 0; str[i] != '\0'; i++);
    for (i = i - 1; i >= 0; i--) {
        str_rev[a] = str[i];
        a++;
    }
    str_rev[a] = '\0';
    my_putstr_color_char(str_rev);
}
