#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"world.h"


int GetCommand(const Vector<MyString>&commands)
{
	//'GO' COMMANDS
	if (commands[0] == "go" || commands[0] == "n" || commands[0] == "s" || commands[0] == "e" ||
		commands[0] == "w" || commands[0] == "d" || commands[0] == "u" || commands[0] == "north" ||
		commands[0] == "south" || commands[0] == "east" || commands[0] == "west" || commands[0] == "up" || 
		commands[0] == "down")
	{
		return Movement;
	}

	//'LOOK' COMMANDS
	else if (commands[0] == "look")
	{
		return Look;
	}
	
	//'OPEN' COMMANDS
	else if (commands[0] == "open")
	{
		return Open;
	}
	
	//'CLOSE' COMMANDS
	else if (commands[0] == "close")
	{
		return Close;
	}

	//'PICK' COMMANDS
	else if (commands[0] == "pick")
	{
		return Pick;
	}

	//'DROP' COMMANDS
	else if (commands[0] == "drop")
	{
		return Drop;
	}

	//'HELP' COMMANDS
	else if (commands[0] == "help")
	{
		return Help;
	}

	//'QUIT' COMMANDS
	else if (commands[0] == "quit" || commands[0]=="q")
	{
		return Quit;
	}

	//'INVENTORY' COMMANDS
	else if (commands[0] == "i" || commands[0] == "inv" || commands[0] == "inventory")
	{
		return Inventory;
	}

	//'EQUIP' COMMAND
	else if (commands[0] == "equip")
	{
		return Equip;
	}

	//'UNEQUIP' COMMAND
	else if (commands[0] == "unequip")
	{
		return Unequip;
	}

	//'STATS' COMMANDS
	else if (commands[0] == "stats" || commands[0] == "st")
	{
		return Stats;
	}

	//'EQUIPMENT' COMMANDS
	else if (commands[0] == "equipment" || commands[0] == "eq")
	{
		return Equipment;
	}

	//'PUT' COMMANDS
	else if (commands[0] == "put" || commands[0] == "p")
	{
		return Put;
	}

	//'GET' COMMANDS
	else if (commands[0] == "get" || commands[0] == "g")
	{
		return Get;
	}

	//INVALID COMMAND
	else
	{
		return Invalid_command;
	}
}

int SetDirMove(const Vector<MyString>&commands)
{
	if (commands.size() == 2 && commands[0] == "go" && (commands[1] == "north" || commands[1] == "n") || commands[0] == "north" || commands[0] == "n")
	{
		return north;
	}
	else if (commands.size() == 2 && commands[0] == "go" && (commands[1] == "south" || commands[1] == "s") || commands[0] == "south" || commands[0] == "s")
	{
		return south;
	}
	else if (commands.size() == 2 && commands[0] == "go" && (commands[1] == "east" || commands[1] == "e") || commands[0] == "east" || commands[0] == "e")
	{
		return east;
	}
	else if (commands.size() == 2 && commands[0] == "go" && (commands[1] == "west" || commands[1] == "w") || commands[0] == "west" || commands[0] == "w")
	{
		return west;
	}
	else if (commands.size() == 2 && commands[0] == "go" && (commands[1] == "up" || commands[1] == "u") || commands[0] == "up" || commands[0] == "u")
	{
		return up;
	}
	else if (commands.size() == 2 && commands[0] == "go" && (commands[1] == "down" || commands[1] == "d") || commands[0] == "down" || commands[0] == "d")
	{
		return down;
	}
	else
	{
		return 10;
	}
}

int SetDirLook(const Vector<MyString>&commands)
{
	if (commands.size() == 2 && (commands[1] == "north" || commands[1] == "n"))
	{
		return north;
	}
	else if (commands.size() == 2 && (commands[1] == "south" || commands[1] == "s"))
	{
		return south;
	}

	else if (commands.size() == 2 && (commands[1] == "east" || commands[1] == "e"))
	{
		return east;
	}
	else if (commands.size() == 2 && (commands[1] == "west" || commands[1] == "w"))
	{
		return west;
	}
	else if (commands.size() == 2 && (commands[1] == "up" || commands[1] == "u"))
	{
		return up;
	}
	else if (commands.size() == 2 && (commands[1] == "down" || commands[1] == "d"))
	{
		return down;
	}
	else if (commands.size() == 2 && (commands[1] == "trunk"))
	{
		return 6;
	}
	else
	{
		return 10;
	}
}

int SetDirOpenClose(const Vector<MyString>&commands)
{
	if (commands.size() == 3 && (commands[1] == "north" || commands[1] == "n"))
	{
		return north;
	}
	else if (commands.size() == 3 && (commands[1] == "south" || commands[1] == "s"))
	{
		return south;
	}

	else if (commands.size() == 3 && (commands[1] == "east" || commands[1] == "e"))
	{
		return east;
	}
	else if (commands.size() == 3 && (commands[1] == "west" || commands[1] == "w"))
	{
		return west;
	}
	else if (commands.size() == 3 && (commands[1] == "up" || commands[1] == "u"))
	{
		return up;
	}
	else if (commands.size() == 3 && (commands[1] == "down" || commands[1] == "d"))
	{
		return down;
	}
	else
	{
		return 10;
	}
}