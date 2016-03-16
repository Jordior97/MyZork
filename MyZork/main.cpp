#include"world.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	char option[20];
	int position = 0; //Sets initial position to rooms[0](BEDROOM)

	World w;

	w.CreateWorld(); //Sets rooms and exits (names and descriptions)

	w.Help(); //An introduction to my game with a description and controls 

	do
	{
		fflush(stdin);
		printf("\n> ");
		gets_s(option, 20);

		//Goes to Movement Function Member
		if (GetCommand(option) >= go && GetCommand(option) <= go_down)
		{
			w.Movement(position, GetCommand(option));
		}

		//Goes to Look Function Member
		else if (GetCommand(option) >= look && GetCommand(option) <= look_down)
		{
			w.Look(position, GetCommand(option));
		}

		//Goes to Help Function Member
		else if (strcmp(option, "help") == 0)
		{
			w.Help();
		}

		//Goes to Open Function Member
		else if (GetCommand(option) >= open_door && GetCommand(option) <= open_down)
		{
			w.Open(position, GetCommand(option));
		}

		//Goes to Close Function Member
		else if (GetCommand(option) >= close_door && GetCommand(option) <= close_down)
		{
			w.Close(position, GetCommand(option));
		}

		//If a command introduced is not valid
		else if (GetCommand(option) == INVALID_COMMAND)
		{
			printf("\nInvalid command.\n");
		}

	} while (GetCommand(option)!= EXIT);


	return 0;
}

