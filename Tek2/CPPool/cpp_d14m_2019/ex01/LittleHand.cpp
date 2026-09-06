/*
** EPITECH PROJECT, 2020
** LittleHand
** File description:
** LittleHand
*/

#include "LittleHand.hpp"
#include "Banana.hpp"
#include "Lemon.hpp"
#include "Lime.hpp"


LittleHand::LittleHand()
{}

void LittleHand::sortFruitBox(FruitBox & unsorted, FruitBox & lemons, FruitBox & bananas, FruitBox &limes)
{
    int size = unsorted.nbFruits();
    FruitBox *save = new FruitBox(unsorted.nbFruits());

    for (int i = 0; i < size; i++) {
        save->putFruit(unsorted.pickFruit());
    }
    while (save->nbFruits()) {
        Fruit *current_fruit = save->pickFruit();
        if (dynamic_cast<Lime*> (current_fruit) != nullptr && limes.putFruit(current_fruit)) {
        } else if (dynamic_cast<Banana*> (current_fruit) != nullptr && bananas.putFruit(current_fruit)) {
        } else if (dynamic_cast<Lemon*> (current_fruit) != nullptr && lemons.putFruit(current_fruit)) {
        } else {
            unsorted.putFruit(current_fruit);
        }
    }
}