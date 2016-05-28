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
	int money;
	bool seller;

	Creature(const char* name, const char* desc, Type type, int at, int hp, int m, int ar, bool seller, int money);
	~Creature(){};
	Room* location;

	//virtual functions here:
	virtual void Update(){};
	void Look() const;
};

#endif