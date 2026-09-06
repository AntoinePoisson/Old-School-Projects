/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** Logger
*/

#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <fstream>
#include <boost/thread/mutex.hpp>

#include "ILogger.hpp"

/**
* @namespace Zia
* Zia
*/
namespace Zia
{
    /**
     * @class Logger
     * Handle Log (It's logger class of program NOT MODULE A Logger !!)
     */
    class Logger : public ILogger
    {
        private:
            boost::mutex _mutex;
            std::ofstream _file;
        public:
            /**
             * @brief Construct a new Logger object
             * if nameFile not exist (create it)
             * @param nameFile path to log file
             */
            Logger(const std::string &nameFile);
            ~Logger();

            /**
             * @fn log
             * Write string in log file
             * @param str string message
             */
            void log(const std::string &str) final;
    };
} // namespace Zia

#endif /* !LOGGER_HPP_ */
