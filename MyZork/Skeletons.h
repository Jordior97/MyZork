#ifndef _SKELETONS_
#define _SKELETONS_

#include"creature.h"

class Skeletons :public Creature
{
public:
	Skeletons(const char* name, const char* desc, Type type, int at, int hp, int m, int ar, CType c_type, int money, int at_delay) :
		Creature(name, desc, type, at, hp, m, ar, c_type, money, at_delay){}
	void Update(){};
};

#endif