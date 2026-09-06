/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** handle_input
*/

#include "client.h"

void print_buff(char *buff)
{
    char *buff_no_code = calloc(strlen(buff) + 1, 1);
    char **tab = my_str_to_word_tab(buff, '|');
    char **tab_no_code = NULL;

    if (check_code(buff) == 84) return;
    if (strchr(buff, '|') == NULL) {
        if (strcmp(buff, "400\n") == 0)
            cmd_400(NULL);
        if (strcmp(buff, "405\n") == 0)
            cmd_405(NULL);
        return;
    }
    for (int i = 4, j = 0; buff[i]; i++, j++)
        buff_no_code[j] = buff[i];
    tab_no_code = my_str_to_word_tab(buff_no_code, '|');
    if (buff[0] == '3' || buff[0] == '4')
        return (void)go_to_code(tab, tab_no_code, buff);
    for (int i = 0; tab[i]; i++)
        printf("%s ", tab[i]);
    putchar('\n');
}

void reset_select(fd_set *readfds, int server)
{
    struct timeval timeout = {0, 0};

    FD_ZERO(readfds);
    FD_SET(server, readfds);
    FD_SET(0, readfds);

    if (select(server + 1, readfds, NULL, NULL,
        &timeout) < 0) {
        perror("select");
        exit(0);
    }
}

static int wait_for_write(int sock)
{
    fd_set wset;
    struct timeval out = {3, 0};

    FD_ZERO(&wset);
    FD_SET(sock, &wset);
    return select(FD_SETSIZE, NULL, &wset, NULL, &out);
}

int read_stdin(fd_set *readfds, int client)
{
    char *buffer = NULL;
    size_t size = 0;

    if (!end(0) && FD_ISSET(STDIN_FILENO, readfds)) {
        if (getline(&buffer, &size, stdin) < 0 || !strcmp(buffer, "quit\n")) {
            if (wait_for_write(client) > 0)
                write(client, "", 1);
            close(client);
            exit(0);
        }
        buffer = parser_commandes(buffer);
        if (buffer == NULL)
            printf("Commande Invalid\n");
        else {
            if (wait_for_write(client) > 0)
                write(client, buffer, strlen(buffer));
        }
    }
    free(buffer);
    return Ok;
}
