/*
** EPITECH PROJECT, 2018
** is_pushswap
** File description:
** radix header
*/

#ifndef RADIX_H
#define RADIX_H

#include <stddef.h>
#include "my_list.h"
#include "my_lib.h"

void take_element_one(control_list_t **SRC, control_list_t **DEST);
void take_element_two(control_list_t **SRC, control_list_t **DEST);
void rotation_first_list_one(control_list_t **SRC);
void rotation_first_list_two(control_list_t **SRC);
void rotation_end_list_two(control_list_t **SRC);

#endif
