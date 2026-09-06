/*
** EPITECH PROJECT, 2018
** do_op
** File description:
** task02 Day10
*/

int my_getnbr(char const *str);

int my_strlen(char const *str)
{
    int compteur = 0;
    int i = 0;

    for (i = 0; str[i] != '\0'; i = i + 1)
        compteur = compteur + 1;
    return (compteur);
}

void my_putchar(char c)
{
    write(1, &c, 1);
    return;
}

int my_putstr(char const *str)
{
    int carac = 0;

    for (carac = 0; str[carac] != '\0'; carac = carac + 1)
        my_putchar(str[carac]);
    return (0);
}

int check_errors (int ac, char *av[])
{
    if (ac != 4)
        return (84);
    if (my_getnbr(av[1]) == 0 || my_getnbr(av[3]) == 0)
        return (84);
    return (0);
}
