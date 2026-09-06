/*
** EPITECH PROJECT, 2020
** stringh
** File description:
** stringh
*/

#ifndef STRING_H
#define STRING_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct string_s string_t;

struct string_s
{
    char *str;

    void (*assign_s)(string_t *, const string_t *);
    void (*assign_c)(string_t *, const char *);
    void (*append_s)(string_t *, const string_t *);
    void (*append_c)(string_t *, const char *);
    char (*at)(const string_t *, size_t );
    void (*clear)(string_t *);
    int (*size)(const string_t *);
    int (*compare_s)(const string_t *, const string_t *);
    int (*compare_c)(const string_t *, const char *);
    size_t (*copy)(const string_t *, char *, size_t, size_t);
    const char *(*c_str)(const string_t *);
    int (*empty)(const string_t *);
    int (*find_s)(const string_t *, const string_t *, size_t);
    int (*find_c)(const string_t *, const char *, size_t);
} ;

void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);
void assign_c(string_t *this, const char *s);
void assign_s(string_t *this, const string_t *str);
void append_s(string_t *this, const string_t *ap);
void append_c(string_t *this, const char *ap);
char at(const string_t *this, size_t pos);
void clear(string_t *this);
int size(const string_t *this);
int compare_s(const string_t *this, const string_t *str);
int compare_c(const string_t *this, const char *str);
size_t copy(const string_t *this, char *s, size_t n, size_t pos);
const char *c_str(const string_t *this);
int empty(const string_t *this);
int find_s(const string_t *this, const string_t *str, size_t pos);
int find_c(const string_t *this, const char *str, size_t pos);


#endif