#ifndef _GOBLIN_
#define _GOBLIN_

#include"creature.h"
#define WALK_DELAY 3000


enum GStates{ WALK, ATTACK, DIE };


class Goblin :public Creature
{
public:

	GStates actual_state = WALK;
	

	Goblin(const char* name, const char* desc, Type type, int at, int hp, int m, int ar, CType c_type, int money, int at_speed) :
		Creature(name, desc, type, at, hp, m, ar, c_type, money,at_speed){}

	void Update();
	void Movement();
	void Attack();
	
};

#endif