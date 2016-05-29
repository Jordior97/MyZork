#include"MagicSpells.h"

void HotSteam(const Vector<MyString>& commands)
{
	printf("HOT STEAM!\n");
}

void ElectricStorm(const Vector<MyString>& commands)
{
	printf("ELECTRIC STORM!\n");
}

void DarkFire(const Vector<MyString>& commands)
{
	printf("DARK FIRE!\n");
}


void Nothing(const Vector<MyString>& commands)
{
	printf("NOTHING!\n");
}

void DivineStrike(const Vector<MyString>& commands)
{
	printf("DIVINE STRIKE!\n");
}


void Fire(const Vector<MyString>& commands)
{
	if (commands.size() == 1)
	{
		printf("FIRE!\n");
	}
	else if (commands.size() == 2 && commands[1] == "2")
	{
		HotSteam(commands);
	}
	else if (commands.size() == 2 && commands[1] == "4")
	{
		DarkFire(commands);
	}
}

void Water(const Vector<MyString>& commands)
{
	if (commands.size() == 1)
	{
		printf("WATER!\n");
	}
	else if (commands.size() == 2 && commands[1] == "1")
	{
		HotSteam(commands);
	}
	else if (commands.size() == 2 && commands[1] == "3")
	{
		ElectricStorm(commands);
	}
}

void Electricity(const Vector<MyString>& commands)
{
	if (commands.size() == 1)
	{
		printf("ELECTRICITY!\n");
	}
	else if (commands.size() == 2 && commands[1] == "2")
	{
		ElectricStorm(commands);
	}
	else if (commands.size() == 2 && commands[1] == "5")
	{
		DivineStrike(commands);
	}
}

void Darkness(const Vector<MyString>& commands)
{
	if (commands.size() == 1)
	{
		printf("DARKNESS!\n");
	}
	else if (commands.size() == 2 && commands[1] == "1")
	{
		DarkFire(commands);
	}
	else if (commands.size() == 2 && commands[1] == "5")
	{
		Nothing(commands);
	}
}

void Brightness(const Vector<MyString>& commands)
{
	if (commands.size() == 1)
	{
		printf("BRIGHTNESS!\n");
	}
	else if (commands.size() == 2 && commands[1] == "4")
	{
		Nothing(commands);
	}
	else if (commands.size() == 2 && commands[1] == "3")
	{
		DivineStrike(commands);
	}
}
