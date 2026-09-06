/*
** EPITECH PROJECT, 2020
** B-CPP-500-PAR-5-1-babel-antoine.poisson
** File description:
** TransfertData
*/

#include "TransfertData.hpp"

    //! Public
babel::TransfertData::TransfertData()
{
}

std::vector<std::string> babel::TransfertData::extractData(std::string message)
{
    transfertData_t result = {};

    memcpy(&result, message.c_str(), sizeof(transfertData_t));
    switch (result.opcode) {
        case 100: return (cmdListRelation(&result, "100"));
        case 110: return (cmdConfCall(&result, "110"));
        case 111: return (cmdId(&result, "111"));
        case 112: return (cmdVoid(&result, "112"));
        case 120: return (cmdConfRelation(&result, "120"));
        case 130: return (cmdBool(&result, "130"));
        case 131: return (cmdBool(&result, "131"));
        case 132: return (cmdVoid(&result, "132"));
        case 210: return (cmdAskCall(&result, "210"));
        case 211: return (cmdId(&result, "211"));
        case 212: return (cmdId(&result, "212"));
        case 220: return (cmdAddRelation(&result, "220"));
        case 221: return (cmdId(&result, "221"));
        case 222: return (cmdId(&result, "222"));
        case 223: return (cmdVoid(&result, "223"));
        case 230: return (cmdLog(&result, "230"));
        case 231: return (cmdLog(&result, "231"));
        case 232: return (cmdVoid(&result, "232"));
        default: return (cmdVoid(&result, "000"));
    }
    return (std::vector<std::string>());
}

std::vector<std::string> babel::TransfertData::extractDataFromStruct(transfertData_t *result)
{
    switch (result->opcode) {
        case 100: return (cmdListRelation(result, "100"));
        case 110: return (cmdConfCall(result, "110"));
        case 111: return (cmdId(result, "111"));
        case 112: return (cmdVoid(result, "112"));
        case 120: return (cmdConfRelation(result, "120"));
        case 130: return (cmdBool(result, "130"));
        case 131: return (cmdBool(result, "131"));
        case 132: return (cmdVoid(result, "132"));
        case 210: return (cmdAskCall(result, "210"));
        case 211: return (cmdId(result, "211"));
        case 212: return (cmdId(result, "212"));
        case 220: return (cmdAddRelation(result, "220"));
        case 221: return (cmdId(result, "221"));
        case 222: return (cmdId(result, "222"));
        case 223: return (cmdVoid(result, "223"));
        case 230: return (cmdLog(result, "230"));
        case 231: return (cmdLog(result, "231"));
        case 232: return (cmdVoid(result, "232"));
        default: return (cmdVoid(result, "000"));
    }
    return (std::vector<std::string>());
}

babel::transfertData_t babel::TransfertData::transcriptData(int opcode, std::vector<std::string> cmd)
{
    transfertData_t result = {};

    switch (opcode) {
        case 100: return (cmd100(cmd));
        case 110: return (cmd110(cmd));
        case 111: return (cmd111(cmd));
        case 112: return (cmd112(cmd));
        case 120: return (cmd120(cmd));
        case 130: return (cmd130(cmd));
        case 131: return (cmd131(cmd));
        case 132: return (cmd132(cmd));
        case 210: return (cmd210(cmd));
        case 211: return (cmd211(cmd));
        case 212: return (cmd212(cmd));
        case 220: return (cmd220(cmd));
        case 221: return (cmd221(cmd));
        case 222: return (cmd222(cmd));
        case 223: return (cmd223(cmd));
        case 230: return (cmd230(cmd));
        case 231: return (cmd231(cmd));
        case 232: return (cmd232(cmd));
        default: return (result);
    }
}



    //!Private
babel::transfertData_t babel::TransfertData::cmd100(std::vector<std::string> const & cmd)
{
    std::vector<std::string> results;
    transfertData_t result = {};
    int index = 0;

    result.opcode = 100;
    for (size_t i = 1; i < cmd.size(); i++, index++) {
        boost::split(results, cmd[i], [](char c){ return c == '/'; });
        result.relation[index].id = std::stoi(results[0]);
        strcpy(result.relation[index].username, results[1].c_str());
        result.relation[index].online = ((results[2] == "1") ? true : false);
    }
    for (auto &a: result.relation) {
        if (strlen(a.username) == 0)
            break;
    }
    return (result);
}

