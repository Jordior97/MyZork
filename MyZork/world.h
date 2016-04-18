#ifndef _WORLD_
#define  _WORLD_

// Now, if you include "world.h" in other files,
// you are including these other headers and MACROS too.
#include"rooms.h"
#include"player.h"
#include"exits.h"
#include"Functions.h"
#include"Entity.h"
#include"MyString.h"
#include"items.h"
#include"vector.h"

#define NUM_ROOMS 13
#define NUM_EXITS 18
#define NUM_ITEMS 17


class World
{
public:

	Vector<Room*> rooms;
	Vector<Exit*> exits;
	Vector<Item*> items;

	Player* player = nullptr;

	World();

	void CreateWorld();
	void Movement(int&, Vector<MyString>&);
	void Look(int, Vector<MyString>&) const;
	void Help() const;
	void Open(int, Vector<MyString>&) const;
	void Close(int, Vector<MyString>&) const;
	void Pick(Vector<MyString>&) const;
	void Drop(Vector<MyString>&) const;
	void Inventory() const;
	void Equip(Vector<MyString>&) const;
	void Unequip(Vector<MyString>&) const;
	void Equipment() const;
	void Put(Vector<MyString>&) const;
	void Get(Vector<MyString>&) const;

	~World();
};

#endif