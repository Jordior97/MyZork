#ifndef _TOTEM_
#define _TOTEM_

#include"creature.h"

enum TStates{ IDLE, QUEST_1, QUEST2, QUEST3, COMPLETE };

class Totem :public Creature
{
public:
	
	TStates actual_state = IDLE;

	Totem(const char* name, const char* desc, Type type, int at, int hp, int m, int ar, CType c_type, int money) :
		Creature(name, desc, type, at, hp, m, ar, c_type, money){}

	void Update();
	void Passive();
	void Q1();
	void Q2();
	void Q3();
	void Complete();

};

#endif