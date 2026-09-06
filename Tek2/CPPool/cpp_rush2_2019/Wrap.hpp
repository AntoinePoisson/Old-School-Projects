/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Wrap
*/

#ifndef WRAP_HPP_
#define WRAP_HPP_

#include "Object.hpp"

class Wrap : public Object
{
	public:
		Wrap();
        Wrap(std::string str);
		~Wrap();
        virtual void wrapMeThat(Object *obj);
        void isTaken() const;
        void openMe();
        Object *getObject();

	protected:
        bool open;
        Object *object;
	private:
};

#endif /* !WRAP_HPP_ */
