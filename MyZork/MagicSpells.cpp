#include"MagicSpells.h"
#include"player.h"
#include"world.h"
#include"creature.h"

void HotSteam()
{
	if (world->player->mana >= 30)
	{
		world->player->mana -= 30;
		printf("HOT STEAM! It deals 50 points of damage to %s\nand you gain 40 mana points.\n", world->player->enemy->name.c_str());
		world->player->enemy->hp -= 50;
		if (world->player->enemy->hp < 0)
		{
			world->player->enemy->hp = 0;
		}
		world->player->mana += 170;
		printf("\n%s have %i hp.\n", world->player->enemy->name.c_str(), world->player->enemy->hp);
		printf("You have %i mana points.\n", world->player->mana);
	}
	else
	{
		printf("YOU HAVEN'T GOT ENOUGH MANA.\n");
	}

}

void ElectricStorm()
{
	if (world->player->mana >= 20)
	{
		if (world->player->enemy->attack > 10)
		{
			world->player->mana -= 20;
			printf("ELECTRIC STORM! The attack speed of %s increased,\nbut his damage is decreased.\n", world->player->enemy->name.c_str());
			world->player->enemy->at_delay -= 200;
			world->player->enemy->attack -= 10;
			printf("You have %i mana points.\n", world->player->mana);
		}
		else
		{
			printf("ELECTRIC STORM! You can't cast this ability on %s at the moment.\n", world->player->enemy->name.c_str());
		}
	}
	else
	{
		printf("YOU HAVEN'T GOT ENOUGH MANA.\n");
	}
}

void DarkFire()
{
	if (world->player->mana >= 40)
	{
		world->player->mana -= 40;
		printf("DARK FIRE! You consumed 100 hp\nto cause %s 200 points of damage.\n", world->player->enemy->name.c_str());
		world->player->hp -= 100;
		world->player->enemy->hp -= 200;
		if (world->player->enemy->hp < 0)
		{
			world->player->enemy->hp = 0;
		}
		printf(">> Your hp is %i now.\n", world->player->hp);
		printf("%s have %i hp.\n", world->player->enemy->name.c_str(), world->player->enemy->hp);
		printf("You have %i mana points.\n", world->player->mana);
	}
	else
	{
		printf("YOU HAVEN'T GOT ENOUGH MANA.\n");
	}
}

void VoidSpear()
{
	if (world->player->mana >= 30)
	{
		world->player->mana -= 30;
		printf("VOID SPEAR! Your life is reduced 100 hp to increase your attack damage.\n");
		world->player->hp -= 100;
		world->player->attack += 60;
		printf(">> Your hp is %i now.\n", world->player->hp);
		printf("You have %i mana points.\n", world->player->mana);
	}
	else
	{
		printf("YOU HAVEN'T GOT ENOUGH MANA.\n");
	}
}

void DivineStrike()
{
	if (world->player->mana >= 20)
	{
		world->player->mana -= 20;
		printf("DIVINE STRIKE!\n An expansive wave increased your armor by 50\nand caused 50 damage points to %s", world->player->enemy->name.c_str());
		world->player->armor += 50;
		world->player->enemy->hp -= 50;
		if (world->player->enemy->hp < 0)
		{
			world->player->enemy->hp = 0;
		}
		printf("\n%s have %i hp.\n", world->player->enemy->name.c_str(), world->player->enemy->hp);
		printf("You have %i mana points.\n", world->player->mana);
	}
	else
	{
		printf("YOU HAVEN'T GOT ENOUGH MANA.\n");
	}
}


void Fire(const Vector<MyString>& commands, bool red, bool blue, bool black)
{
	if (red == true)
	{
		if (commands.size() == 1)
		{
			if (world->player->mana >= 10)
			{
				world->player->mana -= 10;
				printf("FIRE! You caused 30 points of damage to %s\n", world->player->enemy->name.c_str());
				world->player->enemy->hp -= 30;
				if (world->player->enemy->hp < 0)
				{
					world->player->enemy->hp = 0;
				}
				printf("%s have %i hp.\n", world->player->enemy->name.c_str(), world->player->enemy->hp);
				printf("You have %i mana points.\n", world->player->mana);
			}
			else
			{
				printf("YOU HAVEN'T GOT ENOUGH MANA.\n");
			}
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
			if (world->player->mana >= 20)
			{
				world->player->mana -= 20;
				printf("WATER! You reduced the attack speed of %s.\n", world->player->enemy->name.c_str());
				world->player->enemy->at_delay += 200;
				printf("You have %i mana points.\n", world->player->mana);
			}
			else
			{
				printf("YOU HAVEN'T GOT ENOUGH MANA.\n");
			}
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
			if (world->player->mana >= 10)
			{
				world->player->mana -= 10;
				if (world->player->enemy->armor > 0)
				{
					printf("ELECTRICITY! You reduced the armor of %s\n", world->player->enemy->name.c_str());
					world->player->enemy->armor -= 20;
					printf("You have %i mana points.\n", world->player->mana);
				}
				else
				{
					world->player->enemy->armor = 0;
					printf("ELECTRICITY! You CAN'T REDUCE the armor of %s because it's already 0.\n", world->player->enemy->name.c_str());
					printf("You have %i mana points.\n", world->player->mana);
				}		
			}
			else
			{
				printf("YOU HAVEN'T GOT ENOUGH MANA.\n");
			}
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
			if (world->player->mana >= 20)
			{
				world->player->mana -= 20;
				printf("DARKNESS! You lifestealed 50 hp from %s, but his damage is increased\n", world->player->enemy->name.c_str());
				world->player->enemy->hp -= 50;
				world->player->hp += 50;
				world->player->enemy->attack += 20;
				if (world->player->enemy->hp < 0)
				{
					world->player->enemy->hp = 0;
				}
				printf("%s have %i hp.\n", world->player->enemy->name.c_str(), world->player->enemy->hp);
				printf(">> Your hp is %i now.\n", world->player->hp);
				printf("You have %i mana points.\n", world->player->mana);
			}
			else
			{
				printf("YOU HAVEN'T GOT ENOUGH MANA.\n");
			}

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
			if (world->player->mana >= 10)
			{
				world->player->mana -= 10;
				printf("BRIGHTNESS! Your armor increased by 20.\n");
				world->player->armor += 20;
				printf("You have %i mana points.\n", world->player->mana);
			}
			else
			{
				printf("YOU HAVEN'T GOT ENOUGH MANA.\n");
			}
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
