#ifndef _DRAGON_
#define _DRAGON_

#include"creature.h"

class Dragon :public Creature
{
public:
	bool seller;
	Dragon(const char* name, const char* desc, Type type, int at, int hp, int m, int ar, bool seller, int money) :
		Creature(name, desc, type, at, hp, m, ar, seller, money){}

};

#endif