/*
** EPITECH PROJECT, 2020
** castmania.c
** File description:
** daytwo
*/

#include <stdio.h>
#include "castmania.h"

void exec_operation(instruction_type_t instruction_type, void *data)
{
    struct instruction_s *info = data;
    struct addition_t *operation = ((instruction_t *)data)->operation;

    if (instruction_type == ADD_OPERATION) {
        exec_add(info->operation);
        if (info->output_type == VERBOSE) {
            printf("%d\n", ((addition_t *)operation)->add_op.res);
        }
    }
    if (instruction_type == DIV_OPERATION) {
        exec_div(info->operation);
        if (info->output_type == VERBOSE) {
            if (((division_t *)operation)->div_type == INTEGER) {
                printf("%d\n",
                ((integer_op_t *)((division_t *)operation)->div_op)->res);
            } else {
                printf("%d\n",
                ((decimale_op_t *)((division_t *)operation)->div_op)->res);
            }
        }
    }
}

void exec_instruction(instruction_type_t instruction_type, void *data)
{
    int *value = data;
    float *value_float = data;

    if (instruction_type == PRINT_INT) {
        printf("%d\n", *value);
    } else if (instruction_type == PRINT_FLOAT) {
        printf("%f\n", *value_float);
    } else {
        exec_operation(instruction_type, data);
    }
}