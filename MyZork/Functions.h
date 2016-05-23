#ifndef _FUNCTIONS_
#define _FUNCTIONS_

enum action { Movement, Look, Open, Close, Pick, Drop, Help, Quit, Invalid_command, Inventory, Equip, Unequip, Stats, Equipment, Put, Get };

int GetCommand(const Vector<MyString>&);
int SetDirMove(const Vector<MyString>&);
int SetDirLook(const Vector<MyString>&);
int SetDirOpen(const Vector<MyString>&);


#endif