babel::transfertData_t babel::TransfertData::cmd110(std::vector<std::string> const & cmd)
{
    transfertData_t result = {};

    if (cmd.size() != 4)
        return (result);
    result.opcode = 110;
    result.id = std::stoi(cmd[0]);
    result.portUdp = std::stoi(cmd[1]);
    strcpy(result.ip, cmd[2].c_str());
    strcpy(result.username, cmd[3].c_str());
    return (result);
}

babel::transfertData_t babel::TransfertData::cmd111(std::vector<std::string> const & cmd)
{
    transfertData_t result = {};

    if (cmd.size() != 1)
        return (result);
    result.opcode = 111;
    result.id = std::stoi(cmd[0]);
    return (result);
}

babel::transfertData_t babel::TransfertData::cmd112(std::vector<std::string> const & cmd)
{
    transfertData_t result = {};

    if (cmd.size()) {
    }
    result.opcode = 112;
    return (result);
}

babel::transfertData_t babel::TransfertData::cmd120(std::vector<std::string> const & cmd)
{
    transfertData_t result = {};

    if (cmd.size() != 3)
        return (result);
    result.opcode = 120;
    strcpy(result.username, cmd[1].c_str());
    result.id = std::stoi(cmd[2]);
    return (result);
}

babel::transfertData_t babel::TransfertData::cmd130(std::vector<std::string> const & cmd)
{
    transfertData_t result = {};

    if (cmd.size() != 1)
        return (result);
    result.opcode = 130;
    result.rep = (cmd[0] == "1") ? true : false;
    return (result);
}

babel::transfertData_t babel::TransfertData::cmd131(std::vector<std::string> const & cmd)
{
    transfertData_t result = {};

    if (cmd.size() != 1)
        return (result);
    result.opcode = 131;
    result.rep = (cmd[0] == "1") ? true : false;
    return (result);
}

babel::transfertData_t babel::TransfertData::cmd132(std::vector<std::string> const & cmd)
{
    transfertData_t result = {};

    if (cmd.size()) {
    }
    result.opcode = 132;
    return (result);
}

babel::transfertData_t babel::TransfertData::cmd210(std::vector<std::string> const & cmd)
{
    transfertData_t result = {};

    if (cmd.size() != 2)
        return (result);
    result.opcode = 210;
    result.id = std::stoi(cmd[0]);
    result.portUdp = std::stoi(cmd[1]);
    return (result);
}

babel::transfertData_t babel::TransfertData::cmd211(std::vector<std::string> const & cmd)
{
    transfertData_t result = {};

    if (cmd.size() != 1)
        return (result);
    result.opcode = 211;
    result.id = std::stoi(cmd[0]);
    return (result);
}

babel::transfertData_t babel::TransfertData::cmd212(std::vector<std::string> const & cmd)
{
    transfertData_t result = {};

    if (cmd.size() != 1)
        return (result);
    result.opcode = 212;
    result.id = std::stoi(cmd[0]);
    return (result);
}

babel::transfertData_t babel::TransfertData::cmd220(std::vector<std::string> const & cmd)
{
    transfertData_t result = {};

    if (cmd.size() != 2)
        return (result);
    result.opcode = 220;
    strcpy(result.username, cmd[1].c_str());
    return (result);
}

babel::transfertData_t babel::TransfertData::cmd221(std::vector<std::string> const & cmd)
{
    transfertData_t result = {};

    if (cmd.size() != 1)
        return (result);
    result.opcode = 221;
    result.id = std::stoi(cmd[0]);
    return (result);
}

babel::transfertData_t babel::TransfertData::cmd222(std::vector<std::string> const & cmd)
{
    transfertData_t result = {};

    if (cmd.size() != 1)
        return (result);
    result.opcode = 222;
    result.id = std::stoi(cmd[0]);
    return (result);
}

