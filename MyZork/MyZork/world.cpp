#include"world.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NUM_ROOMS 13
#define NUM_EXITS 19

World::World()
{
	rooms = new Room[NUM_ROOMS];
	player = new Player;
	exits = new Exit[NUM_EXITS];
}

void World::CreateWorld() const
{
	int  i;
	//ROOMS: NAMES and DESCRIPTIONS
	char *names[] = { "BEDROOM", "GRIMGAR", "TAVERN", "LAKE", "CLIFF", "SUPER GENERATOR", "PORTAL ROOM", "UNDERWATER CAVE", "DRAGON CHAMBER", "FLOOR 1", "FLOOR 2", "TREASURE CHAMBER", "RAKDOS THRONE ROOM" };
	for (i = 0; i < NUM_ROOMS; i++)
	{
	strcpy_s((rooms+i)->name, names[i]);
	}
	/*
	for (i = 0; i < 13; i++)
	{
		printf("%i) %s\n", i, (rooms + i)->name);
	}*/

char *descriptions[] =
{
	"This is my room, what a mess.\nI can hear a very strange noise coming from under my bed.\nI should take a look.\n",
	"We are in Grimgar, Simon.\nIt's the capital city of Aincrad, this beautiful fantasy world.\n",
	"In this tavern we can buy new items and weapons to improve our abilities.\n",
	"What an enormous lake!\nIt's a nice day to take a dip.\nIf you stare at the bottom you can see a small grotto.\n",
	"This is the highest hill in the city.\nYou can see everything wonderful about Aincrad from up here, and the Tower of Rakdos, the Devil King...\n",
	"We are at the entrance of Rakdos Tower, the hell...\nNext to it the Super Generator is installed.\nThis huge device is the responsible for providing all the energy of the city.\n",
	"We have entered in a magical Room.\nCan you see the big Portal with a very strange inscriptions?\nIf you jump into it you can teleport to another place.\n",
	"Echo, echo, echo ...\nWe have to care if we want to leave this cave alive.\nIt's a very big and deep cave, so we will have to defeat powerful enemies if you want to continue.\n",
	"It's very hot here...Wait!\nThis is the Dragon chamber.\nWe have to leave quickly before the Dragon returns.\n",
	"This is the first floor of the tower.\nScary monsters and skeletons can appear, so let's fight them!\nWe have to care, some trapps have been scatteret throughout the building.\n",
	"Good Job, Simon! We have reached the second floor.\nIt's a big room with some inscriptions on the walls.\n",
	"Yeah! Simon, this is the final room before the ultimate battle.\nThere is a key on the ground, and seems to fit the lock of these two big chests in front of us.\n",
	"What a big chamber!\nSimon, Rakdos is there, let's fight and defeat him!\n" };

for (i = 0; i < NUM_ROOMS; i++)
{
	strcpy_s((rooms + i)->description, descriptions[i]);
}
/*
for (i = 0; i < 13; i++)
{
	printf("%i) %s\n\n", i, (rooms + i)->description);
}*/

/*
//CARDINAL POINTS OF ROOMS
//Bedroom
strcpy_s((rooms + 0)->north, "-");
strcpy_s((rooms + 0)->south, "-");
strcpy_s((rooms + 0)->east, "-");
strcpy_s((rooms + 0)->west, "-");
strcpy_s((rooms + 0)->up, "-");
strcpy_s((rooms + 0)->down, names[1]);

//Grimgar
strcpy_s((rooms + 1)->north, names[4]);
strcpy_s((rooms + 1)->south, "-");
strcpy_s((rooms + 1)->east, names[2]);
strcpy_s((rooms + 1)->west, names[3]);
strcpy_s((rooms + 1)->up, "-");
strcpy_s((rooms + 1)->down, "-");

//Tavern
strcpy_s((rooms + 2)->north, "-");
strcpy_s((rooms + 2)->south, "-");
strcpy_s((rooms + 2)->east, "-");
strcpy_s((rooms + 2)->west, names[1]);
strcpy_s((rooms + 2)->up, "-");
strcpy_s((rooms + 2)->down, "-");

//Lake
strcpy_s((rooms + 3)->north, "-");
strcpy_s((rooms + 3)->south, "-");
strcpy_s((rooms + 3)->east, names[1]);
strcpy_s((rooms + 3)->west, "-");
strcpy_s((rooms + 3)->up, "-");
strcpy_s((rooms + 3)->down, names[7]);

//Cliff
strcpy_s((rooms + 4)->north, names[5]);
strcpy_s((rooms + 4)->south, names[1]);
strcpy_s((rooms + 4)->east, "-");
strcpy_s((rooms + 4)->west, "-");
strcpy_s((rooms + 4)->up, "-");
strcpy_s((rooms + 4)->down, "-");

//Super Generator
strcpy_s((rooms + 5)->north, "-");
strcpy_s((rooms + 5)->south, "-");
strcpy_s((rooms + 5)->east, "-");
strcpy_s((rooms + 5)->west, names[9]);
strcpy_s((rooms + 5)->up, "-");
strcpy_s((rooms + 5)->down, "-");

//Portal Room
strcpy_s((rooms + 6)->north, "-");
strcpy_s((rooms + 6)->south, names[1]);
strcpy_s((rooms + 6)->east, "-");
strcpy_s((rooms + 6)->west, "-");
strcpy_s((rooms + 6)->up, "-");
strcpy_s((rooms + 6)->down, "-");

//Underwater Cave
strcpy_s((rooms + 7)->north, "-");
strcpy_s((rooms + 7)->south, "-");
strcpy_s((rooms + 7)->east, names[8]);
strcpy_s((rooms + 7)->west, "-");
strcpy_s((rooms + 7)->up, "-");
strcpy_s((rooms + 7)->down, "-");

//Dragon Chamber
strcpy_s((rooms + 8)->north, "-");
strcpy_s((rooms + 8)->south, names[6]);
strcpy_s((rooms + 8)->east, "-");
strcpy_s((rooms + 8)->west, "-");
strcpy_s((rooms + 8)->up, "-");
strcpy_s((rooms + 8)->down, "-");

//Floor 1
strcpy_s((rooms + 9)->north, "-");
strcpy_s((rooms + 9)->south, "-");
strcpy_s((rooms + 9)->east, "-");
strcpy_s((rooms + 9)->west, "-");
strcpy_s((rooms + 9)->up, names[10]);
strcpy_s((rooms + 9)->down, "-");

//Floor 2
strcpy_s((rooms + 10)->north, "-");
strcpy_s((rooms + 10)->south, "-");
strcpy_s((rooms + 10)->east, "-");
strcpy_s((rooms + 10)->west, "-");
strcpy_s((rooms + 10)->up, names[11]);
strcpy_s((rooms + 10)->down, "-");

//Treasure Chamber
strcpy_s((rooms + 11)->north, "-");
strcpy_s((rooms + 11)->south, "-");
strcpy_s((rooms + 11)->east, "-");
strcpy_s((rooms + 11)->west, "-");
strcpy_s((rooms + 11)->up, names[12]);
strcpy_s((rooms + 11)->down, "-");

//Rakdos Throne Room
strcpy_s((rooms + 12)->north, "-");
strcpy_s((rooms + 12)->south, "-");
strcpy_s((rooms + 12)->east, names[0]);
strcpy_s((rooms + 12)->west, "-");
strcpy_s((rooms + 12)->up, "-");
strcpy_s((rooms + 12)->down, "-");
*/

/*CREATE EXITS*/

//PORTAL
strcpy((exits + 0)->name, "PORTAL");
strcpy((exits + 0)->description, "A nice Portal");
(exits + 0)->src = rooms + 0;
(exits + 0)->dst = rooms + 1;
(exits + 0)->direction = down;

//FOREST
strcpy((exits + 1)->name, "FOREST\n");
strcpy((exits + 1)->description, "It's a big forest.\n");
(exits + 1)->src = rooms + 1;
(exits + 1)->dst = rooms + 3;
(exits + 1)->direction = west;

//SAND PATH
strcpy((exits + 2)->name, "SAND PATH\n");
strcpy((exits + 2)->description, "A long path that connects this big lake with Grimgar.\n");
(exits + 2)->src = rooms + 3;
(exits + 2)->dst = rooms + 1;
(exits + 2)->direction = east;

//TAVERN ENTRANCE
strcpy((exits + 3)->name, "TAVERN ENTRACE\n");
strcpy((exits + 3)->description, "A big door to enter to the tavern.\n");
(exits + 3)->src = rooms + 1;
(exits + 3)->dst = rooms + 2;
(exits + 3)->direction = west;

//TAVERN EXIT
strcpy((exits + 4)->name, "TAVERN EXIT\n");
strcpy((exits + 4)->description, "The big door to exit to the tavern.\n");
(exits + 4)->src = rooms + 2;
(exits + 4)->dst = rooms + 1;
(exits + 4)->direction = east;

//STONE PATH
strcpy((exits + 5)->name, "STONE PATH\n");
strcpy((exits + 5)->description, "At the end of this path you can see the hill.\n");
(exits + 5)->src = rooms + 1;
(exits + 5)->dst = rooms + 4;
(exits + 5)->direction = north;

//STONE PATH
strcpy((exits + 6)->name, "STONE PATH\n");
strcpy((exits + 6)->description, "At the end of this path you can see Grimgar.\n");
(exits + 6)->src = rooms + 4;
(exits + 6)->dst = rooms + 5;
(exits + 6)->direction = north;

//
strcpy((exits + 7)->name, "\n");
strcpy((exits + 7)->description, "At the end of this path you can see Grimgar.\n");
(exits + 7)->src = rooms + 4;
(exits + 7)->dst = rooms + 1;
(exits + 7)->direction = south;



}

