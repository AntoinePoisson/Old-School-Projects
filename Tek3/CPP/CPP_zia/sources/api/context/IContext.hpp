/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** IContext
*/

#ifndef ICONTEXT_HPP_
#define ICONTEXT_HPP_

#include <string>
#include <any>

/**
* @namespace Zia
* Zia API
*/
namespace Zia
{
    /**
    * @interface IContext
    * Abstract context values. They are stored by std::string keys, value is a std::any.
    */
    class IContext
    {
        public:
            virtual ~IContext(void) = default;

            /**
            * @fn get
            * Get context value by key. Returns non-null if present, null otherwise
            * @param const std::string &key: key of context parameter to retrieve
            * @return const std::any*: the optional context value
            */
            virtual const std::any* get(const std::string &key) const = 0;

            /**
            * @fn set
            * Set context value.
            * @param const std::string &key: key of context parameter to set
            * @param const const std::any &value: value of context parameter to set
            */
            virtual void set(const std::string &key, const std::any &value) = 0;
    };
} // namespace Zia

#endif /* !ICONTEXT_HPP_ */
