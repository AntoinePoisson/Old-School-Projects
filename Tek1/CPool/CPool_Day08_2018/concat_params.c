/*
** EPITECH PROJECT, 2018
** concat_params
** File description:
** Write a function that turns the command-line given arguments into a single string.
*/

#include <stdlib.h>

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *concat_params(int argc, char **argv)
{
    int i = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int size_str = 0;
    char *memoireAlloue = NULL;

    for (a = 0; a < argc; a++)
        size_str = size_str + my_strlen(argv[a]);
    memoireAlloue = malloc(sizeof(char) * (size_str));
    while (b < argc) {
        i = 0;
        for (i = 0; argv[b][i] != '\0'; i++) {
            memoireAlloue[c] = argv[b][i];
            c++;
        }
        if (b != argc - 1) {
            memoireAlloue[c] = '\n';
            c++;
        }
        b++;
    }
    memoireAlloue[c] = '\0';
    return (memoireAlloue);
}
