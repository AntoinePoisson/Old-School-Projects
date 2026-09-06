/*
** EPITECH PROJECT, 2020
** Phaser
** File description:
** Phaser
*/

#ifndef PHASER_H
#define PHASER_H

#include <iostream>

class Phaser
{
    public:
        enum AmmoType
        {
            REGULAR,
            PLASMA,
            ROCKET
        };
        Phaser(int maxAmmo = 20, AmmoType type = REGULAR);
        ~Phaser();
        void fire();
        void ejectClip();
        void changeType(AmmoType newType);
        void reload();
        void addAmmo(AmmoType type);
        int getCurrentAmmos();

    private:
        static const int Empty = 0;
        int _maxAmmo;
        int _ammo[3];
        AmmoType _type;
};

#endif /* !PHASER_H */
