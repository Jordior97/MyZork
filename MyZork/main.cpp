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
		printf("> ");
		gets_s(option, 20);

		if (strcmp(option, "move") == 0)
		{
			w.Movement(position);
		}
		else if (strcmp(option, "look") == 0)
		{
			w.Look(position);
		}

		getchar();

	} while (1);


	getchar();
	return 0;
}

