#ifndef _PLAYER_
#define _PLAYER_


#include"creature.h"

class Player :public Creature
{
public:
	Player(const char* name, const char* desc, Type type, int at, int h, int m, int ar,bool seller, int money) :
		Creature(name, desc, type, at, h, m, ar,seller, money){}
	~Player(){};

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
	void Look(int, const Vector<MyString>&);
	void Open(int, const Vector<MyString>&);
	void Close(int, const Vector<MyString>&);
	void Inventory() const;
	void Equip(const Vector<MyString>&);
	void Unequip(const Vector<MyString>&);
	void Equipment() const;
	void Buy(const Vector<MyString>&) const;
	void BuyFrom(const Vector<MyString>&);
	void SellTo(const Vector<MyString>&);


};


#endif