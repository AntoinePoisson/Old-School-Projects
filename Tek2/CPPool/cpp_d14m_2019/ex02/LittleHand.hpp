/*
** EPITECH PROJECT, 2020
** LittleHand
** File description:
** LittleHand
*/

#ifndef LittleHand_hpp
#define LittleHand_hpp

#include "FruitBox.hpp"
#include "Coconut.hpp"

class LittleHand {
	public:
		LittleHand();
		~LittleHand() = default;

        static void sortFruitBox(FruitBox & unsorted, FruitBox & lemons, FruitBox & bananas, FruitBox &limes);
        static FruitBox * const * organizeCoconut(Coconut const * const * coconuts);

	protected:
	private:
};

#endif /* !LittleHand_hpp */
