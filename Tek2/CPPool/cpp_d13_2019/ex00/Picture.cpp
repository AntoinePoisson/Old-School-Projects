/*
** EPITECH PROJECT, 2020
** Picture
** File description:
** Picture
*/

#include "Picture.hpp"

Picture::Picture()
{
    data = "";
}

Picture::Picture(const std::string &file)
{
    getPictureFromFile(file);
}

Picture::~Picture()
{
}


bool Picture::getPictureFromFile(const std::string &file)
{
    std::string name = "";

    std::ifstream data (file, std::ifstream::in);
    if (!data) {
        this->data = "ERROR";
        return (false);
    }
    char c = data.get();
    while (data.good()) {
        name += c;
        c = data.get();
    }
    data.close();
    this->data = name;
    return (true);
}