/*
** EPITECH PROJECT, 2020
** DroidMemory
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory()
{
    this->_Exp = 0;
    this->_Fingerprint = random();
}

DroidMemory::~DroidMemory()
{
}

size_t DroidMemory::getFingerprint() const
{
    return (this->_Fingerprint);
}

size_t DroidMemory::getExp() const
{
    return (this->_Exp);
}

void DroidMemory::setFingerprint(size_t fingerPrint)
{
    this->_Fingerprint = fingerPrint;
}
void DroidMemory::setExp(size_t exp)
{
    this->_Exp = exp;
}

DroidMemory &DroidMemory::operator<<(const DroidMemory & droidMemory)
{
    this->_Exp = this->_Exp + droidMemory.getExp();
    this->_Fingerprint = this->_Fingerprint ^ droidMemory.getFingerprint();
    return (*this);
}

DroidMemory &DroidMemory::operator>>(DroidMemory & droidMemory)
{
    droidMemory._Exp = this->_Exp + droidMemory.getExp();
    droidMemory._Fingerprint = droidMemory.getFingerprint() ^ this->_Fingerprint;
    return (*this);
}

DroidMemory &DroidMemory::operator+=(const DroidMemory & droidMemory)
{
    return (DroidMemory::operator<<(droidMemory));
}

DroidMemory &DroidMemory::operator+=(size_t exp)
{
    this->_Exp = this->_Exp + exp;
    this->_Fingerprint = this->_Fingerprint ^ exp;
    return (*this);
}


DroidMemory &DroidMemory::operator+(const DroidMemory &droidMemory)
{
	DroidMemory *element = new DroidMemory();
    element->_Exp = this->_Exp + droidMemory.getExp();
    element->_Fingerprint = this->_Fingerprint ^ droidMemory.getFingerprint();
    return (*element);
}

DroidMemory &DroidMemory::operator+(size_t exp)
{
	DroidMemory *element = new DroidMemory();
    element->_Exp = this->_Exp + exp;
    element->_Fingerprint = this->_Fingerprint ^ exp;
    return (*element);
}

std::ostream &operator<<(std::ostream &os, const DroidMemory &droidMemory)
{
    return (os << "DroidMemory '" << droidMemory.getFingerprint() << "', " << droidMemory.getExp());
}



DroidMemory &DroidMemory::operator=(const DroidMemory &droidMemory)
{
    this->_Exp = droidMemory._Exp;
    this->_Fingerprint = droidMemory._Fingerprint;
	return *this;
}

bool DroidMemory::operator==(const DroidMemory &droidMemory) const
{
    if (this->_Exp == droidMemory._Exp && this->_Fingerprint == droidMemory._Fingerprint)
        return (true);
    return (false);
}

bool DroidMemory::operator!=(const DroidMemory &droidMemory) const
{
    return (!DroidMemory::operator==(droidMemory));
}

bool DroidMemory::operator<=(const DroidMemory &droidMemory) const
{
    if (this->_Exp <= droidMemory._Exp)
        return (true);
    return (false);
}

bool DroidMemory::operator>=(const DroidMemory &droidMemory) const
{
    if (this->_Exp >= droidMemory._Exp)
        return (true);
    return (false);
}

bool DroidMemory::operator>(const DroidMemory &droidMemory) const
{
    if (this->_Exp > droidMemory._Exp)
        return (true);
    return (false);
}

bool DroidMemory::operator<(const DroidMemory &droidMemory) const
{
    if (this->_Exp < droidMemory._Exp)
        return (true);
    return (false);
}

bool DroidMemory::operator<=(size_t exp) const
{
    if (this->_Exp <= exp)
        return (true);
    return (false);
}

bool DroidMemory::operator>=(size_t exp) const
{
    if (this->_Exp >= exp)
        return (true);
    return (false);
}

bool DroidMemory::operator>(size_t exp) const
{
    if (this->_Exp > exp)
        return (true);
    return (false);
}

bool DroidMemory::operator<(size_t exp) const
{
    if (this->_Exp < exp)
        return (true);
    return (false);
}
