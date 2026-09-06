/*
** EPITECH PROJECT, 2020
** ex00
** File description:
** ex00
*/

#ifndef ex00_H
#define ex00_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct cthulhu_s {
    int m_power;
    char *m_name;
} cthulhu_t;

typedef struct koala_s
{
    cthulhu_t m_parent;
    char m_is_a_legend;
} koala_t;


cthulhu_t *new_cthulhu();
void print_power(cthulhu_t *);
void attack(cthulhu_t *);
void sleeping(cthulhu_t *);
koala_t *new_koala(char *, char);
void eat(koala_t *);

#endif /* !ex00 */
