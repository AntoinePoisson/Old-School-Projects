/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** CPU
*/

#ifndef CPU_HPP_
#define CPU_HPP_

#include <string>
#include <vector>
#include "Modules/Module.hpp"

class CPU : public Module
{
	public:
		CPU(std::string const &name);
		virtual ~CPU() = default;

        void refreshData();
	protected:
	private:
		void getPercent(std::stringstream &ss);
};

#endif /* !CPU_HPP_ */
