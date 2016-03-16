#ifndef _WORLD_
#define  _WORLD_

#include"rooms.h"
#include"player.h"
#include"exits.h"
#include"Functions.h"

#define EXIT 200
#define NUM_ROOMS 13
#define NUM_EXITS 18
#define INVALID_COMMAND 100

// Now, if you include "world.h" in other files,
// you are including these other headers and MACROS too.

class World
{
public:

	Room* rooms = nullptr;
	Player* player = nullptr;
	Exit* exits = nullptr;

	World();

	void CreateWorld() const;
	void Movement(int&,int);
	void Look(int,int) const;
	void Help() const;
	void Open(int,int) const;
	void Close(int,int) const;

	~World();
};

#endif