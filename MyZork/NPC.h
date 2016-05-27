#ifndef _NPC_
#define _NPC_

#include"creature.h"

class Npc :public Creature
{
public:
	bool seller;
	Npc(const char* name, const char* desc, Type type, int at, int hp, int m, int ar, bool s) :
		Creature(name, desc, type, at, hp, m, ar), seller(s){}

	void Look() const;

};

#endif