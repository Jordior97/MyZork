#ifndef _PLAYER_
#define _PLAYER_

#include"creature.h"

class Player:public Creature
{
public:
	Player(const char*, const char*, Type, int, int, int, int);

	//Inventory
	unsigned int num_items = 0;
	unsigned int max_items = 10;

	//Slots for equipping items
	bool head_item = false;
	bool body_item = false;
	bool LHand_item = false;
	bool RHand_item = false;
	bool legs_item = false;

	//Functions
	void Stats();
	void Movement(int&, const Vector<MyString>&);
	void Pick(const Vector<MyString>&);
	void Drop(const Vector<MyString>&);
	void Put(const Vector<MyString>&);
	void Get(const Vector<MyString>&);



};


#endif