babel::transfertData_t babel::TransfertData::cmd223(std::vector<std::string> const & cmd)
{
    transfertData_t result = {};

    if (cmd.size()) {
    }
    result.opcode = 223;
    return (result);
}

babel::transfertData_t babel::TransfertData::cmd230(std::vector<std::string> const & cmd)
{
    transfertData_t result = {};

    if (cmd.size() != 4)
        return (result);
    result.opcode = 230;
    strcpy(result.username, cmd[1].c_str());
    strcpy(result.password, cmd[3].c_str());
    return (result);
}

babel::transfertData_t babel::TransfertData::cmd231(std::vector<std::string> const & cmd)
{
    transfertData_t result = {};

    if (cmd.size() != 4)
        return (result);
    result.opcode = 231;
    strcpy(result.username, cmd[1].c_str());
    strcpy(result.password, cmd[3].c_str());
    return (result);
}

babel::transfertData_t babel::TransfertData::cmd232(std::vector<std::string> const & cmd)
{
    transfertData_t result = {};

    if (cmd.size()) {
    }
    result.opcode = 232;
    return (result);
}

std::vector<std::string> babel::TransfertData::cmdVoid(babel::transfertData_t *cmd, std::string const opcode)
{
    std::vector<std::string> result;

    if (cmd) {
    }
    result.push_back(opcode);
    return (result);
}

std::vector<std::string> babel::TransfertData::cmdLog(babel::transfertData_t *cmd, std::string const opcode)
{
    std::vector<std::string> result;

    result.push_back(opcode);
    result.push_back("1");
    result.push_back(cmd->username);
    result.push_back("1");
    result.push_back(cmd->password);
    return (result);
}

std::vector<std::string> babel::TransfertData::cmdId(babel::transfertData_t *cmd, std::string const opcode)
{
    std::vector<std::string> result;

    result.push_back(opcode);
    result.push_back(std::to_string(cmd->id));
    return (result);
}

std::vector<std::string> babel::TransfertData::cmdAddRelation(babel::transfertData_t *cmd, std::string const opcode)
{
    std::vector<std::string> result;

    result.push_back(opcode);
    result.push_back("1");
    result.push_back(cmd->username);
    return (result);
}

std::vector<std::string> babel::TransfertData::cmdAskCall(babel::transfertData_t *cmd, std::string const opcode)
{
    std::vector<std::string> result;

    result.push_back(opcode);
    result.push_back(std::to_string(cmd->id));
    result.push_back(std::to_string(cmd->portUdp));
    return (result);
}

std::vector<std::string> babel::TransfertData::cmdBool(babel::transfertData_t *cmd, std::string const opcode)
{
    std::vector<std::string> result;

    result.push_back(opcode);
    result.push_back(cmd->rep ? "1" : "0");
    return (result);
}

std::vector<std::string> babel::TransfertData::cmdConfRelation(babel::transfertData_t *cmd, std::string const opcode)
{
    std::vector<std::string> result;

    result.push_back(opcode);
    result.push_back("1");
    result.push_back(cmd->username);
    result.push_back(std::to_string(cmd->id));
    return (result);
}

std::vector<std::string> babel::TransfertData::cmdConfCall(babel::transfertData_t *cmd, std::string const opcode)
{
    std::vector<std::string> result;

    result.push_back(opcode);
    result.push_back(std::to_string(cmd->id));
    result.push_back(std::to_string(cmd->portUdp));
    result.push_back(cmd->ip);
    result.push_back(cmd->username);
    return (result);
}

std::vector<std::string> babel::TransfertData::cmdListRelation(babel::transfertData_t *cmd, std::string const opcode)
{
    int count = 0;
    std::vector<std::string> result;

    for (auto el : cmd->relation) {
        if (strlen(el.username) == 0)
            break;
        count++;
    }
    result.push_back(opcode);
    result.push_back(std::to_string(count));
    for (auto el : cmd->relation) {
        if (strlen(el.username) == 0)
            break;
        result.push_back(std::to_string(el.id) + "/" + el.username + "/" + (el.online ? "1" : "0"));
    }
    return (result);
}
