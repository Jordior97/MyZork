#include"world.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	bool quit =false; //variable used to quit the game
	World w;

	w.CreateWorld(); //Sets rooms exits and items (names, descriptions and other properties)

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
			//Splits the command introduced to check the different words it contains
			Vector<MyString> commands = option.SplitString(" ", command); 


			//To move between the rooms of the map
			if (GetCommand(commands) == Movement)
			{
				w.Movement(position, commands);
			}

			//To look the rooms, exits and objects
			else if (GetCommand(commands) == Look)
			{
				w.Look(position, commands);
			}

			//To open doors
			else if (GetCommand(commands) == Open)
			{
				w.Open(position, commands);
			}

			//To close doors
			else if (GetCommand(commands) == Close)
			{
				w.Close(position, commands);
			}

			//To pick items that are in the actual room
			else if (GetCommand(commands) == Pick)
			{
				w.Pick(commands);
			}

			//To leave items in the actual room
			else if (GetCommand(commands) == Drop)
			{
				w.Drop(commands);
			}

			//It shows the instructions and a brief description of the game
			else if (GetCommand(commands) == Help)
			{
				w.Help();
			}

			//If the player introduces an incorrect command
			else if (GetCommand(commands) == Invalid_command)
			{
				printf("Invalid command\n");
			}

			//To exit the game
			else if (GetCommand(commands) == Quit)
			{
				quit = true;
			}

			//To look the items in the inventory
			else if (GetCommand(commands) == Inventory)
			{
				w.Inventory();
			}

			//To equip items the player has picked
			else if (GetCommand(commands) == Equip)
			{
				w.Equip(commands);
			}

			//To unequip items the player has equipped 
			else if (GetCommand(commands) == Unequip)
			{
				w.Unequip(commands);
			}

			//To look the stats of the payer
			else if (GetCommand(commands) == Stats)
			{
				w.player->Stats();
			}

			//To look items equipped
			else if (GetCommand(commands) == Equipment)
			{
				w.Equipment();
			}

			//To put items inside other items
			else if (GetCommand(commands) == Put)
			{
				w.Put(commands);
			}

			//To get items that are inside other items
			else if (GetCommand(commands) == Get)
			{
				w.Get(commands);
			}
		}

	} while (quit == false);

	return 0;
}

