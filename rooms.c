#include<stdio.h>
#include"rooms.h"

void move(char dir, int *i, int *j)
{
	switch (dir)
	{
		case'n':
		{
			if (*i == 1 && *j == 1)
			{
				printf("You can't go that way.");
				getchar();
				getchar();
				break;
			}

			(*i)--;

			if (*i < 0)
			{
				printf("You can't go that way.");
				(*i)++;
				getchar();
				getchar();
			}
		
			break;
		}
		case's':
		{
			if (*i == 0 && *j == 1)
			{
				printf("You can't go that way.");
				(*i)--;
				getchar();
				getchar();
			}

			(*i)++;

			if (*i > 2)
			{
				printf("You can't go that way.");
				(*i)--;
				getchar();
				getchar();
			}
			else if (*i > 1 && *j > 0)
			{
				printf("You can't go that way.");
				(*i)--;
				getchar();
				getchar();
			}
		
			break;
		}
		case'e':
		{
			(*j)++;
			if (*j > 1)
			{
				printf("You can't go that way.");
				(*j)--;
				getchar();
				getchar();
			}
			else if (*i > 1 && *j > 0)
			{
				printf("You can't go that way.");
				(*j)--;
				getchar();
				getchar();
			}
			break;
		}
		case'w':
		{
			(*j)--;
			if (*j <0)
			{
				printf("You can't go that way.");
				(*j)++;
				getchar();
				getchar();
			}
			break;
		}
		case 'q':
		{
			return 0;
		}
		default:
		{
			printf("Choose a valid option (Press enter to continue).");
			getchar();
			getchar();
			break;
		}
	}
}
