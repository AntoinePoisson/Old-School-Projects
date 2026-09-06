/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** Parser
*/

#ifndef PARSERMODULEHANDE_HPP_
#define PARSERMODULEHANDE_HPP_

#include "IParser.hpp"

namespace Zia
{
    class Parser : public Zia::Module::IParser
    {
        public:
            Parser();
            ~Parser();
            std::unique_ptr<IInstance> create(IInput &input, ILogger &log, IRequest::IEmitter &requestEmitter);

        protected:
        private:
    };
}

#endif /* !PARSERMODULEHANDE_HPP_ */
