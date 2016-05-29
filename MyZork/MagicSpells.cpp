#include"MagicSpells.h"
#include"player.h"
#include"world.h"

void HotSteam()
{
	printf("HOT STEAM!\n");
}

void ElectricStorm()
{
	printf("ELECTRIC STORM!\n");
}

void DarkFire()
{
	printf("DARK FIRE!\n");
}


void Nothing()
{
	printf("NOTHING!\n");
}

void DivineStrike()
{
	printf("DIVINE STRIKE!\n");
}


void Fire(const Vector<MyString>& commands, bool red, bool blue, bool black)
{
	if (red == true)
	{
		if (commands.size() == 1)
		{
			printf("FIRE!\n");
		}
		else if (commands.size() == 2 && commands[1] == "2")
		{
			if (blue == true)
			{
				HotSteam();
			}
			else
			{
				printf("You need AO to cast this spell.\n");
			}
		}
		else if (commands.size() == 2 && commands[1] == "4")
		{
			if (black == true)
			{
				DarkFire();
			}
			else
			{
				printf("You need KURO to cast this spell.\n");
			}
		}
	}
	else
	{
		printf("You don't have AKA in your inventory.\n");
	}
}

void Water(const Vector<MyString>& commands, bool blue, bool red, bool yellow)
{
	if (blue == true)
	{
		if (commands.size() == 1)
		{
			printf("WATER!\n");
		}
		else if (commands.size() == 2 && commands[1] == "1")
		{
			if (red == true)
			{
				HotSteam();
			}
			else
			{
				printf("You need AKA to cast this spell.\n");
			}
		}
		else if (commands.size() == 2 && commands[1] == "3")
		{
			if (yellow == true)
			{
				ElectricStorm();
			}
			else
			{
				printf("You need KIIRO to cast this spell.\n");
			}
		}
	}
	else
	{
		printf("You don't have AO in your inventory.\n");
	}
}

void Electricity(const Vector<MyString>& commands, bool yellow, bool blue, bool white)
{
	if (yellow == true)
	{
		if (commands.size() == 1)
		{
			printf("ELECTRICITY!\n");
		}
		else if (commands.size() == 2 && commands[1] == "2")
		{
			if (blue == true)
			{
				ElectricStorm();
			}
			else
			{
				printf("You need AO to cast this spell.\n");
			}
		}
		else if (commands.size() == 2 && commands[1] == "5")
		{
			if (white == true)
			{
				ElectricStorm();
			}
			else
			{
				printf("You need SHIRO to cast this spell.\n");
			}
		}
	}
	else
	{
		printf("You don't have KIIRO in your inventory.\n");
	}
}

void Darkness(const Vector<MyString>& commands, bool black, bool red, bool white)
{
	if (black == true)
	{
		if (commands.size() == 1)
		{
			printf("DARKNESS!\n");
		}
		else if (commands.size() == 2 && commands[1] == "1")
		{
			if (red == true)
			{
				DarkFire();
			}
			else
			{
				printf("You need AKA to cast this spell.\n");
			}
		}
		else if (commands.size() == 2 && commands[1] == "5")
		{
			if (white == true)
			{
				Nothing();
			}
			else
			{
				printf("You need SHIRO to cast this spell.\n");
			}
		}
	}
	else
	{
		printf("You don't have KURO in your inventory.\n");
	}
}

void Brightness(const Vector<MyString>& commands, bool white, bool black, bool yellow)
{
	if (white == true)
	{
		if (commands.size() == 1)
		{
			printf("BRIGHTNESS!\n");
		}
		else if (commands.size() == 2 && commands[1] == "4")
		{
			if (black == true)
			{
				Nothing();
			}
			else
			{
				printf("You need KURO to cast this spell.\n");
			}
		}
		else if (commands.size() == 2 && commands[1] == "3")
		{
			if (yellow == true)
			{
				DivineStrike();
			}
			else
			{
				printf("You need SHIRO to cast this spell.\n");
			}
		}
	}
	else
	{
		printf("You don't have SHIRO in your inventory.\n");
	}
}
