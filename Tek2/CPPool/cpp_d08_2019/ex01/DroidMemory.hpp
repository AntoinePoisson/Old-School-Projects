/*
** EPITECH PROJECT, 2020
** DroidMemory
** File description:
** DroidMemory
*/

#ifndef DroidMemory_H
#define DroidMemory_H

#include <iostream>

class DroidMemory {
    public:
        DroidMemory();
        ~DroidMemory();

	size_t getFingerPrint() const;
	size_t getExp() const;

	void setFingerPrint(size_t fingerPrint);
	void setExp(size_t exp);

    DroidMemory &operator<<(const DroidMemory &droidMemory);
    DroidMemory &operator>>(DroidMemory &droidMemory);
    DroidMemory &operator+=(const DroidMemory &droidMemory);
    DroidMemory &operator+=(size_t exp);
	DroidMemory &operator+(const DroidMemory &droidMemory);
	DroidMemory &operator+(size_t exp);

    private:
    	size_t _Fingerprint;
	    size_t _Exp;
};

std::ostream &operator<<(std::ostream &os, const DroidMemory &droidMemory);

#endif /* !DroidMemory_H */
