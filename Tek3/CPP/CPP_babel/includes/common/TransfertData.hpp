/*
** EPITECH PROJECT, 2020
** B-CPP-500-PAR-5-1-babel-antoine.poisson
** File description:
** TransfertData
*/

#ifndef TRANSFERTDATA_HPP_
#define TRANSFERTDATA_HPP_

#include <iostream>
#include <vector>
#include <memory>
#include <cstring>
#include <boost/algorithm/string.hpp>
#include <boost/serialization/serialization.hpp>

#define SIZE_MAX_RELATION 512
#define SIZE_DEFAULT_NAME 256
#define SIZE_DEFAULT_PASS 256
#define SIZE_DEFAULT_IP 56

namespace babel {

    typedef struct relation_s {
        int id;
        char username[SIZE_DEFAULT_NAME];
        bool online;
    } relation_t;

    typedef struct transfertData_s {
        int opcode;
        relation_t relation[SIZE_MAX_RELATION];
        char username[SIZE_DEFAULT_NAME];
        char password[SIZE_DEFAULT_PASS];
        char ip[SIZE_DEFAULT_IP];
        int id;
        int portUdp;
        bool rep;
    } transfertData_t;

    class TransfertData {
        public:
            TransfertData();
            virtual ~TransfertData() = default;

            std::vector<std::string> extractData(std::string message);
            std::vector<std::string> extractDataFromStruct(transfertData_t *transfert);
            transfertData_t transcriptData(int opcode, std::vector<std::string> cmd);
        private:
            transfertData_t cmd100(std::vector<std::string> const & cmd);
            transfertData_t cmd110(std::vector<std::string> const & cmd);
            transfertData_t cmd111(std::vector<std::string> const & cmd);
            transfertData_t cmd112(std::vector<std::string> const & cmd);
            transfertData_t cmd120(std::vector<std::string> const & cmd);
            transfertData_t cmd130(std::vector<std::string> const & cmd);
            transfertData_t cmd131(std::vector<std::string> const & cmd);
            transfertData_t cmd132(std::vector<std::string> const & cmd);
            transfertData_t cmd210(std::vector<std::string> const & cmd);
            transfertData_t cmd211(std::vector<std::string> const & cmd);
            transfertData_t cmd212(std::vector<std::string> const & cmd);
            transfertData_t cmd220(std::vector<std::string> const & cmd);
            transfertData_t cmd221(std::vector<std::string> const & cmd);
            transfertData_t cmd222(std::vector<std::string> const & cmd);
            transfertData_t cmd223(std::vector<std::string> const & cmd);
            transfertData_t cmd230(std::vector<std::string> const & cmd);
            transfertData_t cmd231(std::vector<std::string> const & cmd);
            transfertData_t cmd232(std::vector<std::string> const & cmd);
            std::vector<std::string> cmdVoid(transfertData_t *cmd, std::string const opcode);
            std::vector<std::string> cmdLog(transfertData_t *cmd, std::string const opcode);
            std::vector<std::string> cmdId(transfertData_t *cmd, std::string const opcode);
            std::vector<std::string> cmdAddRelation(transfertData_t *cmd, std::string const opcode);
            std::vector<std::string> cmdAskCall(transfertData_t *cmd, std::string const opcode);
            std::vector<std::string> cmdBool(transfertData_t *cmd, std::string const opcode);
            std::vector<std::string> cmdConfRelation(transfertData_t *cmd, std::string const opcode);
            std::vector<std::string> cmdConfCall(transfertData_t *cmd, std::string const opcode);
            std::vector<std::string> cmdListRelation(transfertData_t *cmd, std::string const opcode);
    };

}

#endif /* !TRANSFERTDATA_HPP_ */
