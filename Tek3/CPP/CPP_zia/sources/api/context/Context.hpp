/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** Context
*/

#ifndef CONTEXT_HPP_
#define CONTEXT_HPP_

#include <map>

#include "IContext.hpp"

/**
* @namespace Zia
* Zia
*/
namespace Zia
{
    /**
     * @class Context
     * Allow to stockage data between module
     */
    class Context : public IContext
    {
        private:
            std::map<std::string, std::any> _data;
        public:
            Context() = default;
            ~Context();

            const std::any *get(const std::string &key) const;
            void set(const std::string &key, const std::any &value);
    };
} // namespace Zia

#endif /* !CONTEXT_HPP_ */
