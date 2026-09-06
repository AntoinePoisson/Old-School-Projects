/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** IInputOutput
*/

#ifndef IINPUTOUTPUT_HPP_
#define IINPUTOUTPUT_HPP_

#include "IInput.hpp"
#include "IOutput.hpp"

/**
* @namespace Zia
* Zia API
*/
namespace Zia
{
    /**
    * @interface IInputOutput
    * Non-blocking input/output stream.
    */
    class IInputOutput : public IInput, public IOutput
    {
        public:
            virtual ~IInputOutput(void) override = default;
    };
} // namespace Zia

#endif /* !IINPUTOUTPUT_HPP_ */
