/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** affichage
*/

void my_putchar(char c)
{
    write(1, &c, 1);
    return;
}
