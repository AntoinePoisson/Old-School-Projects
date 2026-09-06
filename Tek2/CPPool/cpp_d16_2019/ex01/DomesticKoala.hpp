/*
** EPITECH PROJECT, 2020
** DomesticKoala
** File description:
** DomesticKoala
*/

#ifndef DomesticKoala_hpp
#define DomesticKoala_hpp

#include <iostream>
#include <vector>
#include "KoalaAction.hpp"

class DomesticKoala {
	public:
		explicit DomesticKoala(KoalaAction &);
		~DomesticKoala();


        // void KoalaAction();
        explicit DomesticKoala(const DomesticKoala &);
        DomesticKoala & operator=(const DomesticKoala &);

		void setKoalaAction(KoalaAction &action);

		using methodPointer_t = void (KoalaAction::*)(const std::string &);
		//typedef void (*methodPointer_t)(const std::string &);
		const std::vector<methodPointer_t> *getActions() const;

		void learnAction(unsigned char command, methodPointer_t action);
		void unlearnAction(unsigned char command);
		void doAction(unsigned char command, const std::string & param);
		// void setKoalaAction(KoalaAction &);

		KoalaAction *_action;
		std::vector<methodPointer_t> _stockage;
		std::vector<char> _index;
	protected:
	private:
};

#endif /* !DomesticKoala_hpp */
