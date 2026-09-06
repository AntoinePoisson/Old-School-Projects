/*
** EPITECH PROJECT, 2018
** my_lib.h
** File description:
** all headers of my lib
*/

#ifndef MY_LIB_H
# define MY_LIB_H

#ifndef EXIT_SUCCESS
# define EXIT_SUCCESS 0
#endif

#ifndef EXIT_ERROR
# define EXIT_ERROR 84
#endif

#include "defender.h"

void display_highscore(variable_t *sf);
void display_highscore_transition(variable_t *sf);
void create_bg(variable_t *sf);
void create_music(variable_t *sf);
void create_menu(variable_t *sf);
void create_end_level(variable_t *sf);
void open_window(variable_t *sf);
int is_runner(variable_t *sf, char *av[], int ac);
void check_argument(char *av[], int ac, variable_t *sf);
void create_bg(variable_t *sf);
void create_end_level(variable_t *sf);
int open_file_highscore(void);
int analyse_file(char *file, int nbr);
void position_obj_menu(variable_t *sf);
void create_bg_menu(variable_t *sf);
void create_ressources(variable_t *sf);
int count_arg(char *arg[]);
char *get_next_line(int fd);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_isneg(int nb);
int my_is_prime(int nb);
char *my_malloc(int size);
char **my_malloc_two_d(int size);
int my_printf(char *str, ...);
void my_putchar(char c);
int my_putnbr(int nb);
int my_putstr(char const *str);
int my_puterror(char const *str);
char *my_revstr(char *str);
void my_sort_int_array(int *tab, int size);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *str);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char **my_str_to_word_array(char const *str);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);

#endif
