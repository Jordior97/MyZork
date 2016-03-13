#include"world.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char option[20];
	int j=0;
	World w;

	w.CreateWorld();

	do
	{
		fflush(stdin);
		printf("What do you want to do? Move or Look?\n");
		gets_s(option, 20);
		if (strcmp(option, "move") == 0)
		{
			w.Movement(&j);
		}
		else if (strcmp(option, "look") == 0)
		{
			w.Look(j);
		}
		else
		{
			printf("Error.\n");
		}
		
	} while (option != "quit");

	getchar();
	return 0;
}