/*
** EPITECH PROJECT, 2020
** header
** File description:
** header
*/

#ifndef MALLOC_H
#define MALLOC_H

#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define SIZE_PAGE sysconf(_SC_PAGESIZE)

typedef struct node_s
{
    unsigned long size;
    bool is_free;
    struct node_s *next;
    struct node_s *prev;
} node_t;

typedef struct head_s
{
    size_t nbr_page;
    struct node_s *list;
    struct node_s *tail;
    node_t *limit;
} head_t;

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

head_t **get_start(bool activation);
size_t convertion_parameter(size_t size);
void *reload_memory_same_size(head_t **head, int index);
int research_space_in_list(size_t size, head_t **head);

#endif
