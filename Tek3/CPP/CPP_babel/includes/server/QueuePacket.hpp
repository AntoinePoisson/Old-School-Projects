/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** QueuePacket
*/

#ifndef QUEUEPACKET_HPP_
#define QUEUEPACKET_HPP_

#include <queue>
#include "Package.hpp"

namespace babel {

    class QueuePacket {
        public:
            virtual ~QueuePacket() = default;

            void push(Package &pack);
            Package pop(void);
            Package front(void);
            size_t size(void);

            friend std::ostream &operator<<(std::ostream &os, QueuePacket &element)
            { return os << element.front().get(); }
        private:
            std::queue<babel::Package> _queue;
    };

}

#endif /* !QUEUEPACKET_HPP_ */
