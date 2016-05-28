#ifndef _CREATURE_
#define _CREATURE_

#include"Entity.h"
#include"rooms.h"

enum CType{ HERO, SELLER, HOSTILE, PASSIVE };

class Creature : public Entity
{
public:

	CType c_type;

	//Stats
	int hp;
	int mana;
	int attack;
	int armor;
	int money;
	

	Creature(const char* name, const char* desc, Type type, int at, int hp, int m, int ar, CType c_type, int money);
	~Creature(){};
	Room* location;

	//virtual functions here:
	virtual void Update(){};
	void Look() const;
};

#endif