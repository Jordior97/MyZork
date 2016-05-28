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
	(Room*)world->player->location = (Room*)world->entities[position];

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
					if (size > 1)
					{
						size--;
						size--;
					}
					else
					{
						size--;
					}
				}

				if (command[size - 1] == '\r')
				{
					printf("\n\n");
					command[size - 1] = '\0';
					size = 0;
					option = command;

					//Splits the command introduced to check the different words it contains
					Vector<MyString> commands = option.SplitString(" ", command);

					if (command[0] != NULL && command[0] != ' ' && command[0] != '\b')
					{

						int Action = GetCommand(position, commands);
						//If the player introduces an incorrect command
						if (Action == Invalid_command)
						{
							printf("You have to be more accurate telling what you want to do.\n");
						}

						//To exit the game
						else if (Action == Quit)
						{
							quit = true;
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

