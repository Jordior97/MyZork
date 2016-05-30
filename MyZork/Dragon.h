#ifndef _DRAGON_
#define _DRAGON_

#include"creature.h"
#define FBALL_DELAY 8000

enum DStates{ SLEEP, D_ATTACK, FIRE_BALL, D_DIE };

class Dragon :public Creature
{
public:

	DStates actual_state = SLEEP;
	unsigned int FBall_count = GetTickCount();

	Dragon(const char* name, const char* desc, Type type, int at, int hp, int m, int ar, CType c_type, int money, int at_delay) :
		Creature(name, desc, type, at, hp, m, ar, c_type, money, at_delay){}

	void Update();
	void Sleep();
	void FireBall();
	void ClawsAttack();

};

#endif