/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** AMenu.cpp
*/

#include "AMenu.hpp"

void indie::AMenu::background(const std::string &path)
{
    ITexture *bg = get_img(path);

    indie::irrlicht->driver->draw2DImage(bg, position2d<s32>(0), rect<s32>(0,0,1920 * indie::irrlicht->R_RATIO,1080 * indie::irrlicht->R_RATIO), 0, SColor(255,255,255,255), false);
}

void indie::AMenu::image(int x, int y, const std::string &path, int alpha)
{
    ITexture *img = get_img(path);
    auto size = img->getSize();

    indie::irrlicht->driver->draw2DImage(img, irr::core::vector2di(x * indie::irrlicht->R_RATIO, y * indie::irrlicht->R_RATIO), rect<s32>(0,0,size.Width * ((indie::irrlicht->R_RATIO <= 0.99) ? indie::irrlicht->R_RATIO + 0.01 : indie::irrlicht->R_RATIO),size.Height * ((indie::irrlicht->R_RATIO <= 0.99) ? indie::irrlicht->R_RATIO + 0.01 : indie::irrlicht->R_RATIO)), 0, SColor(alpha,255,255,255), true);
}

void indie::AMenu::previousButton(int x, int y, void (*ptr)())
{
    // this->button(x, y, ptr, "", "");
}