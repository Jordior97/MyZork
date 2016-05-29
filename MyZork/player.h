#ifndef _PLAYER_
#define _PLAYER_


#include"creature.h"

class Player :public Creature
{
public:
	Player(const char* name, const char* desc, Type type, int at, int h, int m, int ar,CType ctype, int money) :
		Creature(name, desc, type, at, h, m, ar,ctype, money){}
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
	void Movement(const Vector<MyString>&);
	void Pick(const Vector<MyString>&);
	void Drop(const Vector<MyString>&);
	void Put(const Vector<MyString>&);
	void Get(const Vector<MyString>&);
	void Look( const Vector<MyString>&) const;
	void Open( const Vector<MyString>&);
	void Close( const Vector<MyString>&);
	void Inventory() const;
	void Equip(const Vector<MyString>&);
	void Unequip(const Vector<MyString>&);
	void Equipment() const;
	void Buy(const Vector<MyString>&) const;
	void BuyFrom(const Vector<MyString>&);
	void SellTo(const Vector<MyString>&);
	void Attack(const Vector<MyString>&);

	void Gem_Abilities(const Vector<MyString>&);

	void Update(){};


};


#endif