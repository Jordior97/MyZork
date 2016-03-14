#ifndef _EXITS_
#define  _EXITS_

#include"world.h"

enum dir{ north, south, east, west, up, down };

class Exit
{
public:
	char name[30];
	char description[200];
	Room* src; //source room
	Room* dst; //destination room
	bool open = true; //indicates if an exit is opened or closed
	dir direction;
};

#endif