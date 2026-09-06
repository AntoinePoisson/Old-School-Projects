/*
** EPITECH PROJECT, 2020
** Fruit
** File description:
** Fruit
*/

#ifndef FruitNode_hpp
#define FruitNode_hpp

#include <iostream>
#include "Fruit.hpp"

typedef struct FruitNode_s {
	Fruit *data;
	FruitNode_s *next = nullptr;
} FruitNode_t;

#endif /* !FruitNode_hpp */
