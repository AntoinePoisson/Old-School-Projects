/*
** EPITECH PROJECT, 2020
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include <stdarg.h>
#include "object.h"
#include "float.h"

Object *new(const Class *class, ...);

typedef struct
{
    Class base;
    float x;
} FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    if (!this)
        raise("Error");
    this->x = va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    if (this)
        return;
}

static char *Float_str(FloatClass *this)
{
    int size = !this ? 1 : ((Class *)this)->__size__;
    char *result = malloc(sizeof(char) * size + 1);

    if (!this || !result)
        raise("Wrong Parameter");
    for (int i = 0; i != size; i++)
        result[i] = '\0';
    snprintf(result, size, "<Float (%f)>", (float)this->x);
    return (result);
}

static Object *Float_add(const Object *this, const Object *other)
{
    FloatClass *value_a = (FloatClass *)this;
    FloatClass *value_b = (FloatClass *)other;
    float a = 0.0;

    if (!this || !other)
        raise("Wrong Parameter");
    a = (float)value_a->x + (float)value_b->x;
    return (new(Float, a));
}

static Object *Float_sub(const Object *this, const Object *other)
{
    FloatClass *value_a = (FloatClass *)this;
    FloatClass *value_b = (FloatClass *)other;
    float a = 0.0;

    if (!this || !other)
        raise("Wrong Parameter");
    a = (float)value_a->x - (float)value_b->x;
    return (new(Float, a));
}

static Object *Float_mul(const Object *this, const Object *other)
{
    FloatClass *value_a = (FloatClass *)this;
    FloatClass *value_b = (FloatClass *)other;
    float a = 0.0;

    if (!this || !other)
        raise("Wrong Parameter");
    a = (float)value_a->x * (float)value_b->x;
    return (new(Float, a));
}

static Object *Float_div(const Object *this, const Object *other)
{
    FloatClass *value_a = (FloatClass *)this;
    FloatClass *value_b = (FloatClass *)other;
    float a = 0.0;

    if (!this || !other)
        raise("Wrong Parameter");
    if ((float)value_b->x == 0)
        raise("div by 0");
    a = (float)value_a->x / (float)value_b->x;
    return (new(Float, a));
}

static bool Float_eq(const Object *this, const Object *other)
{
    FloatClass *value_a = (FloatClass *)this;
    FloatClass *value_b = (FloatClass *)other;

    if (!this || !other)
        raise("Wrong Parameter");
    if ((float)value_a->x  == (float)value_b->x)
        return (true);
    return (false);
}

static bool Float_lt(const Object *this, const Object *other)
{
    FloatClass *value_a = (FloatClass *)this;
    FloatClass *value_b = (FloatClass *)other;

    if (!this || !other)
        raise("Wrong Parameter");
    if ((float)value_a->x < (float)value_b->x)
        return (true);
    return (false);
}

static bool Float_gt(const Object *this, const Object *other)
{
    FloatClass *value_a = (FloatClass *)this;
    FloatClass *value_b = (FloatClass *)other;

    if (!this || !other)
        raise("Wrong Parameter");
    if ((float)value_a->x > (float)value_b->x)
        return (true);
    return (false);
}

static const FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .x = 0
};

const Class *Float = (const Class *)&_description;
