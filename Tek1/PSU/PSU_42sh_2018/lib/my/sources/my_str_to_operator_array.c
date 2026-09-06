/*
** EPITECH PROJECT, 2018
** my_str_to_operator_array.c
** File description:
** my_str_to_operator_array
*/

#include <stdlib.h>

char *my_malloc(int count);
char **my_malloc_two_d(int count);
char *my_strcpy_(char *dest, char const *src, int start, int limit);

static int is_operator_two(char const *str, int *i, int *size)
{
    if ((str[*i] == '>') || (str[*i] == '|') ||
        (str[*i] == ';') || (str[*i] == '(') ||
        (str[*i] == '<'))
        return (1);
    if ((str[*i] == '<' && str[*i + 1] == '<') ||
        (str[*i] == '>' && str[*i + 1] == '>') ||
        (str[*i] == '|' && str[*i + 1] == '|') ||
        (str[*i] == '&' && str[*i + 1] == '&')) {
        *i += 1;
        *size += 1;
        return (1);
    }
    return (0);
}

static int is_operator_one(char const *str, int *i, int cas)
{
    if (cas == 1) {
        if ((str[*i] == '>' && str[*i + 1] != '>') ||
            (str[*i] == '|' && str[*i + 1] != '|') ||
            (str[*i] == ';') || (str[*i] == '(') ||
            (str[*i] == '<' && str[*i + 1] != '<'))
            return (1);
        if ((str[*i] == '<' && str[*i + 1] == '<') ||
            (str[*i] == '&' && str[*i + 1] == '&') ||
            (str[*i] == '|' && str[*i + 1] == '|') ||
            (str[*i] == '>' && str[*i + 1] == '>')) {
            *i += 1;
            return (1);
        }
    }
    if (cas == 0 && str[*i] != '<' && str[*i] != '>' && str[*i] != '&' &&
        str[*i] != '|' && str[*i] != ';' && str[*i] != '\0' && str[*i] != '(')
        return (1);
    return (0);
}

static int word_count(char const *str)
{
    int count = 1;
    int operator = 0;

    if (str == NULL)
        return (1);
    for (int i = 0; str && str[i] != '\0'; i++) {
        if (is_operator_one(str, &i, 1)) {
            count++;
            operator++;
        }
    }
    count += operator;
    return (count);
}

char **increase_operator(char const *str, char **array, int *a, int *i)
{
    int size = 0;
    int save = *i;

    for (; is_operator_two(str, i, &size); *i += 1, size++);
    if (size == 0)
        return (array);
    *a += 1;
    if ((array[*a] = my_malloc(size + 1)) == NULL)
        return (NULL);
    size += save;
    for (int i2 = 0; save < size; save += 1, i2++)
        array[*a][i2] = str[save];
    return (array);
}

char **my_str_to_operator_array(char const *str)
{
    char **array = my_malloc_two_d(word_count(str) + 1);
    int a = 0;
    int length = 0;
    int start = 0;

    if (str == NULL) {
        free(array);
        return (NULL);
    }
    for (int i = 0; str[i] != '\0'; a++, length = 0, start = i) {
        for (; is_operator_one(str, &i, 0); i++)
            length++;
        if ((array[a] = my_malloc(length + 1)) == NULL)
            return (NULL);
        my_strcpy_(array[a], str, start, length);
        array = increase_operator(str, array, &a, &i);
    }
    array[a] = NULL;
    return (array);
}
