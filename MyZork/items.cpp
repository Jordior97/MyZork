#include"world.h"
#include<stdio.h>

Item::Item(const char*name, const char*desc, slot part, int at, int h, int m, int ar, Type type, int money) :
Entity(name, desc,type), part(part), attack(at), hp(h), mana(m), armor(ar),money(money){}

Item::~Item(){}

void Item::Look()const
{
	if (part == Non_Equipable)
	{
		printf("%s\n%s\n", name.c_str(), description.c_str());

	}
	else
	{
		printf("%s (attack: %i / hp: %i / mana: %i armor: %i / money: %i)\n%s\n", name.c_str(), attack, hp, mana, armor,money, description.c_str());
	}
}