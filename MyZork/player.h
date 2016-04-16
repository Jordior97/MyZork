#ifndef _PLAYER_
#define _PLAYER_

#include"world.h"
#include"Entity.h"
#include"items.h"

class Player
{
public:

	Room* player_pos;

	//Inventory
	unsigned int num_items = 0;
	unsigned int max_items = 7;


	//Slots for equip items
	bool head_item = false;
	bool body_item = false;
	bool LHand_item = false;
	bool RHand_item = false;
	bool legs_item = false;

	//Stats
	int hp = 100;
	int mana = 500;
	int attack = 20;
	int armor = 0;

	void Stats();
	

};


#endif