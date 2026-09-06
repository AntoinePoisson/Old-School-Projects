/*
** EPITECH PROJECT, 2020
** Error
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <string>
#include <exception>

namespace Plazza {

    namespace Throw {

        class Error : public std::exception {
            public:
                Error(std::string const &component = "Unknown", std::string const &message = "", int returnValue = 84);
                virtual ~Error() = default;

                const char *what() const throw();
                std::string const &getComponent() const;
                int getValue() const;

            private:
                std::string message;
                std::string component;
                int returnValue;
                bool messageVoid;
        };

    }

}

#endif /* !Error_hpp */
