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

	size_t getFingerprint() const;
	size_t getExp() const;

	void setFingerprint(size_t fingerPrint);
	void setExp(size_t exp);

    DroidMemory &operator<<(const DroidMemory &droidMemory);
    DroidMemory &operator>>(DroidMemory &droidMemory);
    DroidMemory &operator+=(const DroidMemory &droidMemory);
    DroidMemory &operator+=(size_t exp);
	DroidMemory &operator+(const DroidMemory &droidMemory);
	DroidMemory &operator+(size_t exp);

	DroidMemory& operator=(const DroidMemory &droidMemory);
	bool operator==(const DroidMemory &droidMemory) const;
	bool operator!=(const DroidMemory &droidMemory) const;
	bool operator<=(const DroidMemory &droidMemory) const;
	bool operator>=(const DroidMemory &droidMemory) const;
	bool operator>(const DroidMemory &droidMemory) const;
	bool operator<(const DroidMemory &droidMemory) const;
	bool operator<=(size_t exp) const;
	bool operator>=(size_t exp) const;
	bool operator>(size_t exp) const;
	bool operator<(size_t exp) const;

    private:
    	size_t _Fingerprint;
	    size_t _Exp;
};

std::ostream &operator<<(std::ostream &os, const DroidMemory &droidMemory);

#endif /* !DroidMemory_H */
