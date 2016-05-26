#ifndef _NPC_
#define _NPC_

#include"creature.h"

class NPC :public Creature
{
public:
	NPC(const char* name, const char* desc, Type type, int at, int hp, int m, int ar) :
		Creature(name, desc, type, at, hp, m, ar){}
};

#endif