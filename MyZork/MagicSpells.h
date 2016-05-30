#ifndef _SPELLS_
#define _SPELLS_

#include"player.h"

void Fire(const Vector<MyString>&, bool, bool, bool);
void Water(const Vector<MyString>&, bool, bool, bool);
void Electricity(const Vector<MyString>&, bool, bool, bool);
void Darkness(const Vector<MyString>&, bool, bool, bool);
void Brightness(const Vector<MyString>&, bool, bool, bool);

void HotSteam(); // fire + water
void ElectricStorm(); // water + electricity
void DarkFire(); // fire + darkness
void VoidSpear(); //darkness + brightness
void DivineStrike(); // electricity + brightness

#endif