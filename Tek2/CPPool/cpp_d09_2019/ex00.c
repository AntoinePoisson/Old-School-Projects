/*
** EPITECH PROJECT, 2020
** ex00
** File description:
** ex00
*/

#include "ex00.h"

static void cthulhu_initializer(cthulhu_t *this)
{
    if (!this)
        return;
    this->m_name = strdup("Cthulhu");
    this->m_power = 42;
    printf("----\n");
    printf("Building %s\n", this->m_name);
}

cthulhu_t *new_cthulhu()
{
    cthulhu_t *new = malloc(sizeof(*new));

    if (!new)
        return (NULL);
    cthulhu_initializer(new);
    return (new);
}

void print_power(cthulhu_t *this)
{
    if (!this)
        return;
    printf("Power => %d\n", this->m_power);
}

void attack(cthulhu_t *this)
{
    if (!this && !this->m_name)
        return;
    if (this->m_power >= 42) {
        this->m_power -= 42;
        printf("%s attacks and destroys the city\n", this->m_name);
        return;
    }
    printf("%s can't attack, he doesn't have enough power\n", this->m_name);
}

void sleeping(cthulhu_t *this)
{
    if (this && this->m_name) {
        this->m_power += 42000;
        printf("%s sleeps\n", this->m_name);
    }
}

static void koala_initializer(koala_t *this, char *name, char is_a_legend)
{
    if (!this)
        return;
    if (name)
        this->m_parent.m_name = strdup(name);
    else
        this->m_parent.m_name = NULL;
    if (is_a_legend == 0)
        this->m_parent.m_power = 0;
    else
        this->m_parent.m_power = 42;
    this->m_is_a_legend = is_a_legend;
    printf("----\n");
    printf("Building %s\n", "Cthulhu");
    printf("Building %s\n", name);
}

koala_t *new_koala(char *name, char is_a_legend)
{
    koala_t *new = malloc(sizeof(*new));

    if (new == NULL)
        return (NULL);
    koala_initializer(new, name, is_a_legend);
    return (new);
}

void eat(koala_t *this)
{
    if (this) {
        this->m_parent.m_power += 42;
        printf("%s eats\n", this->m_parent.m_name);
    }
}
