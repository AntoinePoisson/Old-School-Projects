/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** AMenu.hpp
*/

#ifndef __AMENU_HPP_
#define __AMENU_HPP_

#include "IMenu.hpp"

namespace indie
{
    class AMenu : public IMenu
    {
        public:
            virtual ~AMenu() = default;

            virtual void run() = 0;
            template<class T>
            void button(int x, int y, T *obj, void (T::*ptr)(), const std::string &path="", const std::string &placeholder="");
            void background(const std::string &path) override;
            void image(int x, int y, const std::string &path, int alpha = 255) override;
            void previousButton(int x, int y, void (*ptr)());
        protected:
            bool touched;
    };
}

ITexture *get_img(const std::string &filename);

template<class T>
void indie::AMenu::button(int x, int y, T *obj, void (T::*ptr)(), const std::string &path, const std::string &placeholder)
{
    ITexture *butt1 = get_img(path.c_str());

    if (!butt1) {
        std::cerr << "Invalid texture loaded" << std::endl;
        return ;
    }

    auto size = butt1->getSize();
    auto cursor = indie::irrlicht->device->getCursorControl()->getPosition();
    if ((cursor.X > x * indie::irrlicht->R_RATIO && cursor.X < x * indie::irrlicht->R_RATIO + size.Width * indie::irrlicht->R_RATIO) && (cursor.Y > y * indie::irrlicht->R_RATIO && cursor.Y < y * indie::irrlicht->R_RATIO + size.Height * indie::irrlicht->R_RATIO)) {
        if (indie::irrlicht->event->getReleaseState()) {
            indie::irrlicht->event->resetMouse();
            (obj->*ptr)();
            return ;
        }
        this->image(x, y, placeholder);
    } else
        this->image(x, y, path);
}

#endif