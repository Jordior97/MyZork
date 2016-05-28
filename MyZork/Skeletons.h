#ifndef _SKELETONS_
#define _SKELETONS_

#include"creature.h"

class Skeletons :public Creature
{
public:
	Skeletons(const char* name, const char* desc, Type type, int at, int hp, int m, int ar, bool seller, int money) :
		Creature(name, desc, type, at, hp, m, ar, seller, money){}

};

#endif