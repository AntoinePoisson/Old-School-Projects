/*
** EPITECH PROJECT, 2018
** my strlen
** File description:
** length of a string
*/

int my_strlen(char const *str)
{
    int index = 0;

    while (str[index] != '\0')
        index += 1;
    return (index);
}
