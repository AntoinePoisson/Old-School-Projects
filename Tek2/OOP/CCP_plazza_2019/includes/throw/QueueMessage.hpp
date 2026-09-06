/*
** EPITECH PROJECT, 2020
** QueueMessage.hpp
** File description:
** QueueMessage
*/

#ifndef ERROR_QUEUE_MESSAGE_HPP_
#define ERROR_QUEUE_MESSAGE_HPP_

#include <string>
#include <exception>

namespace Plazza {

    namespace Throw {

        class QueueMessage : public std::exception {
            public:
                QueueMessage(std::string const &message = "No message");
                virtual ~QueueMessage() = default;

                const char *what() const throw();

            private:
                std::string message;
        };

    }

}

#endif /* !QueueMessage_hpp */
