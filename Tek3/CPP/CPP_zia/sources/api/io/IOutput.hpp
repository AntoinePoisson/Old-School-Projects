/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** IOutput
*/

#ifndef IOUTPUT_HPP_
#define IOUTPUT_HPP_

#include <cstddef>

/**
* @namespace Zia
* Zia API
*/
namespace Zia
{
    /**
    * @interface IOutput
    * Non-blocking output stream.
    */
    class IOutput
    {
        public:
            virtual ~IOutput(void) = default;

            /**
            * @fn write
            * Write bytes on the stream.
            * @param size_t buf_size: available bytes count at buf
            * @param const char *buf: buffer with bytes that will be written on the stream
            * @return size_t: the amount of bytes actually written on the stream
            * @note This function can very well return 0 if no bytes are available on stream for writing,
            * even if buf_size is superior to 0. It is reasonnable to keep trying to write those bytes
            * until a strictly positive response is returned, as writing availability should come in at any time
            * in the near future. Also, assume that this availability might never actually come so you should
            * also take that into consideration.
            */
            virtual size_t write(size_t buf_size, const char *buf) = 0;
    };
} // namespace Zia

#endif /* !IOUTPUT_HPP_ */
