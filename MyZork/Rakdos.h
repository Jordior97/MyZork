#ifndef _RAKDOS_
#define _RAKDOS_

#include"creature.h"

class Rakdos :public Creature
{
public:
	Rakdos(const char* name, const char* desc, Type type, int at, int hp, int m, int ar, CType c_type, int money) :
		Creature(name, desc, type, at, hp, m, ar, c_type, money){}

};

#endif