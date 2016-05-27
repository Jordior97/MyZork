#ifndef _CREATURE_
#define _CREATURE_

#include"Entity.h"
#include"rooms.h"


class Creature : public Entity
{
public:
	//Stats
	int hp;
	int mana;
	int attack;
	int armor;

	Creature(const char* name, const char* desc, Type type, int at, int hp, int m, int ar);
	~Creature();
	Room* location;

	//virtual functions here:
	virtual void Update(){};
};

#endif