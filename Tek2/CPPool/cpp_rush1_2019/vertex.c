/*
** EPITECH PROJECT, 2020
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include <stdarg.h>
#include "vertex.h"

Object *new(const Class *class, ...);
typedef struct
{
    Class base;
    int x;
    int y;
    int z;
} VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    if (!this)
        raise("Error");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    if (this)
        return;
}

static char *Vertex_str(VertexClass *this)
{
    int size = !this ? 1 : ((Class *)this)->__size__;
    char *result = malloc(sizeof(char) * size + 1);

    if (!this || !result)
        raise("Wrong Parameter");
    for (int i = 0; i != size; i++)
        result[i] = '\0';
    snprintf(result, size, "<Vertex (%d, %d, %d)>", (int)this->x,
    (int)this->y, (int)this->z);
    return (result);
}

static Object *Vertex_add(const Object *this, const Object *other)
{
    VertexClass *value_a = (VertexClass *)this;
    VertexClass *value_b = (VertexClass *)other;
    int a = 0;
    int b = 0;
    int c = 0;

    if (!this || !other)
        raise("Wrong Parameter");
    a = (int)value_a->x + (int)value_b->x;
    b = (int)value_a->y + (int)value_b->y;
    c = (int)value_a->z + (int)value_b->z;
    return (new(Vertex, a, b, c));
}

static Object *Vertex_sub(const Object *this, const Object *other)
{
    VertexClass *value_a = (VertexClass *)this;
    VertexClass *value_b = (VertexClass *)other;
    int a = 0;
    int b = 0;
    int c = 0;

    if (!this || !other)
        raise("Wrong Parameter");
    a = (int)value_a->x - (int)value_b->x;
    b = (int)value_a->y - (int)value_b->y;
    c = (int)value_a->z - (int)value_b->z;
    return (new(Vertex, a, b, c));
}

static const VertexClass _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class *Vertex = (const Class *)&_description;
