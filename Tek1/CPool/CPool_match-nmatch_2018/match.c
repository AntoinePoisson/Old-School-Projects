/*
** EPITECH PROJECT, 2018
** Match
** File description:
** he purpose of this function is to find out if two strings match
*/

int my_strlen(char const *str)
{
    int compteur = 0;
    int i = 0;

    for (i = 0; str[i] != '\0'; i = i + 1)
        compteur = compteur + 1;
    return (compteur);
}

int checkage(char s1[], char s2[])
{
    int i = 0;
    int resultat = 0;

    for (i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return (0);
    }
    return (1);
}

char s2(char s1[], char s2[])
{
    int i = 0;
    int a = 0;
    int b = 0;
    int constance = 0;
    int compteur = 0;
    int reponse = 0;
    char save_carac[my_strlen(s1)];
    char s2_bis[my_strlen(s1)];

    for (i = 0; s1[constance] != '\0' || s2[a + compteur] != '\0'; i++) {
        if (s2[a + compteur] == '*') {
                save_carac[b] = s2[a + compteur + 1];
            for (i; save_carac[b] != s1[i] && s1[i] != '\0'; i++)
                 s2_bis[i] = s1[i];
            b++;
            compteur++;
        }
        s2_bis[i] = s2[a + compteur];
        a++;
	if (s1[constance] != '\0')
	    constance++;
    }
    s2_bis[i] = '\0';
    reponse = checkage(s1, s2_bis);
    return (reponse);
}

int check_errors(int ac)
{
    if (ac != 3)
        return(0);
    return (1);
}

int match(int ac, char *av[])
{
    int resultat = 0;
    
    if (check_errors(ac) != 1)
        return (0);
    resultat = s2(av[1], av[2]);
    return (resultat);
}
