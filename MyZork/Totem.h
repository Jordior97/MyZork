#ifndef _TOTEM_
#define _TOTEM_

#include"creature.h"

class Totem :public Creature
{
public:
	bool seller;
	Totem(const char* name, const char* desc, Type type, int at, int hp, int m, int ar, CType c_type, int money) :
		Creature(name, desc, type, at, hp, m, ar, c_type, money){}
	void Update(){};
};

#endif