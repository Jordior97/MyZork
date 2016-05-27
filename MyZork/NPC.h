#ifndef _NPC_
#define _NPC_

#include"creature.h"

class Npc :public Creature
{
public:

	Npc(const char* name, const char* desc, Type type, int at, int hp, int m, int ar) :
		Creature(name, desc, type, at, hp, m, ar){}

	void Look() const;

};

#endif