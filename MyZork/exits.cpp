#include"world.h"
#include<stdio.h>

Exit::Exit(const char* name, const char* descrip, Room* source, Room* dest, dir direct,bool d,bool o,Type type) :Entity(name, descrip,type), 
src(source), dst(dest), direction(direct),door(d),open(o){}

Exit::~Exit(){}

void Exit::Look()const
{
	printf("\n%s%s\n", name.c_str(), description.c_str());
}