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

	//I decided to divide the Entities vector into this 3 vectors to modify directly
	//some specific properties of these different classes

	/*Vector<Room*> rooms;
	Vector<Exit*> exits;
	Vector<Item*> items;*/

	Vector<Entity*> entities;

	Player* player;

	World();

	void CreateWorld();
	//void Movement(int&, const Vector<MyString>&);
	void Look(int, const Vector<MyString>&) const;
	void Help() const;
	void Open(int, const Vector<MyString>&) const;
	void Close(int, const Vector<MyString>&) const;
	//void Pick(const Vector<MyString>&) const;
	//void Drop(const Vector<MyString>&) const;
	void Inventory() const;
	void Equip(const Vector<MyString>&) const;
	void Unequip(const Vector<MyString>&) const;
	void Equipment() const;
	void Put(const Vector<MyString>&) const;
	void Get(const Vector<MyString>&) const;

	~World();
};

extern World* world;

#endif