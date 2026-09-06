/*
** EPITECH PROJECT, 2020
** MyUnitTests
** File description:
** MyUnitTests
*/

#include "Object.hpp"
#include "Teddy.hpp"
#include "LittlePony.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"


Object **MyUnitTests()
{
    Object **result = new Object*[2];

    result[0] = new LittlePony("happy pony");
    result[1] = new Teddy("cuddles");

    return (result);
}

Object *MyUnitTests(Object **obj)
{
    int size = 0;

    for (;obj[size];size++);
    if (size < 3)
        return (nullptr);

    dynamic_cast<Box *>(obj[1])->openMe();
    dynamic_cast<Box *>(obj[1])->wrapMeThat(obj[0]);
    dynamic_cast<GiftPaper *>(obj[2])->wrapMeThat(obj[1]);
    return (obj[2]);
}