/*
** EPITECH PROJECT, 2021
** Zia
** File description:
** HandleResponse
*/

#ifndef HANDLERESPONSE_HPP_
#define HANDLERESPONSE_HPP_

#include <map>
#include "../api/context/IResponse.hpp"
#include "../api/io/IConnection.hpp"

/**
* @namespace Zia
* Zia
*/
namespace Zia
{
    static const std::map<size_t, std::string> listCodeStatus = {
            {100, "Continue"},
            {101, "Switching Protocols"},
            {200, "OK"},
            {201, "Created"},
            {202, "Accepted"},
            {203, "Non-authoritative Information"},
            {204, "No Content"},
            {205, "Reset Content"},
            {206, "Partial Content"},
            {300, "Multiple Choices"},
            {301, "Moved Permanently"},
            {302, "Found"},
            {303, "See Other"},
            {304, "Not Modified"},
            {305, "Use Proxy"},
            {306, "Unused"},
            {307, "Temporary Redirect"},
            {400, "Bad Request"},
            {401, "Unauthorized"},
            {402, "Payment Required"},
            {403, "Forbidden"},
            {404, "Not Found"},
            {405, "Method Not Allowed"},
            {406, "Not Acceptable"},
            {407, "Proxy Authentication Required"},
            {408, "Request Timeout"},
            {409, "Conflict"},
            {410, "Gone"},
            {411, "Length Required"},
            {412, "Precondition Failed"},
            {413, "Request Entity Too Large"},
            {414, "Request-url Too Long"},
            {415, "Unsupported Media Type"},
            {416, "Requested Range Not Satisfiable"},
            {417, "Expectation Failed"},
            {500, "Internal Server Error"},
            {501, "Not Implemented"},
            {502, "Bad Gateway"},
            {503, "Service Unavailable"},
            {504, "Gateway Timeout"},
            {505, "HTTP Version Not Supported"}
        };

    /**
     * @class HandleResponse
     * Manage Response to client
     */
    class HandleResponse
    {
        private:
            // static const std::string addHeader(const Zia::IResponse &res, const std::string &key);
        public:
            ~HandleResponse() = default;

            /**
             * @brief convertResponse
             * convertir Class Iresponse tp vector<char>
             * @param res Iresponse
             * @return const std::vector<char> response
             */
            static const std::vector<char> convertResponse(const Zia::IResponse &res);
            /**
             * @brief genRespInterErrServer
             * Generate Reponse of Internal Server Error
             * @return const std::vector<char> response
             */
            static const std::vector<char> genRespInterErrServer(void);
            /**
             * @brief genRespErr
             * Generate Rponse starting from nbr erreur code
             * @param code nbr
             * @return const std::vector<char> response
             */
            static const std::vector<char> genRespErr(size_t code);
            /**
             * @brief sendReponseToClient
             * Send a Reponse to Client
             * @param res reponse message
             * @param client Iconnection
             */
            static void sendReponseToClient(const std::vector<char> &res, Zia::IConnection &client);
            private:
                /**
                 * @brief add_some_to_vector
                 * Add the content of src at the end of dest vector
                 * @param dest destination vector
                 * @param src what to append in the dest vector
                 */
                template<typename T>
                static void add_some_to_vector(std::vector<char> &dest, const T &src);
    };
} // namespace Zia

#endif /* !HANDLERESPONSE_HPP_ */
