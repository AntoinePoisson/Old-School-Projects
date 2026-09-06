/*
** EPITECH PROJECT, 2018
** struct
** File description:
** struct
*/

typedef struct vector_s
{
    float x;
    float y;
    float z;
} vector_t;

typedef struct point_s
{
    float x;
    float y;
    float z;
} point_t;

typedef struct equa_parametric_s
{
    float x;
    float y;
    float z;
    struct vector_s vector;
    struct point_s point;
    float coefficient;
} equa_parametric_t;

typedef struct var_s
{
    float solve_equa_one;
    float solve_equa_two;
} var_t;