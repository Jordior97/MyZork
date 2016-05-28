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

	bool picked = false; //indicates if the item is in the inventory
	bool equipped = false; //indicates if the item is equipped

	bool inside = false; //indicates if the item is inside the container
	bool container = false; //indicates if the item is a container

	bool magic_gem = false; //indicates if the item is a magic gem

	slot part; //indicates the slot it occupies

	//modifiers of player stats
	int attack;
	int hp;
	int mana;
	int armor;
	int money;

	Item(const char*, const char*, Room*, slot, int, int, int, int,Type,int);
	~Item();
};

#endif