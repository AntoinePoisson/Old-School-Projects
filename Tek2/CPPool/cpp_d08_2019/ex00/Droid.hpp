/*
** EPITECH PROJECT, 2020
** Droid
** File description:
** Droid
*/

#ifndef Droid_H
#define Droid_H

// #include <fstream>
// #include <string.h>
#include <iostream>


class Droid {
    public:
        Droid(std::string serial = "");
        Droid(const Droid &);
        ~Droid();

        std::string getId() const;
        size_t getEnergy() const;
        size_t getAttack() const;
        size_t getToughness() const;
        std::string *getStatus() const;

        void setId(std::string);
        void setEnergy(size_t);
        void setStatus(std::string *);

        Droid& operator=(const Droid&);
        bool operator==(const Droid&) const;
        bool operator!=(const Droid&) const;
        Droid& operator<<(size_t &);
    
    private:
        std::string Id;
        size_t Energy;
        const size_t Attack = 25;
        const size_t Toughness = 15;
        std::string *Status;
};

std::ostream &operator<<(std::ostream &, Droid const &);

#endif /* !Droid */
