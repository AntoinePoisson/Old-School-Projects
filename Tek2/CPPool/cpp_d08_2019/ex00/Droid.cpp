/*
** EPITECH PROJECT, 2020
** Droid
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::Droid(std::string serial)
{
    this->Id = serial;
    this->Energy = 50;
    this->Status = new std::string("Standing by");
    // "Droid "serial" Activated\n";
    std::cout << "Droid '" << serial << "' Activated\n";
}

Droid::Droid(const Droid &old_obj)
{
    this->Id = old_obj.Id;
    this->Energy = old_obj.Energy;
	if (old_obj.Status)
		this->Status = new std::string(*(old_obj.Status));
	else
		this->Status = new std::string("Standing by");
    // "Droid '"serial"' Activated, Memory Dumped\n";
    std::cout << "Droid '" << old_obj.Id << "' Activated, Memory Dumped\n";
}



Droid::~Droid()
{
    std::cout <<  "Droid '" << this->Id << "' Destroyed\n";
}



std::string Droid::getId() const
{
    return (this->Id);
}

size_t Droid::getEnergy() const
{
    return (this->Energy);
}

size_t Droid::getAttack() const
{
    return (this->Attack);
}

size_t Droid::getToughness() const
{
    return (this->Toughness);
}

std::string *Droid::getStatus() const
{
    return (this->Status);
}

void Droid::setId(std::string id)
{
    this->Id = id;
}

void Droid::setEnergy(size_t energy)
{
    if (energy >= 100) {
        this->Energy = 100;
        return;
    }
    this->Energy = energy;
}

void Droid::setStatus(std::string *status)
{
    this->Status = status;
}


Droid& Droid::operator=(const Droid& droid)
{
    this->Id = droid.Id;
    this->Energy = droid.Energy;
	this->Status = new std::string(*(droid.Status));
	return *this;
}

bool Droid::operator==(const Droid& droid) const
{
    if (this->Id == droid.Id && this->Energy == droid.Energy
        && this->Status->compare((*droid.Status)) == 0 && this->Attack == droid.Attack
        && this->Toughness == droid.Toughness)
        return (true);
    return (false);
}

bool Droid::operator!=(const Droid& droid) const
{
    if (!Droid::operator==(droid))
        return (true);
    return (false);
}

Droid& Droid::operator<<(size_t &size)
{
    if (this->Energy >= 100) {
        this->Energy = 100;
        return *this;
    }
    if (!(100 <= this->Energy + size)) {
        Energy = Energy + size;
        size = 0;
    } else {
        size = size - (100 - this->Energy);
        this->Energy = 100;
    }
    return *this;
}
// std::ostream& operator<<(std::ostream& os, Droid const &droid)
// {
//     return (os << "Droid '" << *(droid.getId()) << "', "Status", "Energy"\n");
// }

std::ostream & operator<<(std::ostream & os, Droid const & droid) {
	return os << "Droid '" << droid.getId() << "', " << (*droid.getStatus()) << ", " << droid.getEnergy();
}
