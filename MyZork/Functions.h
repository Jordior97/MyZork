#ifndef _FUNCTIONS_
#define _FUNCTIONS_

enum action { Movement, Look, Open, Close, Pick, Drop, Help, Quit, Invalid_command, Inventory, Equip, Unequip, Stats, Equipment, Put, Get };

int GetCommand(const Vector<MyString>&);
int SetDirection(const Vector<MyString>&);

#endif