#ifndef _TOTEM_
#define _TOTEM_

#include"creature.h"
#define COUNTDOWN 10000

enum TStates{ IDLE, ACTIVATION, EXPLOSION, EVAPORATION};

class Totem :public Creature
{
public:
	
	TStates actual_state = IDLE;
	unsigned int countdown;

	Totem(const char* name, const char* desc, Type type, int at, int hp, int m, int ar, CType c_type, int money, int at_delay) :
		Creature(name, desc, type, at, hp, m, ar, c_type, money, at_delay){}

	void Update();
	void Passive();
	void Activation();
	void Explosion();

};

#endif