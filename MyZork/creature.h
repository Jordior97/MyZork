#ifndef _CREATURE_
#define _CREATURE_

#include"Entity.h"


class Creature : public Entity
{
public:

	Creature(const char* name, const char* desc, Type type, int at, int hp, int m, int ar) :Entity(name, desc, type),
		attack(at), hp(hp), mana(m), armor(ar){};

	Room* location = nullptr;

	//Stats
	int hp;
	int mana;
	int attack;
	int armor;

	//virtual functions here:


};

#endif