#include"world.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	char option[20];
	int position = 0; //Sets initial position to rooms[0](BEDROOM)

	World w;

	w.CreateWorld();


	do
	{
		fflush(stdin);
		printf("\n> ");
		gets_s(option, 20);


		if (GetCommand(option) == go || GetCommand(option) == go_north || GetCommand(option) == go_south || GetCommand(option) == go_east || GetCommand(option) == go_west || GetCommand(option) == go_up || GetCommand(option) == go_down)
		{
			w.Movement(position, GetCommand(option));
		}

		else if (GetCommand(option) == look || GetCommand(option) == look_north || GetCommand(option) == look_south || GetCommand(option) == look_east || GetCommand(option) == look_west || GetCommand(option) == look_up || GetCommand(option) == look_down)
		{
			w.Look(position, GetCommand(option));
		}

		else if (strcmp(option, "help") == 0)
		{
			w.Help();
		}

		else if (GetCommand(option) == open_door || GetCommand(option) == open_north || GetCommand(option) == open_south || GetCommand(option) == open_east || GetCommand(option) == open_west || GetCommand(option) == open_up || GetCommand(option) == open_down)
		{
			w.Open(position, GetCommand(option));
		}

		else if (GetCommand(option) == close_door || GetCommand(option) == close_north || GetCommand(option) == close_south || GetCommand(option) == close_east || GetCommand(option) == close_west || GetCommand(option) == close_up || GetCommand(option) == close_down)
		{
			w.Close(position, GetCommand(option));
		}
		else if (GetCommand(option) == 100)
		{
			printf("Invalid command.\n");
		}


	} while (GetCommand(option)!= EXIT);


	return 0;
}

