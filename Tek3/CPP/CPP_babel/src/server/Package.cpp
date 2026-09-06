/*
** EPITECH PROJECT, 2020
** Babel
** File description:
** Package
*/

#include "Package.hpp"

babel::Package::Package(transfertData_t *transfert)
{
    babel::TransfertData _tmp_;
    _data.clear();
    _dataParameter = _tmp_.extractDataFromStruct(transfert);

    for (auto el : _dataParameter) {
        if (_dataParameter[0] != el)
            _data += " ";
        _data += el;
    }
    if (_dataParameter.empty() == false) {
        _dataOP = std::stoi(_dataParameter[0]);
        _dataParameter.erase(_dataParameter.begin());
    }
}

babel::Package::Package(std::string data)
: _data(data)
{
    parceParameter(_data);
}

std::string babel::Package::get(void)
{
    return (_data);
}

int babel::Package::getOp(void) const
{
    return (_dataOP);
}

std::vector<std::string> babel::Package::getParameter(void) const
{
    return (_dataParameter);
}

bool babel::Package::is_empty(void)
{
    return (_data.size() ? false : true);
}

void babel::Package::print(void)
{
    std::cout << "[Print]: Package (" << _data << ")." << std::endl;
}

std::string babel::Package::deserialize(boost::asio::streambuf &data)
{
    std::istream tmp(&data);
    std::getline(tmp, _data);
    return (_data);
}

void babel::Package::operator=(const Package &element)
{
    _data = element._data;
    _dataParameter = element._dataParameter;
    _dataOP = element._dataOP;
}

bool babel::Package::operator==(const Package &element)
{
    return (_data == element._data);
}

void babel::Package::operator+=(const Package &element)
{
    _data += element._data;
}

babel::Package babel::Package::operator+(const Package &element)
{
    return Package(_data + element._data);
}

std::string babel::Package::operator<<(const std::string &element)
{
    if (element.size()) {
    }
    return (_data);
}

void babel::Package::parceParameter(std::string &data)
{
    bool first = true;
    std::stringstream ss(data);
    std::string buff;

    while (getline(ss, buff, ' ')) {
        if (first) {
            try {
                _dataOP = std::stoi(buff);
            } catch(...) {
                _dataOP = 0;
                return;
            }
            first = !first;
        } else {
            _dataParameter.push_back(buff);
        }
    }
}