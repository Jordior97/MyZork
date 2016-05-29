#ifndef _SPELLS_
#define _SPELLS_

#include"player.h"

void Fire(const Vector<MyString>&);
void Water(const Vector<MyString>&);
void Electricity(const Vector<MyString>&);
void Darkness(const Vector<MyString>&);
void Brightness(const Vector<MyString>&);

void HotSteam(const Vector<MyString>&); // fire + water
void ElectricStorm(const Vector<MyString>&); // water + electricity
void DarkFire(const Vector<MyString>&); // fire + darkness
void Nothing(const Vector<MyString>&); //darkness + brightness
void DivineStrike(const Vector<MyString>&); // electricity + brightness

void Rainbow(const Vector<MyString>&); // all gems, in order



#endif