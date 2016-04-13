#ifndef _WORLD_
#define  _WORLD_

#include"rooms.h"
#include"player.h"
#include"exits.h"
#include"Functions.h"
#include"Entity.h"
#include"MyString.h"
#include"items.h"
#include"vector.h"

#define EXIT 200
#define NUM_ROOMS 13
#define NUM_EXITS 18
#define NUM_ITEMS 2
#define TOKENIZE 100

// Now, if you include "world.h" in other files,
// you are including these other headers and MACROS too.

class World
{
public:

	Vector<Room*> rooms;
	Vector<Exit*> exits;
	Vector<Item*> items;


	Player* player = nullptr;

	Item* inventory = nullptr;

	World();

	void CreateWorld();
	void Movement(int&,int);
	void Look(int,int) const;
	void Help() const;
	void Open(int,int) const;
	void Close(int,int) const;
	void Pick(const MyString&);
	void Drop(const MyString&);

	~World();
};

#endif