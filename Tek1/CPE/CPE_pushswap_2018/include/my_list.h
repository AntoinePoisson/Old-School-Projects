/*
** EPITECH PROJECT, 2018
** my_list
** File description:
** list
*/

#ifndef MY_LIST_H
#define MY_LIST_H

typedef struct linked_list_s
{
    char *data;
    struct linked_list_s *next;
    struct linked_list_s *previous;
} linked_list_t;

typedef struct control_list_s
{
    unsigned int length;
    struct linked_list_s *tail;
    struct linked_list_s *head;
} control_list_t;

#endif
