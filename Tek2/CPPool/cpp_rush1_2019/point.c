/*
** EPITECH PROJECT, 2020
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include <stdarg.h>
#include "point.h"

Object *new(const Class *class, ...);

typedef struct
{
    Class base;
    int x;
    int y;
} PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    if (!this)
        raise("Error");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    if (this)
        return;
}

static char *Point_str(PointClass *this)
{
    int size = !this ? 1 : ((Class *)this)->__size__;
    char *result = malloc(sizeof(char) * size + 1);

    if (!this || !result)
        raise("Wrong Parameter");
    for (int i = 0; i != size; i++)
        result[i] = '\0';
    snprintf(result, size, "<Point (%d, %d)>", (int)this->x, (int)this->y);
    return (result);
}

static Object *Point_add(const Object *this, const Object *other)
{
    PointClass *value_a = (PointClass *)this;
    PointClass *value_b = (PointClass *)other;
    int a = 0;
    int b = 0;

    if (!this || !other)
        raise("Wrong Parameter");
    a = (int)value_a->x + (int)value_b->x;
    b = (int)value_a->y + (int)value_b->y;
    return (new(Point, a, b));
}

static Object *Point_sub(const Object *this, const Object *other)
{
    PointClass *value_a = (PointClass *)this;
    PointClass *value_b = (PointClass *)other;
    int a = 0;
    int b = 0;

    if (!this || !other)
        raise("Wrong Parameter");
    a = (int)value_a->x - (int)value_b->x;
    b = (int)value_a->y - (int)value_b->y;
    return (new(Point, a, b));
}

static const PointClass _description = {
    {
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Point = (const Class *)&_description;