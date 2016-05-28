#ifndef _KARLA_
#define _KARLA_

#include"creature.h"

class Karla :public Creature
{
public:

	Karla(const char* name, const char* desc, Type type, int at, int hp, int m, int ar, bool seller, int money) :
		Creature(name, desc, type, at, hp, m, ar, seller, money){}

};

#endif