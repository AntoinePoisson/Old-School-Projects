/*
** EPITECH PROJECT, 2020
** Fruit
** File description:
** Fruit
*/

#ifndef FruitBox_hpp
#define FruitBox_hpp

#include <iostream>
#include "FruitNode.hpp"
#include "Fruit.hpp"

class FruitBox {
	public:
		explicit FruitBox(int size);
		~FruitBox();

		int nbFruits() const;
		bool putFruit(Fruit *f);
		Fruit *pickFruit();
		FruitNode_t *head() const;

	protected:
	private:
		FruitNode_t *_next;
		FruitNode_t *_head;
		int _size_max;
		int _size_currently;
};

#endif /* !FruitBox_hpp */
