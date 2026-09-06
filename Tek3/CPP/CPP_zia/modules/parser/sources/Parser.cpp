/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** Parser
*/

#include "Parser.hpp"
#include "Instance.hpp"
#include "../../exception/AException.hpp"

Zia::Parser::Parser()
{
}

std::unique_ptr<Zia::Module::IParser::IInstance> Zia::Parser::create(IInput &input, ILogger &log, IRequest::IEmitter &requestEmitter)
{
    return (std::make_unique<Zia::Instance>(input, log, requestEmitter));
}

Zia::Parser::~Parser()
{
}
