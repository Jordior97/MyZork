#ifndef _FUNCTIONS_
#define _FUNCTIONS_

enum action { Movement, Look, Open, Close, Pick, Drop, Help, Quit, Invalid_command, Inventory, Equip, Unequip, Stats, Equipment, Put, Get };


//I have to set different values to the inital elements of each enum to differentiate them.

int GetCommand(Vector<MyString>&);

#endif