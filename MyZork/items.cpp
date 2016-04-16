#include"world.h"
#include<stdio.h>

void Item::Look()const
{
	printf("%s\n%s\n",name.c_str(),description.c_str());
}

Item::Item(const char*name, const char*desc, Room* source, slot part, int at, int h, int m, int ar) :
Entity(name, desc), src(source), part(part), attack(at), hp(h), mana(m), armor(ar){}