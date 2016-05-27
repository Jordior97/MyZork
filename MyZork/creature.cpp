#include"creature.h"

Creature::Creature(const char* name, const char* desc, Type type, int at, int hp, int m, int ar):Entity(name, desc, type), attack(at), hp(hp), mana(m), armor(ar){}
