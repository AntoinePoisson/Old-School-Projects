/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** Write a function that counts string.
*/

int my_strlen(char const *str)
{
    int compteur = 0;
    int i = 0;

    for (i = 0; str[i] != '\0'; i = i + 1)
        compteur = compteur + 1;
    return (compteur);
}
