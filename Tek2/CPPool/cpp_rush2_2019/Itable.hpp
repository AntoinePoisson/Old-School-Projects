/*
** EPITECH PROJECT, 2020
** Itable
** File description:
** Itable
*/

#ifndef Itable_hpp
#define Itable_hpp

#include "IconveyorBelt.hpp"

class IconveyorBelt;

class Itable {
	public:
		Itable();
		~Itable();

		Itable *createTable();
		std::string **look() const;
		
		bool addTableObject(Object *obj);
		bool addTableObject(Object *obj, int index, bool force_add = false);
		bool deleteTableObject(int index);
		bool deleteTableObject(Object *obj);
		bool put(int i, IconveyorBelt *iconveyorbelt);
		Object *take();

	protected:
		Object **ObjectOnTable;
	private:
		int table_size = 10;
};

#endif /* !Itable_hpp */
