#ifndef _ENTITY_ 
#define _ENTITY_

#include"MyString.h"

enum Type{ PLAYER, ROOM, EXIT, ITEM };

class Entity
{
public:
	MyString name;
	MyString description;
	Type type;
	Entity(const char*,const char*,Type);
	~Entity();
	virtual void Look() const{};

};



#endif