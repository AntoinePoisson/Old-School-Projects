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

class Errors : public std::exception {
    public:
        Errors(std::string const &message,
                std::string const &component = "Unknown");
        virtual ~Errors() = default;

        const char *what() const throw();
        std::string const &getComponent() const;

    private:
        std::string _message;
        std::string _component;
};

// class Exemple : public Errors {
//     public:
//         Exemple(std::string const &message,
//                 std::string const &component = "Unknown");
//         virtual ~Exemple() = default;
// };

#endif /* !Error_hpp */
