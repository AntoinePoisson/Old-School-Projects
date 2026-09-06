/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>

static int find_word(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    for (; (str[i] == ' ' && str[i] != '\0') ||
        (str[i] == '\r' && str[i] != '\0'); i++) {
    }
    return (i);
}

char *my_strcpy_(char *dest, char const *src, int start, int limit)
{
    int i = 0;

    for (; i != limit; i++, start++)
        dest[i] = src[start];
    dest[i] = '\0';
    return (dest);
}

static int word_count(char const *str)
{
    int count = 1;

    if (str == NULL)
        return (1);
    for (int i = find_word(str); str[i] != '\0'; i++)
        if ((str[i] == ' ' && str[i + 1] != ' ') ||
            (str[i] == '\r' && str[i + 1] != '\r'))
            count++;
    return (count);
}

char **my_str_to_word_array(char const *str)
{
    char **array = malloc(sizeof(char *) * (word_count(str) + 1));
    int a = 0;
    int length = 0;
    int start = find_word(str);

    if (str == NULL) {
        free(array);
        return (NULL);
    }
    for (int i = find_word(str); str[i] != '\0'; a++, length = 0, start = i) {
        for (; str[i] != ' ' && str[i] != '\0' && str[i] != '\r'; i++)
            length++;
        if ((array[a] = malloc(sizeof(char) * (length + 1))) == NULL)
            return (NULL);
        my_strcpy_(array[a], str, start, length);
        for (; (str[i] == ' ' && str[i] != '\0') || (str[i] == '\r' &&
            str[i] != '\0'); i++);
    }
    array[a] = NULL;
    return (array);
}