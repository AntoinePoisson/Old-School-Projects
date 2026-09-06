/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** ErrorSql
*/

#ifndef ERRORSQL_HPP_
#define ERRORSQL_HPP_

#include "AException.hpp"
#include "Babel.hpp"

namespace babel {

    class ErrorSql : public AException {
        public:
            ErrorSql(std::string component = "[SQL]", std::string message = "Error sql", int returnValue = Ok);
            virtual ~ErrorSql() = default;
    };

}

#endif /* !ERRORSQL_HPP_ */
