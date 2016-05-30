#include"MagicSpells.h"
#include"player.h"
#include"world.h"
#include"creature.h"

void HotSteam()
{
	printf("HOT STEAM! It deals 30 points of damage to %s\nand you gain 40 mana points.\n", world->player->enemy->name.c_str());
	world->player->enemy->hp -= 30;
	if (world->player->enemy->hp < 0)
	{
		world->player->enemy->hp = 0;
	}
	world->player->mana += 40;
	printf("\n%s have %i hp.\n", world->player->enemy->name.c_str(), world->player->enemy->hp);
	printf("You have %i mana points.\n", world->player->mana);

}

void ElectricStorm()
{
	printf("ELECTRIC STORM! The attack speed of %s increased,\nbut his damage is decreased.\n", world->player->enemy->name.c_str());
	world->player->enemy->at_delay -= 500;
	world->player->enemy->attack -= 20;
}

void DarkFire()
{
	printf("DARK FIRE! You consumed 100 hp\nto cause %s 200 points of damage.\n", world->player->enemy->name.c_str());
	world->player->hp -= 100;
	world->player->enemy->hp -= 200;
	if (world->player->enemy->hp < 0)
	{
		world->player->enemy->hp = 0;
	}
	printf("Your hp is %i now.\n", world->player->hp);
	printf("\n%s have %i hp.\n", world->player->enemy->name.c_str(), world->player->enemy->hp);
}

void VoidSpear()
{
	printf("VOID SPEAR! Your life is reduced 100 hp to increase your attack damage.\n");
	world->player->hp -= 100;
	if (world->player->enemy->hp < 0)
	{
		world->player->enemy->hp = 0;
	}
	world->player->attack += 60;
	printf("Your hp is %i now.\n", world->player->hp);
}

void DivineStrike()
{
	printf("DIVINE STRIKE!\n An expansive wave increased your armor by 50\nand caused 50 damage points to %s", world->player->enemy->name.c_str());
	world->player->armor += 50;
	world->player->enemy->hp -= 50;
	if (world->player->enemy->hp < 0)
	{
		world->player->enemy->hp = 0;
	}
	printf("\n%s have %i hp.\n", world->player->enemy->name.c_str(), world->player->enemy->hp);
}


void Fire(const Vector<MyString>& commands, bool red, bool blue, bool black)
{
	if (red == true)
	{
		if (commands.size() == 1)
		{
			printf("FIRE! You caused 30 points of damage to %s\n", world->player->enemy->name.c_str());
			world->player->enemy->hp -= 30;
			if (world->player->enemy->hp < 0)
			{
				world->player->enemy->hp = 0;
			}
			printf("%s have %i hp.\n", world->player->enemy->name.c_str(), world->player->enemy->hp);
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
			printf("WATER! You reduced the attack speed of %s.\n", world->player->enemy->name.c_str());
			world->player->enemy->at_delay += 500;
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
			printf("ELECTRICITY! You reduced the armor of %s\n", world->player->enemy->name.c_str());
			world->player->enemy->armor -= 20;
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
		printf("You don't have KIIRO in your inventory.\n");
	}
}

void Darkness(const Vector<MyString>& commands, bool black, bool red, bool white)
{
	if (black == true)
	{
		if (commands.size() == 1)
		{
			printf("DARKNESS! You lifestealed 30 hp from %s, but his damage is increased\n",world->player->enemy->name.c_str());
			world->player->enemy->hp -= 30;
			world->player->hp += 30;
			world->player->enemy->attack += 20;
			if (world->player->enemy->hp < 0)
			{
				world->player->enemy->hp = 0;
			}
			printf("%s have %i hp.\n", world->player->enemy->name.c_str(), world->player->enemy->hp);
			printf("Your hp is %i now.\n", world->player->hp);

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
				VoidSpear();
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
			printf("BRIGHTNESS! Your armor increased by 20.\n");
			world->player->armor += 20;
		}
		else if (commands.size() == 2 && commands[1] == "4")
		{
			if (black == true)
			{
				VoidSpear();
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
