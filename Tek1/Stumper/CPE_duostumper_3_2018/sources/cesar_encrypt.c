/*
** EPITECH PROJECT, 2019
** Duo_Stumper_3
** File description:
** encrypt the file
*/

static int determine_order_in_alphabet_lowcase(char c, char const **alphabet)
{
    for (int i = 1; alphabet[0][i] != '\0'; i++)
        if (c == alphabet[0][i])
            return (i);
    return (84);
}

static int determine_order_in_alphabet_upcase(char c, char const **alphabet)
{
    for (int i = 1; alphabet[1][i] != '\0'; i++)
        if (c == alphabet[1][i])
            return (i);
    return (84);
}

static int find_good_charac(int alpha, int nbr)
{
    int result = alpha + nbr;

    if (result < 1) {
        while (result < 1)
            result = result + 26;
    }
    else if (result > 26) {
        while (result > 26)
            result = result - 26;
    }
    return (result);
}

char *cesar_encrypt(char *file, char const **alphabet, int nb)
{
    int order = 0;

    for (int i = 0; file[i] != '\0'; i++) {
        if (file[i] >= 'A' && file[i] <= 'Z') {
            order = determine_order_in_alphabet_upcase(file[i], alphabet);
            order = find_good_charac(order, nb);
            file[i] = alphabet[1][order];
        }
        else if (file[i] >= 'a' && file[i] <= 'z') {
            order = determine_order_in_alphabet_lowcase(file[i], alphabet);
            order = find_good_charac(order, nb);
            file[i] = alphabet[0][order];
        }
    }
    return (file);
}
