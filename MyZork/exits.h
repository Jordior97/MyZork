#ifndef _EXITS_
#define  _EXITS_

#include"world.h"
#include"Entity.h"

enum dir{ north, south, east, west, up, down };

class Exit :public Entity
{
public:
	Room* src; //source room
	Room* dst; //destination room
	bool door; //indicates if an exits has a door to open/close
	bool open; //indicates if an exit is opened or closed
	dir direction; //indicates the direction of the exit
	void Look()const;

	Exit(const char*, const char*,Room*,Room*,dir,bool,bool,Type);
	~Exit();

};

#endif