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
    this->BattleData = new DroidMemory();
    // "Droid "serial" Activated\n";
    std::cout << "Droid '" << serial << "' Activated\n";
}

Droid::Droid(const Droid &old_obj)
{
    this->Id = old_obj.Id;
    this->Energy = 50;
    this->BattleData = old_obj.BattleData;
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

DroidMemory *Droid::getBattleData() const
{
    return (this->BattleData);
}

void Droid::setId(std::string id)
{
    this->Id = id;
}

void Droid::setEnergy(size_t energy)
{
    this->Energy = energy;
}

void Droid::setStatus(std::string *status)
{
    this->Status = status;
}

void Droid::setBattleData(DroidMemory *status)
{
    this->BattleData = status;
}


Droid& Droid::operator=(const Droid& droid)
{
    this->Id = droid.Id;
    this->Energy = 50;
	this->Status = new std::string(*(droid.Status));
	this->BattleData = droid.BattleData;
	return *this;
}

bool Droid::operator==(const Droid& droid) const
{
    if (this->Status->compare((*droid.Status)) == 0)
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
  size_t offset = 0;

    if (this->Energy >= 100) {
        this->Energy = 100;
        return *this;
    }
    offset = (100 - this->Energy < size) ? 100 - this->Energy : size;
    this->Energy += offset;
    size -= offset;
    return *this;
}


bool Droid::operator()(std::string const * task, size_t exp)
{
    std::string *status = nullptr;

	if (this->Energy <= 10) {
		this->Energy = 0;
		this->Status = new std::string("Battery Low");
		return (false);
	}
    if (!this->BattleData) {
        return (false);
    }
	status = new std::string(*task);
	if (*BattleData >= exp) {
	    this->Energy -= 10;
        status->append(" - Completed!");
		this->Status = status;
		BattleData->setExp((BattleData->getExp() + (exp / 2)));
		return (true);
	}
	this->Energy -= 10;
    status->append(" - Failed!");
	this->Status = status;
	BattleData->setExp((BattleData->getExp() + (exp)));
	return (false);
}

// std::ostream& operator<<(std::ostream& os, Droid const &droid)
// {
//     return (os << "Droid '" << *(droid.getId()) << "', "Status", "Energy"\n");
// }

std::ostream & operator<<(std::ostream & os, Droid const & droid) {
	return os << "Droid '" << droid.getId() << "', " << (*droid.getStatus()) << ", " << droid.getEnergy();
}
