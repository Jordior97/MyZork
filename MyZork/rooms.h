#ifndef _ROOMS_
#define  _ROOMS_

#include"Entity.h"

class Room:public Entity
{
public:
	Room(const char*, const char*,Type);
	~Room();
	
	void Look()const;
	
};

#endif