/*
** EPITECH PROJECT, 2019
** navy
** File description:
** navy.h
*/

#ifndef _NAVY_H_
#define _NAVY_H_

#include "mgetline.h"
#include <signal.h>
#include <ucontext.h>
#include <errno.h>

typedef struct battleship_s {
    pid_t my_pid;
    pid_t enemy_pid;
    char **my_map;
    char **enemy_map;
    int x;
    int end;
    char *entry;
    int attack;
    int y;
} battleship_t;

void mput(char c);
void mputstr(char const *s);
int mstrlen(char const *s);
int misnum(char const *str);
int mstrcmp(char const *s1, char const *s2);
char *mrevstr(char *s);
int itobin(int nb);
int bintoi(int nb);
int mput_nbr(int nb);
int mgetnbr(char const *s);
int game_help(void);
int error_handling(int ac, char **av);
char **str_to_arr(char *str);
char *create_buffer(char *buff, int fd);
int battleship(char **av);
int connection(char **av, battleship_t *navy);
int fill_map(char ***my_map, char ***enemy_map, char **av);
char *recover_signal(char add);
void receive_signal(int signal, siginfo_t *info, void *context);
int redirect_signal(void);
void display_map(char **map);
int torpedo(char **av, battleship_t *navy, int round);
int check_hit(char **av, battleship_t *navy, int round);
int end_of_game(char **my_map, char **enemy_map, int end);

#endif
