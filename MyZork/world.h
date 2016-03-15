#ifndef _WORLD_
#define  _WORLD_

#include"rooms.h"
#include"player.h"
#include"exits.h"

// Now, if you include "world.h" in other files,
// you are including these other headers too.

class World
{
public:

	Room* rooms = nullptr;
	Player* player = nullptr;
	Exit* exits = nullptr;

	World();

	void CreateWorld() const;
	void Movement(int&,char[]);
	void Look(int&,char[]);
	void Help();

	~World();
};

#endif