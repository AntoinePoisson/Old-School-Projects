/*
** EPITECH PROJECT, 2020
** B-CPP-500-PAR-5-1-babel-antoine.poisson
** File description:
** DataClient
*/

#include "DataClient.h"

babel::DataClient::DataClient(const std::string &fst, const std::string &snd)
{
    setFirstParam(fst);
    setSecondParam(snd);
}

babel::DataClient::DataClient(const std::string &fst, uint16_t port)
{
    setFirstParam(fst);
    setSecondParam(port);
}

babel::DataClient::~DataClient()
{
}


void babel::DataClient::setFirstParam(const std::string &fst)
{
    _fstParam = fst;

}

void babel::DataClient::setSecondParam(const std::string &snd)
{
    _sndParam = snd;

}


const std::string& babel::DataClient::getFirstParam() const
{
    return _fstParam;
}

const std::string& babel::DataClient::getSecondParam() const
{
    return _sndParam;
}

void babel::DataClient::setSecondParam(int port)
{
    _port = port;

}

uint16_t babel::DataClient::getPort() const
{
    return _port;
}

