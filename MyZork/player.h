#ifndef _PLAYER_
#define _PLAYER_

#include"creature.h"
#define HEAL_DELAY 3000
#define MANA_DELAY 3000

enum PStates{ ALIVE, GAMEOVER , WIN};

class Player :public Creature
{
public:
	Player(const char* name, const char* desc, Type type, int at, int hp, int m, int ar, CType c_type, int money, int at_delay) :
		Creature(name, desc, type, at, hp, m, ar, c_type, money, at_delay){}
	~Player(){};

	PStates actual_state = ALIVE;

	unsigned int heal_count = GetTickCount();
	unsigned int mana_count = GetTickCount();

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
	void Heal(const Vector<MyString>&);
	void Mana(const Vector<MyString>&);

	//god mode
	void g_Mana(const Vector<MyString>&);
	void g_Heal(const Vector<MyString>&);

	void Gem_Abilities(const Vector<MyString>&);
	bool CheckGems(bool&, bool&, bool&, bool&, bool&);

	void Update();
	void Alive();
	void Win();




};


#endif