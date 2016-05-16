#ifndef _PLAYER_
#define _PLAYER_

#include"world.h"
#include"Entity.h"
#include"items.h"

class Player:public Entity
{
public:
	Player(const char*, const char*, Type, int, int, int, int);
	Room* player_pos = nullptr;

	//Inventory
	unsigned int num_items = 0;
	unsigned int max_items = 10;

	//Slots for equipping items
	bool head_item = false;
	bool body_item = false;
	bool LHand_item = false;
	bool RHand_item = false;
	bool legs_item = false;

	//Stats
	int hp;
	int mana;
	int attack;
	int armor;

	//Functions
	void Stats();
	void Movement(int&, const Vector<MyString>&);
	

};


#endif