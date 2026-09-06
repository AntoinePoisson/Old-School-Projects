/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include "my_lib.h"

int word_count(char const * str)
{
    int nbr = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z' && str[i + 1] == ' ' )||
            (str[i] >= 'a' && str[i] <= 'z' && str[i + 1] == ' '))
            nbr++;
    }
    nbr++;
    return (nbr);
}

char **my_str_to_word_array(char const *str, int *size)
{
    int count = word_count(str);
    char **array = malloc(sizeof(char *) * (count + 1));
    int a = 0;
    int length = 0;
    int i_three = 0;

    for (int i = 0; str[i] != '\0'; ) {
        if (i > 1 && str[i - 1] == '\0')
            break;
        i_three = i;
        for (; str[i] != ' ' && str[i] != '\0' && str[i] != '\t'; i++)
            length++;
        if (str[i] == ' ' || str[i] == '\0' || str[i] == '\t') {
            array[a] = malloc(sizeof(char) * (length + 1));
            *size += 1;
            for (int i_two = 0; i_two <= length && str[i_three] != '\0' &&
                 str[i_three] != ' ' && str[i_three] != '\t';
                 i_two++, i_three++)
                array[a][i_two] = str[i_three];
            length = 0;
            a++;
        }
        if (str[i] != '\0')
            i++;
    }
    array[a] = NULL;
    return (array);
}