void World::Movement(int *num)
{
	int i;
	char direction;
	printf("Which direction do you want to go? (n/s/e/w/u/d)\n");
	scanf_s("%c", &direction);
	switch (direction)
	{
	case 'n':
	{
		printf("You are in %s\n", (rooms + *num)->name);
		printf("North is %s\n", (rooms + *num)->north);
		if (strcmp((rooms + *num)->north, "-") == 0)
		{
			printf("You can't go that way.\n");
		}
		else
		{
			for (i = 0; i < NUM_ROOMS; i++)
			{
				if (strcmp((rooms + i)->name, (rooms + *num)->north) == 0)
				{
					*num = i;
					break;
				}
			}
		}
		break;
	}
	case 's':
	{
		printf("You are in %s\n", (rooms + *num)->name);
		printf("South is %s\n", (rooms + *num)->south);
		if (strcmp((rooms + *num)->south, "-") == 0)
		{
			printf("You can't go that way.\n");
		}
		else
		{
			for (i = 0; i < NUM_ROOMS; i++)
			{
				if (strcmp((rooms + i)->name, (rooms + *num)->south) == 0)
				{
					*num = i;
					break;
				}
			}
		}
		break;
	}
	case 'e':
	{
		printf("You are in %s\n", (rooms + *num)->name);
		printf("East is %s\n", (rooms + *num)->east);
		if (strcmp((rooms + *num)->east, "-") == 0)
		{
			printf("You can't go that way.\n");
		}
		else
		{
			for (i = 0; i < NUM_ROOMS; i++)
			{
				if (strcmp((rooms + i)->name, (rooms + *num)->east) == 0)
				{
					*num = i;
					break;
				}
			}
		}
		break;
	}
	case 'w':
	{
		printf("You are in %s\n", (rooms + *num)->name);
		printf("West is %s\n", (rooms + *num)->west);
		if (strcmp((rooms + *num)->west, "-") == 0)
		{
			printf("You can't go that way.\n");
		}
		else
		{
			for (i = 0; i < NUM_ROOMS; i++)
			{
				if (strcmp((rooms + i)->name, (rooms + *num)->west) == 0)
				{
					*num = i;
					break;
				}
			}
		}
		break;
	}

	case 'u':
	{
		printf("You are in %s\n", (rooms + *num)->name);
		printf("Up is %s\n", (rooms + *num)->up);
		if (strcmp((rooms + *num)->up, "-") == 0)
		{
			printf("You can't go that way.\n");
		}
		else
		{
			for (i = 0; i < NUM_ROOMS; i++)
			{
				if (strcmp((rooms + i)->name, (rooms + *num)->up) == 0)
				{
					*num = i;
					break;
				}
			}
		}
		break;
	}
	case 'd':
	{
		printf("You are in %s\n", (rooms + *num)->name);
		printf("Down is %s\n", (rooms + *num)->down);
		if (strcmp((rooms + *num)->down, "-") == 0)
		{
			printf("You can't go that way.\n");
		}
		else
		{
			for (i = 0; i < NUM_ROOMS; i++)
			{
				if (strcmp((rooms + i)->name, (rooms + *num)->down) == 0)
				{
					*num = i;
					break;
				}
			}
		}
		break;
	}
	default:
	{
		printf("ERROR\n");
		break;
	}
	}
}


void World::Look(int num)const
{
	printf("%s\n%s", (rooms + num)->name, (rooms + num)->description);
}

void World::Help()const
{
	printf("Welcome to my Zork!\nThis is an interactive textual adventure where you are the protagonist.\n");
	printf("OBJECTIVE:\nExplore Aincrad and fight enemies to find the magical stones.\nThese powerful items will give you enough power to defeat Rakdos, the Devil King, and save the world.");
	printf("INSTRUCTIONS:\nYou can move or look through the entire map using commands 'go'/'look' combined with 'north','south','east','west'.\n");
	

}

World::~World()
{
	delete[] rooms;
	delete player;
	delete[] exits;
}
