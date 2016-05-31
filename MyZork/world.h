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
#include"Karla.h"
#include"Dragon.h"
#include"Skeletons.h"
#include"Rakdos.h"
#include"Totem.h"
#include"KikkiJikki.h"

#define NUM_ROOMS 13

class World
{
public:

	Vector<Entity*> entities; //All the entities are contained inside this vector
	Player* player; //Pointer to access to player
	World();
	~World();

	void CreateWorld();
	void Help() const;

};

extern World* world;

#endif