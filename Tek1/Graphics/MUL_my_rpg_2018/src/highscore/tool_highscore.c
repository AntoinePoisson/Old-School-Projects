/*
** EPITECH PROJECT, 2018
** is_menu
** File description:
** menu
*/

#include "my_rpg.h"

char *data_highscore_file(int cas)
{
    int fd = open_file_highscore();
    char *result = malloc(sizeof(char) * 99999);
    static char *buffer = NULL;
    static int i_two = 0;

    if (cas == 0) {
        buffer = malloc(sizeof(char) * 99999);
        i_two = 0;
    }
    if (result == NULL || buffer == NULL || fd == -1 || (cas == 0 &&
        read(fd, buffer, 99999) < 1))
        return ("ERROR");
    for (int i = 0; buffer[i_two] != '|' && buffer[i] != '\0'; i++, i_two++) {
        result[i] = buffer[i_two];
        result[i + 1] = '\0';
    }
    i_two++;
    close(fd);
    return (result);
}

int check_file_highscore(void)
{
    int fd = open_file_highscore();
    int nbr = 0;
    char *fil = my_malloc(sizeof(char) * 9999, 1);

    if (read(fd, fil, 9998) < 1 || analyse_file(fil, nbr) != 0) {
        my_putstr("Invalid Highscore file\n");
        return (84);
    }
    close(fd);
    return (0);
}

char *decrypt_highscore(char *dec)
{
    char *nbr = malloc(sizeof(char) * (my_strlen(dec) * 2 + 2));
    int a = 0;

    if (!nbr)
        return (NULL);
    for (int i = 0; i < my_strlen(dec) * 2 + 2; nbr[i] = '\0', i++);
    for (int i = 0; dec && dec[i] && dec[i] != '\n'; i++) {
        if (dec[i] != '|')
            nbr = my_strcat_charac(nbr, my_itoa(dec[i], 0));
        else {
            for (; nbr[a]; a++);
            nbr[a] = '|';
        }
    }
    nbr[a + 1] = '\0';
    return (nbr);
}

char *dec_to_char(char *dec)
{
    char *nbr = my_malloc(sizeof(char) * (my_strlen(dec) * 2 + 3), 1);

    if (!nbr)
        return (NULL);
    for (int i = 0; i < my_strlen(dec) * 2 + 3; nbr[i] = '\0', i++);
    for (int i = 0; dec && dec[i]; i++) {
        nbr = my_strcat_charac(nbr, my_itoa(dec[i], 0));
    }
    return (nbr);
}

char *char_to_dec(char *nbr)
{
    char *dec = my_malloc(sizeof(char) * (my_strlen(nbr) * 2 + 9), 1);
    char *save = my_malloc(sizeof(char) * 4, 1);
    int i_two = 0;

    if (!nbr || !dec || !save)
        return (NULL);
    for (int i = 0; nbr && nbr[i] && nbr[i + 1]; i += 2, i_two++) {
        save[0] = nbr[i];
        save[1] = nbr[i + 1];
        dec[i_two] = my_getnbr(save);
    }
    return (dec);
}
