/*
** EPITECH PROJECT, 2020
** new.c
** File description:
** new file
*/

#include "new.h"

Object *va_new(const Class *class, va_list* ap)
{
    Object *new_obj = malloc(class->__size__);

    if (!new_obj)
        raise("Error Memory");
    memcpy(new_obj, class, class->__size__);
    if (class->__ctor__)
        class->__ctor__(new_obj, ap);
    va_end(*ap);
    return (new_obj);
}

Object *new(const Class *class, ...)
{
    va_list ap;

    if (!class)
        raise("No class");
    va_start(ap, class);
    return (va_new(class, &ap));
}

void delete(Object *ptr)
{
    Class *class = NULL;

    if (!ptr)
        raise("No Object");
    class = (Class *)ptr;
    if (ptr && class->__dtor__)
        class->__dtor__(ptr);
    free(ptr);
    ptr = NULL;
}
