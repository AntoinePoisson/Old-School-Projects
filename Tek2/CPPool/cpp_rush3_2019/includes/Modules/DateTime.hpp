/*
** EPITECH PROJECT, 2020
** DateTime
** File description:
** DateTime
*/

#ifndef DATETIME_HPP
#define DATETIME_HPP

#include <iostream>
#include "Module.hpp"

class DateTime : public Module {
	public:
		DateTime(std::string const &name);
		~DateTime() = default;

        std::vector<std::string> getTimeDate() const;
        void refreshData();

	protected:
	private:
};

#endif /* !DateTime_HPP */
