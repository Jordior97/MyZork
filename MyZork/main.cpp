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

		if (strcmp(option,"go") == 0 || strcmp(option, "n") == 0 || strcmp(option, "s") == 0 || strcmp(option, "e") == 0 || strcmp(option, "w") == 0 || strcmp(option, "u") == 0 || strcmp(option, "d") == 0
		|| strcmp(option, "north") == 0 || strcmp(option, "south") == 0 || strcmp(option, "east") == 0 || strcmp(option, "west") == 0 || strcmp(option, "up") == 0 || strcmp(option, "down") == 0 
		|| strcmp(option, "go north") == 0 || strcmp(option, "go south") == 0 || strcmp(option, "go east") == 0 || strcmp(option, "go west") == 0 || strcmp(option, "go up") == 0 || strcmp(option, "go down") == 0)
		{
			w.Movement(position,option);
		}

		else if (strcmp(option, "look") == 0 || strcmp(option, "look north") == 0 || strcmp(option, "look south") == 0 || strcmp(option, "look east") == 0 || strcmp(option, "look west") == 0 || strcmp(option, "look up") == 0 || strcmp(option, "look down") == 0)
		{
			w.Look(position,option);
		}

		else if (strcmp(option, "help") == 0)
		{
			w.Help();
		}

		else if (strcmp(option, "open door") == 0 || strcmp(option, "open north door") == 0 || strcmp(option, "open south door") == 0 || strcmp(option, "open east door") == 0 || strcmp(option, "open west door") == 0 || strcmp(option, "open up door") == 0 || strcmp(option, "open down door") == 0)
		{
			w.Open(position,option);
		}

		else if (strcmp(option, "close door") == 0 || strcmp(option, "close north door") == 0 || strcmp(option, "close south door") == 0 || strcmp(option, "close east door") == 0 || strcmp(option, "close west door") == 0 || strcmp(option, "close up door") == 0 || strcmp(option, "close down door") == 0)
		{
			w.Close(position, option);
		}


	} while (1);


	getchar();
	return 0;
}

