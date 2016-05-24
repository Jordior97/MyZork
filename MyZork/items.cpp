#include"world.h"
#include<stdio.h>

Item::Item(const char*name, const char*desc, Room* source, slot part, int at, int h, int m, int ar, Type type) :
Entity(name, desc,type), src(source), part(part), attack(at), hp(h), mana(m), armor(ar){}

Item::~Item(){}

void Item::Look()const
{
	if (part == Non_Equipable)
	{
		printf("%s\n%s\n", name.c_str(), description.c_str());

	}

	else
	{
		printf("%s (attack: %i / hp: %i / mana: %i armor: %i)\n%s\n", name.c_str(), attack, hp, mana, armor, description.c_str());
	}
}