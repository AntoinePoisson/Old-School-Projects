/*
** EPITECH PROJECT, 2018
** my_lib.h
** File description:
** all headers of my lib
*/

#ifndef MY_LIB_H
#define MY_LIB_H

int mprintf(char const *str, ...);
int my_isneg(int nb);
int my_putnbr(int nb);
int my_is_prime(int nb);
int count_arg(char *arg[]);
int is_num(char const *str);
int my_strerror(int errnum);
int my_strlen(char const *str);
int my_putstr(char const *str);
int my_getnbr(char const *str);
int my_puterror(char const *str);
int my_str_isnum(char const *str);
int my_compute_square_root(int nb);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_compute_power_rec(int nb, int power);
int str_comp(char const *s1, char const *s2);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_malloc(int size);
char *my_revstr(char *str);
char *get_next_line(int fd);
char *my_strdup(char const *str);
char *my_strcapitalize(char *str);
char *my_strchr(char *str, int c);
char *read_file(char const *filepath);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
char *my_strstr(char *str, char const *to_find);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strncat(char *dest, char const *src, int nb);
char **my_malloc_two_d(int size);
char **my_str_to_word_array(char const *str);
void my_putchar(char c);
void my_swap(int *a, int *b);
void my_sort_int_array(int *tab, int size);

#endif
