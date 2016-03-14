#include"world.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char option[20];
	//int room_num = 0; //Sets initial position to rooms[0] (BEDROOM)
	char option_move;
	int position = 0;

	World w;

	w.CreateWorld();



	do
	{
		fflush(stdin);
		printf("Which direction do you want to move?");
		scanf_s("%c", &option_move);
		w.Movement(option_move, position);
		getchar();

	} while (strcmp(option, "quit") != 0);


	getchar();
	return 0;
}

