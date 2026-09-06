/*
** EPITECH PROJECT, 2019
** sort_alpha
** File description:
** sort_alpha
*/

#include "my_lib.h"

int analyze_chara(int, char);
char  **destroy_ligne(char **, int);

int sort_alpha(char *tab[], int ac)
{
    int i = 'A';
    int first = 0;

    for (; i <= 'Z'; i++)
        for (int i_two = 0; i_two < ac; i_two++) {
            if (analyze_chara(i, tab[i_two][0]) == 1) {
                if (first == 1) {
                    my_putstr(" ");
                }
                first = 1;
                destroy_ligne(tab, i_two);
            }
        }
    return (0);
}
