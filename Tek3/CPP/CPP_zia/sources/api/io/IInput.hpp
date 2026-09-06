/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** IInput
*/

#ifndef IINPUT_HPP_
#define IINPUT_HPP_

#include <cstddef>

/**
* @namespace Zia
* Zia API
*/
namespace Zia
{
    /**
    * @interface IInput
    * Non-blocking input stream.
    */
    class IInput
    {
        public:
            virtual ~IInput(void) = default;

            /**
            * @fn read
            * Read available bytes on the stream
            * @param size_t buf_size: available bytes count at buf
            * @param char *buf: buffer to write stream available bytes to
            * @return size_t: the amount of bytes polled from the stream and written into buf
            */
            virtual size_t read(size_t buf_size, char *buf) = 0;
    };
} // namespace Zia


#endif /* !IINPUT_HPP_ */
