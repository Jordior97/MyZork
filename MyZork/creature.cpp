#include"creature.h"

Creature::Creature(const char* name, const char* desc, Type type, int at, int hp, int m, int ar, CType c_type, int money) :Entity(name, desc, type), attack(at), hp(hp), mana(m), armor(ar), money(money), c_type(c_type){}

void Creature::Look() const
{
	printf("%s\n%s\n", name.c_str(), description.c_str());
}