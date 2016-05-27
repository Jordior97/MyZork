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
#include"creature.h"
#include"NPC.h"

#define NUM_ROOMS 13
#define NUM_EXITS 18
#define NUM_ITEMS 17


class World
{
public:

	Vector<Entity*> entities;
	Player* player;
	World();

	void CreateWorld();
	void Help() const;

	~World();
};

extern World* world;

#endif