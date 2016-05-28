#ifndef _GOBLIN_
#define _GOBLIN_

#include"creature.h"

class Goblin :public Creature
{
public:
	Goblin(const char* name, const char* desc, Type type, int at, int hp, int m, int ar, CType c_type, int money) :
		Creature(name, desc, type, at, hp, m, ar, c_type, money){}

};

#endif