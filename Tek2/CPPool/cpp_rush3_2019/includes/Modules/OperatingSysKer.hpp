/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** OperatingSysKer
*/

#ifndef OPERATINGSYSKER_HPP_
#define OPERATINGSYSKER_HPP_

#include <string>
#include <vector>
#include "Modules/Module.hpp"

class OperatingSysKer : public Module
{
	public:
		OperatingSysKer(std::string const &name);
		virtual ~OperatingSysKer() = default;

        void refreshData();
};

#endif /* !OPERATINGSYSKER_HPP_ */
