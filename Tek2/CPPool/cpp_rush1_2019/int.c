/*
** EPITECH PROJECT, 2020
** cpp_rush1
** File description:
** Exercice 02
*/

#include <malloc.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include "int.h"

Object *new(const Class *class, ...);

typedef struct
{
    Class base;
    int x;
} IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    if (!this)
        raise("Error");
    this->x = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    if (this)
        return;
}

static char *Int_str(IntClass *this)
{
    int size = 9 + 11;
    char *result = malloc(sizeof(char) * (size + 1));

    if (!this || !result)
        raise("Error");
    memset(result, 0, (size+1)*sizeof(char));
    snprintf(result, size, "<Int (%d)>", (int)this->x);
    return (result);
}

static Object *Int_add(const Object *this, const Object *other)
{
    IntClass *value_a = (IntClass *)this;
    IntClass *value_b = (IntClass *)other;
    int a = 0;

    if (this && other)
        a = (int)value_a->x + (int)value_b->x;
    else
        raise("Empty Obj");
    return (new(Int, a));
}

static Object *Int_sub(const Object *this, const Object *other)
{
    IntClass *value_a = (IntClass *)this;
    IntClass *value_b = (IntClass *)other;
    int a = 0;

    if (this && other)
        a = (int)value_a->x - (int)value_b->x;
    else
        raise("Empty Obj");
    return (new(Int, a));
}

static Object *Int_mul(const Object *this, const Object *other)
{
    IntClass *value_a = (IntClass *)this;
    IntClass *value_b = (IntClass *)other;
    int a = 0;

    if (this && other)
        a = (int)value_a->x * (int)value_b->x;
    else
        raise("Empty Obj");
    return (new(Int, a));
}

static Object *Int_div(const Object *this, const Object *other)
{
    IntClass *value_a = (IntClass *)this;
    IntClass *value_b = (IntClass *)other;
    int a = 0;

    if (this && other && (int)value_b->x != 0)
        a = (int)value_a->x / (int)value_b->x;
    else if ((int)value_b->x != 0)
        raise("Empty Obj");
    else
        raise("div 0");
    return (new(Int, a));
}

static bool Int_eq(const Object *this, const Object *other)
{
    IntClass *this2 = (IntClass *)this;
    IntClass *other2 = (IntClass *)other;

    if (this2 && other2 && this2->x == other2->x)
        return (true);
    else if (!this2 || !other2)
        raise("Empty Obj");
    return (false);
}

static bool Int_gt(const Object *this, const Object *other)
{
    IntClass *this2 = (IntClass *)this;
    IntClass *other2 = (IntClass *)other;

    if (this2 && other2 && this2->x > other2->x)
        return (true);
    else if (!this2 || !other2)
        raise("Empty Obj");
    return (false);
}

static bool Int_lt(const Object *this, const Object *other)
{
    IntClass *this2 = (IntClass *)this;
    IntClass *other2 = (IntClass *)other;

    if (this2 && other2 && this2->x < other2->x)
        return (true);
    else if (!this2 || !other2)
        raise("Empty Obj");
    return (false);
}

static const IntClass _description = {
    {
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .x = 0
};

const Class *Int = (const Class *)&_description;
