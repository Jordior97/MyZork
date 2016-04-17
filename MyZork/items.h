#ifndef  _ITEMS_
#define  _ITEMS_

#include"world.h"
#include"Entity.h"

enum slot { Head, Body, RHand, LHand, Legs, Non_Equipable };

class Item :public Entity
{
public:

	
	Room* src; //source room
	void Look() const;

	bool picked = false;
	bool equipped = false;
	bool inside = false;
	bool container = false;

	slot part; 

	//modifiers of player stats
	int attack;
	int hp;
	int mana;
	int armor;

	Item(const char*, const char*, Room*, slot, int, int, int, int);
	//~Item();

};

#endif