/*
** EPITECH PROJECT, 2018
** header
** File description:
** header lib infadd
*/

#ifndef HEAD_H_
#define HEAD_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define EXIT_SUCCESS 0
#define EXIT_ERROR 84

struct math {
    float **key;
    int size_key;
};

int my_strlen(char const *);
void my_puterror(char const *);
int my_strcmp(char const *, char const *);

int cipher(int, char **);
int **is_ext_atio(int *, int **, int, struct math *);
int nbr_line_for_malloc(int, struct math *);
void display_tab_2d_int(int **, int, int);
int is_ext_product_matrix_two(int, int, int **, struct math *);
void encrypted(char **, struct math *, int);
int create_key(struct math *, char *);
void display_key(struct math *);
int check_error(int, char **);

#endif
