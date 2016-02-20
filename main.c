//Jordi Oña
/* Write a program that allows you to move around a house:
● “Which direction you want to go (n/s/e/w/q) ?
● Rooms:
○ Center: dinning room
○ north of dinning room: kitchen
○ east of dinning room: bathroom
○ south of dinning room: bedroom
○ east of kitchen: pantry */

#include<stdio.h>
#include"rooms.h"

int main()
{
	char dir;
	int *position;
	int i = 1;
	int j = 0;
	char *rooms[3][2] = 
	{ 
		{ "Kitchen", "Pantry" }, 
		{ "Dinning Room", "Bathroom" }, 
		{ "Bedroom"," "} 
	};

	do{
		system("cls");
		printf("THE ROOMS\n\n");
		printf("You are in %s.\n", *(*(rooms + i) + j));
		printf("Which direction do you want to go (n/s/e/w/q)?");
		fflush(stdin);
		scanf_s("%c", &dir);
		move(dir, &i,&j);
	} while (dir != 'q');

	
	getchar();
	return 0;
}