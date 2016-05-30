#ifndef _SKELETONS_
#define _SKELETONS_

#include"creature.h"

enum SStates{ S_IDLE, N_ATTACK, RAGE, S_DIE };

class Skeletons :public Creature
{
public:

	SStates actual_state = S_IDLE;

	Skeletons(const char* name, const char* desc, Type type, int at, int hp, int m, int ar, CType c_type, int money, int at_delay) :
		Creature(name, desc, type, at, hp, m, ar, c_type, money, at_delay){}

	void Update();
	void SIdle();
	void NormalAttack();
	void RageMode();



};

#endif