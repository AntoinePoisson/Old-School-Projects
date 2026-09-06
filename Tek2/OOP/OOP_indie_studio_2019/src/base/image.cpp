/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** image.cpp
*/

#include "Indie.hpp"
#include "MainMenu.hpp"
#include "SelectMenu.hpp"
#include "SplashMenu.hpp"
#include <map>
// #include <unistd.h>

ITexture *get_img(const std::string &filename)
{
    static std::map<std::string, ITexture *> textureMap = {};
    static ITexture *texture;
    static video::IImage *image;
    static irr::core::dimension2du size;
    static video::SColor color;
    static int pitch;
    static video::ECOLOR_FORMAT f;
    static int wiseLength;
    static void *buffer;

    if (textureMap.find(filename) == textureMap.end()) {
        if ((texture = indie::irrlicht->driver->getTexture(filename.c_str())) == nullptr)
            throw (indie::error::Image(filename));
        if ((image = indie::irrlicht->driver->createImageFromFile(filename.c_str())) == nullptr)
            throw (indie::error::Image(filename));
        size = texture->getSize();
        color = video::SColor(0xFFFF0000);
        pitch = texture->getPitch();
        f = texture->getColorFormat();
        wiseLength = video::IImage::getBitsPerPixelFromFormat(f) / 8;
        buffer = texture->lock(irr::video::E_TEXTURE_LOCK_MODE::ETLM_READ_WRITE, 0);
        if (buffer) {
            /* Prendre chaque pixel et les placer à un pixel inférieur définit par indie::irrlicht->R_RATIO */
            for (int x = 0; x < size.Width; x++) {
                for (int y = 0; y < size.Height; y++) {
                    color = image->getPixel(x, y);
                    int x_final = (x * ((indie::irrlicht->R_RATIO <= 0.99) ? indie::irrlicht->R_RATIO + 0.01 : indie::irrlicht->R_RATIO));
                    int y_final = (y * ((indie::irrlicht->R_RATIO <= 0.99) ? indie::irrlicht->R_RATIO + 0.01 : indie::irrlicht->R_RATIO));
                    color.getData((unsigned char *)buffer + y_final * pitch + x_final * wiseLength, f);
                }
            }

            /* Supprimer les restes de la texture qu'on ne veut plus // Partie de droite */
            for (int x = size.Width * ((indie::irrlicht->R_RATIO <= 0.99) ? indie::irrlicht->R_RATIO + 0.01 : indie::irrlicht->R_RATIO); x < size.Width; x++) {
                for (int y = 0; y < size.Height; y++) {
                    color = video::SColor(0, 0, 0, 0);
                    color.getData((unsigned char *)buffer + y * pitch + x * wiseLength, f);
                }
            }

            /* Supprimer les restes de la texture qu'on ne veut plus // Partie du bas */
            for (int x = 0; x < size.Width; x++) {
                for (int y = size.Height * ((indie::irrlicht->R_RATIO <= 0.99) ? indie::irrlicht->R_RATIO + 0.01 : indie::irrlicht->R_RATIO); y < size.Height; y++) {
                    color = video::SColor(0, 0, 0, 0);
                    color.getData((unsigned char *)buffer + y * pitch + x * wiseLength, f);
                }
            }
            texture->unlock();
        }
        textureMap.insert(std::make_pair(filename, texture));
    }
    return (textureMap[filename]);
}