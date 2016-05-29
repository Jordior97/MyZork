#ifndef _CREATURE_
#define _CREATURE_

#include"Entity.h"
#include"rooms.h"
#include"windows.h"

enum CType{ HERO, SELLER, HOSTILE, PASSIVE, TALKER };

class Creature : public Entity
{
public:

	CType c_type;

	//Stats
	int hp;
	int mana;
	int attack;
	int armor;
	int at_delay;
	int money;

	//time counter
	unsigned int timer = GetTickCount();
	unsigned int actual_time;

	Room* location;
	Creature* enemy = nullptr;

	Creature(const char* name, const char* desc, Type type, int at, int hp, int m, int ar, CType c_type, int money, int at_speed);
	~Creature(){};


	//functions 
	void Update(){};
	virtual void Movement(const Vector<MyString>&){};
	virtual void Drop(const Vector<MyString>&){};

	void Look() const;
	
};

#endif