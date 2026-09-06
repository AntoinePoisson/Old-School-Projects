/*
** EPITECH PROJECT, 2020
** LittleHand
** File description:
** LittleHand
*/

#ifndef LittleHand_hpp
#define LittleHand_hpp

#include "FruitBox.hpp"

class LittleHand {
	public:
		LittleHand();
		~LittleHand() = default;

        static void sortFruitBox(FruitBox & unsorted, FruitBox & lemons, FruitBox & bananas, FruitBox &limes);

	protected:
	private:
};

#endif /* !LittleHand_hpp */
