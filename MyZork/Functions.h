#ifndef _FUNCTIONS_
#define _FUNCTIONS_

enum action	{
	Movement, Look, Open, Close, Pick, Drop, Help, Quit,
	Invalid_command, Inventory, Equip, Unequip, Stats, Equipment,
	Put, Get, Buy, BuyFrom, SellTo, Attack, Spells, Heal, Mana, G_Heal, G_Mana
};

int GetCommand(const Vector<MyString>&); //Checks commands to redirect to the correct function

//Indicates direction 
int SetDirMove(const Vector<MyString>&); 
int SetDirLook(const Vector<MyString>&);
int SetDirOpenClose(const Vector<MyString>&); 


#endif