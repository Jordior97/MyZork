#include"world.h"
#include<stdio.h>

Room::Room(const char* name, const char* descrip, Type type) :Entity(name, descrip, type){}

Room::~Room(){}

void Room::Look()const
{
	printf("\n%s\n%s", name.c_str(), description.c_str());
}
