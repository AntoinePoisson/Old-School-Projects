/*
** EPITECH PROJECT, 2020
** ptr_tricks
** File description:
** ptr_tricks
*/

#include <stdlib.h>
#include <stdio.h>
#include "ptr_tricks.h"

int get_array_nb_elem(const int *ptr1, const int *ptr2)
{
    if (ptr1 > ptr2) {
        return ((ptr1 - ptr2));
    } else {
        return ((ptr2 - ptr1));
    }
}

whatever_t *get_struct_ptr(const int *member_ptr)
{
    whatever_t *structure;
    int *pos_structure = (int *)structure;
    int *pos_member = &(structure->member);

    return ((whatever_t *)(member_ptr - (pos_member - pos_structure)));
}
