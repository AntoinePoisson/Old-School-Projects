/*
** EPITECH PROJECT, 2020
** B-CPP-500-PAR-5-1-babel-antoine.poisson
** File description:
** IData
*/

#ifndef IDATA_H_
#define IDATA_H_

#include <iostream>

namespace babel
{
    class IData
    {
        public:
        virtual ~IData() = default;
        virtual void setFirstParam(const std::string &name) = 0;
        virtual void setSecondParam(const std::string &password) = 0;
        virtual const std::string& getFirstParam() const = 0;
        virtual const std::string& getSecondParam() const = 0;
    };

}

#endif /* !IDATA_H_ */
