#ifndef _KARLA_
#define _KARLA_

#include"creature.h"

class Karla :public Creature
{
public:

	Karla(const char* name, const char* desc, Type type, int at, int hp, int m, int ar, CType c_type, int money, int at_delay) :
		Creature(name, desc, type, at, hp, m, ar, c_type, money, at_delay){}
	void Update(){};
};

#endif