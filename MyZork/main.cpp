#include"world.h"
#include"MemLeaks.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<conio.h>

#define BUFFER 70
typedef unsigned int uint;

World* world = nullptr;

int main()
{
	uint init_time = 0;
	uint current_time = 0;
	uint size = 0;
	char input = 0;

	init_time = GetTickCount();

	ReportMemoryLeaks();
	bool quit =false; //variable used to quit the game

	world = new World;

	world->CreateWorld(); //Sets rooms exits and items (names, descriptions and other properties)

	world->Help(); //An introduction to my game with a description and controls 

	MyString option;
	char command[BUFFER];

	//Sets initial position to rooms[0](BEDROOM)
	int position = 0; 
	(Room*)world->player->player_pos = (Room*)world->entities[position];

	do
	{
		current_time = GetTickCount();
		fflush(stdin);
		if (_kbhit())
		{
			if (size < BUFFER - 2)
			{
				input = _getch();
				command[size++] = input;
				printf("%c", input);

				if (command[size - 1] == '\b')
				{
					if (size > 0)
					{
						size--;
						size--;
					}
				}

				if (command[size - 1] == '\r')
				{
					printf("\n");
					command[size - 1] = '\0';
					size = 0;
					option = command;

					//Splits the command introduced to check the different words it contains
					Vector<MyString> commands = option.SplitString(" ", command);

					if (command[0] != NULL && command[0] != ' ')
					{
						//To move between the rooms of the map
						if (GetCommand(commands) == Movement)
						{
							world->player->Movement(position, commands);
						}

						//To look the rooms, exits and objects
						else if (GetCommand(commands) == Look)
						{
							world->Look(position, commands);
						}

						//To open doors
						else if (GetCommand(commands) == Open)
						{
							world->Open(position, commands);
						}

						//To close doors
						else if (GetCommand(commands) == Close)
						{
							world->Close(position, commands);
						}

						//To pick items that are in the actual room
						else if (GetCommand(commands) == Pick)
						{
							world->player->Pick(commands);
						}

						//To leave items in the actual room
						else if (GetCommand(commands) == Drop)
						{
							world->player->Drop(commands);
						}

						//It shows the instructions and a brief description of the game
						else if (GetCommand(commands) == Help)
						{
							world->Help();
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
							world->Inventory();
						}

						//To equip items the player has picked
						else if (GetCommand(commands) == Equip)
						{
							world->Equip(commands);
						}

						//To unequip items the player has equipped 
						else if (GetCommand(commands) == Unequip)
						{
							world->Unequip(commands);
						}

						//To look the stats of the payer
						else if (GetCommand(commands) == Stats)
						{
							world->player->Stats();
						}

						//To look items equipped
						else if (GetCommand(commands) == Equipment)
						{
							world->Equipment();
						}

						//To put items inside other items
						else if (GetCommand(commands) == Put)
						{
							world->player->Put(commands);
						}

						//To get items that are inside other items
						else if (GetCommand(commands) == Get)
						{
							world->player->Get(commands);
						}
					}
				}
			}
			else
			{
				command[size - 1] = '\0';
				size = 0;
			}

		}

	} while (quit == false);

	return 0;
}

