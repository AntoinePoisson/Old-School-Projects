/*
** EPITECH PROJECT, 2020
** ex06.hpp
** File description:
** ex06.hpp
*/

#ifndef ex06_hpp
#define ex06_hpp

#include <iostream>
#include <tuple>
#include <string>
#include <sstream>

// template<typename int, typename std::string>
template<typename T, typename U = T>
class Tuple
{
    public:
        T a;
        U b;

        std::string toString() {
            std::string result = "[TUPLE [";
            result += display(a);
            result += "] [";
            result += display(b);
            result += "]]";
            return (result);
        }

    private:
        std::string display(int value) {
            return (std::string("int:") + std::to_string(value));
        }
        std::string display(float a) {
            std::stringstream oss;
            oss << a;
            std::string result;
            oss >> result;
            return (std::string("float:") + result + std::string("f"));
        }
        std::string display(std::string value) {
            return (std::string("string:\"") + value + std::string("\""));
        }
        template<typename K>
        std::string display(K) {
            return (std::string("???"));
        }
};

#endif /* !ex06_hpp */
