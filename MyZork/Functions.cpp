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

		world->player->Movement(commands);
		return Movement;
	}

	//'LOOK' COMMANDS
	else if (commands[0] == "look")
	{
		world->player->Look( commands);
		return Look;
	}
	
	//'OPEN' COMMANDS
	else if (commands[0] == "open")
	{
		world->player->Open(commands);
		return Open;
	}
	
	//'CLOSE' COMMANDS
	else if (commands[0] == "close")
	{
		world->player->Close( commands);
		return Close;
	}

	//'PICK' COMMANDS
	else if (commands[0] == "pick")
	{
		world->player->Pick(commands);
		return Pick;
	}

	//'DROP' COMMANDS
	else if (commands[0] == "drop")
	{
		world->player->Drop(commands);
		return Drop;
	}

	//'HELP' COMMANDS
	else if (commands[0] == "help")
	{
		world->Help();
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
		world->player->Inventory();
		return Inventory;
	}

	//'EQUIP' COMMAND
	else if (commands[0] == "equip")
	{
		world->player->Equip(commands);
		return Equip;
	}

	//'UNEQUIP' COMMAND
	else if (commands[0] == "unequip")
	{
		world->player->Unequip(commands);
		return Unequip;
	}

	//'STATS' COMMANDS
	else if (commands[0] == "stats" || commands[0] == "st")
	{
		world->player->Stats();
		return Stats;
	}

	//'EQUIPMENT' COMMANDS
	else if (commands[0] == "equipment" || commands[0] == "eq")
	{
		world->player->Equipment();
		return Equipment;
	}

	//'PUT' COMMANDS
	else if (commands[0] == "put" || commands[0] == "p")
	{
		world->player->Put(commands);
		return Put;
	}

	//'GET' COMMANDS
	else if (commands[0] == "get" || commands[0] == "g")
	{
		world->player->Get(commands);
		return Get;
	}

	//'BUY' COMMANDS
	else if (commands.size() == 2 && commands[0] == "buy")
	{
		world->player->Buy(commands);
		return Buy;
	}

	//'BUY FROM' COMMANDS
	else if (commands.size() == 4 && commands[0] == "buy" && commands[2] == "from")
	{
		world->player->BuyFrom(commands);
		return BuyFrom;
	}

	//'SELL TO' COMMANDS
	else if (commands[0] == "sell")
	{
		world->player->SellTo(commands);
		return SellTo;
	}

	//'ATTACK' COMMANDS
	else if (commands[0] == "attack" || commands[0] == "a")
	{
		world->player->Attack(commands);
		return Attack;
	}

	//'SPELLS' COMMANDS
	else if (commands[0] == "1" || commands[0] == "2" || commands[0] == "3"
		|| commands[0] == "4" || commands[0] == "5")
	{
		world->player->Gem_Abilities(commands);
		return Spells;
	}

	//'HEAL' COMMANDS
	else if (commands[0] == "heal" || commands[0] == "h")
	{
		world->player->Heal(commands);
		return Heal;
	}

	//'MANA' COMMANDS
	else if (commands[0] == "mana" || commands[0] == "m")
	{
		world->player->Mana(commands);
		return Mana;
	}

	//'GOD MODE' HEAL
	else if (commands[0] == "/heal")
	{
		world->player->g_Heal(commands);
		return G_Heal;
	}

	//'GOD MODE' MANA
	else if (commands[0] == "/mana")
	{
		world->player->g_Mana(commands);
		return G_Mana;
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