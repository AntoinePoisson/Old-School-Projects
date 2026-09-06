/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** FataleErrorSql
*/

#ifndef FATALEERRORSQL_HPP_
#define FATALEERRORSQL_HPP_

#include "AException.hpp"
#include "Babel.hpp"

namespace babel {

    class FataleErrorSql : public AException {
        public:
            FataleErrorSql(std::string component = "[SQL-Fatale]", std::string message = "Error DataBase", int returnValue = Err);
            virtual ~FataleErrorSql() = default;
    };

}

#endif /* !FATALEERRORSQL_HPP_ */
