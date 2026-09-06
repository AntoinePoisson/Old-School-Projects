/*
** EPITECH PROJECT, 2020
** cpp_rush_1 
** File description:
** piscine
*/

#include <malloc.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "char.h"

Object *new(const Class *class, ...);

typedef struct
{
    Class base;
    char c;
} CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    if (!this)
        raise("Error");
    this->c = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    if (this)
        return;
}

static char *Char_str(CharClass *this)
{
    int size = 12;
    char *result = malloc(sizeof(char) * (size + 1));

    if (!this || !result)
        raise("Wrong Parameter");
    memset(result, 0, (size+1)*sizeof(char));
    snprintf(result, size, "<Char (%c)>", (char)this->c);
    return (result);
}

static Object *Char_add(const Object *this, const Object *other)
{
    CharClass *value_a = (CharClass *)this;
    CharClass *value_b = (CharClass *)other;
    char a = 0;

    if (this && other)
        a = (char)value_a->c + (char)value_b->c;
    else
        raise("Empty Obj");
    return (new(Char, a));
}

static Object *Char_sub(const Object *this, const Object *other)
{
    CharClass *value_a = (CharClass *)this;
    CharClass *value_b = (CharClass *)other;
    char a = 0;

    if (this && other)
	a = (char)value_a->c - (char)value_b->c;
    else
        raise("Empty Obj");
    return (new(Char, a));
}
static Object *Char_div(const Object *this, const Object *other)
{
    CharClass *value_a = (CharClass *)this;
    CharClass *value_b = (CharClass *)other;
    char a = 0;

    if (this && other && (char)value_b->c != 0)
	a = (char)value_a->c / (char)value_b->c;
    else if ((char)value_b->c != 0)
        raise("Empty Obj");
    else
        raise("div 0");
    return (new(Char, a));
}

static bool Char_eq(const Object *this, const Object *other)
{
    CharClass *this2 = (CharClass *)this;
    CharClass *other2 = (CharClass *)other;

    if (this2 && other2 && this2->c == other2->c)
        return (true);
    else if (!this2 || !other2)
        raise("Empty Obj");
    return (false);
}

static bool Char_gt(const Object *this, const Object *other)
{
    CharClass *this2 = (CharClass *)this;
    CharClass *other2 = (CharClass *)other;

    if (this2 && other2 && this2->c > other2->c)
        return (true);
    else if (!this2 || !other2)
        raise("Empty Obj");
    return (false);
}

static bool Char_lt(const Object *this, const Object *other)
{
    CharClass *this2 = (CharClass *)this;
    CharClass *other2 = (CharClass *)other;

    if (this2 && other2 && this2->c < other2->c)
	return (true);
    else if (!this2 || !other2)
        raise("Empty Obj");
    return (false);
}

static Object *Char_mul(const Object *this, const Object *other)
{
    CharClass *value_a = (CharClass *)this;
    CharClass *value_b = (CharClass *)other;
    char a = 0;

    if (this && other)
        a = (char)value_a->c * (char)value_b->c;
    else
        raise("Empty Obj");
    return (new(Char, a));
}


static const CharClass _description = {
    {
     	.__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
	.__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .c = 0
};

const Class *Char = (const Class *)&_description;
