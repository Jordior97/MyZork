#ifndef _RAKDOS_
#define _RAKDOS_

#include"creature.h"

enum RStates{WAITING, ATTACKING, R_DIE};
enum Attacks{ ATTACK1, ATTACK2, HEAL };

class Rakdos :public Creature
{
public:

	RStates actual_state = WAITING;
	int attack_type;

	Rakdos(const char* name, const char* desc, Type type, int at, int hp, int m, int ar, CType c_type, int money, int at_delay) :
		Creature(name, desc, type, at, hp, m, ar, c_type, money, at_delay){}

	void Update();
	void Waiting();
	void Attacking();


};

#endif