/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2019
** File description:
** SplashMenu.hpp
*/

#ifndef __SPLASHMENU_HPP_
#define __SPLASHMENU_HPP_

#include "AMenu.hpp"

namespace indie
{
    class SplashMenu : public AMenu
    {
        public:
            SplashMenu() = default;
            virtual ~SplashMenu() = default;

            void run();
        private:
            void afterAnim(float width, float height);
            ITexture *logo;
            IGUIFont *font;
		    u32 time;
            bool isOpen = true;
    };
}


#endif