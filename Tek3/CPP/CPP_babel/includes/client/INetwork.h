/*
** EPITECH PROJECT, 2020
** B-CPP-500-PAR-5-1-babel-antoine.poisson
** File description:
** INetwork
*/

#ifndef INETWORK_H_
#define INETWORK_H_

#include "DataClient.h"

namespace babel
{
    class INetwork
    {
        public:
        virtual ~INetwork() = default;
            virtual void logout() = 0;
            virtual void login(const IData &a) = 0;
            virtual void registered(const IData &a) = 0;
            virtual void listRelation() = 0;
            virtual void askingAddRelation(const IData &a) = 0;
            virtual void answerCalledSomeone(const IData &a) = 0;
            virtual void askingCallSomeone(const IData &a) = 0;
    };
}



#endif /* !INETWORK_H_ */
