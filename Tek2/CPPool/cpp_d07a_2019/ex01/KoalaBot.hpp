/*
** EPITECH PROJECT, 2020
** KoalaBot
** File description:
** KoalaBot
*/

#ifndef KOALABOT_H
#define KOALABOT_H

#include "Parts.hpp"

class KoalaBot {
	public:
		KoalaBot(std::string serial = "Bob-01");
		~KoalaBot();
        void setParts(const Arms &Arms);
        void setParts(const Legs &Legs);
        void setParts(const Head &Head);

        void swapParts(Arms &arms);
        void swapParts(Legs &legs);
        void swapParts(Head &head);

        void informations();
        bool status();

	private:
        Arms _Arms;
        Legs _Legs;
        Head _Head;
        std::string _serial;
};

#endif /* !KOALABOT_H */
