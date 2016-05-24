#ifndef _ENTITY_ 
#define _ENTITY_

#include "MyString.h"
#include "Dlist.h"

enum Type{ PLAYER, ROOM, EXIT, ITEM , NPC};


class Entity
{
public:
	MyString name;
	MyString description;
	Type type;
	DList<Entity*> list;


	Entity(const char*,const char*,Type);
	~Entity();
	virtual void Look() const{};

};



#endif