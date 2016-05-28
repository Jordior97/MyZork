#ifndef _GOBLIN_
#define _GOBLIN_

#include"creature.h"

enum States{ WALK, ATTACK, DIE };

class Goblin :public Creature
{
public:

	States actual_state = WALK;

	Goblin(const char* name, const char* desc, Type type, int at, int hp, int m, int ar, CType c_type, int money) :
		Creature(name, desc, type, at, hp, m, ar, c_type, money){}
	void Update();
	void Movement();
	void Attack();
	void Die();
	
};

#endif