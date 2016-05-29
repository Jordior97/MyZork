#ifndef _FUNCTIONS_
#define _FUNCTIONS_

enum action		{ Movement, Look, Open, Close, Pick, Drop, Help, Quit, 
				Invalid_command, Inventory, Equip, Unequip, Stats, Equipment,
				Put, Get, Buy, BuyFrom, SellTo, Attack ,Spells};

int GetCommand(const Vector<MyString>&);
int SetDirMove(const Vector<MyString>&);
int SetDirLook(const Vector<MyString>&);
int SetDirOpenClose(const Vector<MyString>&);


#endif