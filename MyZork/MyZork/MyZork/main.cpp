#include"world.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char direction=0;
	int j=0;
	World w;

	w.CreateWorld();

	do
	{
		fflush(stdin);
		printf("Which direction do you want to move?(n/s/e/w/u/d)");
		scanf_s("%c", &direction);
		w.Movement(direction,&j);
		getchar();
	} while (direction != 'q');

	getchar();
	return 0;
}