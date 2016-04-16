#include"world.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	int opt;
	World w;

	w.CreateWorld(); //Sets rooms and exits (names and descriptions)

	w.Help(); //An introduction to my game with a description and controls 

	MyString option;
	char command[70];
	int position = 0; //Sets initial position to rooms[0](BEDROOM)

	do
	{
		fflush(stdin);
		printf("\n> ");
		gets_s(command, 70);
		if (command[0] != NULL && command[0] != ' ')
		{
			Vector<MyString> commands = option.SplitString(" ", command);


			//Goes to Movement Function Member
			if (GetCommand(commands) == Movement)
			{
				w.Movement(position, commands);
			}

			//Goes to Look Function Member
			else if (GetCommand(commands) == Look)
			{
				w.Look(position, commands);
			}

			//Goes to Open Function Member
			else if (GetCommand(commands) == Open)
			{
				w.Open(position, commands);
			}

			//Goes to Close Function Member
			else if (GetCommand(commands) == Close)
			{
				w.Close(position, commands);
			}

			//Goes to Pick Function Member
			else if (GetCommand(commands) == Pick)
			{
				w.Pick(commands);
			}

			//Goes to Close Function Member
			else if (GetCommand(commands) == Drop)
			{
				w.Drop(commands);
			}

			else if (GetCommand(commands) == Help)
			{
				w.Help();
			}

			else if (GetCommand(commands) == Invalid_command)
			{
				printf("Invalid command\n");
			}

			else if (GetCommand(commands) == Quit)
			{
				opt = 1;
			}

			else if (GetCommand(commands) == Inventory)
			{
				w.Inventory();
			}

			else if (GetCommand(commands) == Equip)
			{
				w.Equip(commands);
			}

			else if (GetCommand(commands) == Unequip)
			{
				w.Unequip(commands);
			}

			else if (GetCommand(commands) == Stats)
			{
				w.player->Stats();
			}

			else if (GetCommand(commands) == Equipment)
			{
				w.Equipment();
			}
		}

	} while (opt != 1);

	return 0;
}

