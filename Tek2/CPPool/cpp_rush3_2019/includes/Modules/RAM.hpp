/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** RAM
*/

#ifndef RAM_HPP_
#define RAM_HPP_

#include "Modules/Module.hpp"

class RAM : public Module
{
	public:
		RAM(std::string const &name);
		~RAM() = default;

        void refreshData();
};

#endif /* !RAM_HPP_ */
