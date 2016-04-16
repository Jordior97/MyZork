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
	bool equiped = false;
	slot part;
	Item(const char*, const char*, Room*, slot);
	
	//~Item();

};

#endif