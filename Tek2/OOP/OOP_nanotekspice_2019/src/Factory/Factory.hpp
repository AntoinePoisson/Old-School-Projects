/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include <memory>
#include "../Components/IComponent.hpp"
#include "../Components/Input.hpp"
#include "../Components/Clock.hpp"
#include "../Components/True.hpp"
#include "../Components/False.hpp"
#include "../Components/Output.hpp"
#include "../Components/C_4001.hpp"
#include "../Components/C_4008.hpp"
#include "../Components/C_4011.hpp"
#include "../Components/C_4013.hpp"
#include "../Components/C_4017.hpp"
#include "../Components/C_4030.hpp"
#include "../Components/C_4040.hpp"
#include "../Components/C_4069.hpp"
#include "../Components/C_4071.hpp"
#include "../Components/C_4081.hpp"
#include "../Components/C_4094.hpp"
#include "../Components/C_4514.hpp"
#include "../Components/C_4801.hpp"
#include "../Components/C_2716.hpp"

class Factory
{
    public:
        Factory() = default;
        ~Factory() = default;
        
        static std::unique_ptr<nts::IComponent> createComponent(const std::string &type, const std::string &value);

    protected:
    private:
};

#endif /* !FACTORY_HPP_ */
