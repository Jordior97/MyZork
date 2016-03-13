#include"world.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


World::World()
{
	rooms = new Room[13];
	player = new Player;
	exits = new Exit[13];
}

void World::CreateWorld() const
{
	int  i;
	//ROOMS: NAMES and DESCRIPTIONS
	char *names[] = { "Bedroom", "Aincrad", "Tavern", "Lake", "Cliff", "Super Generator", "Portal Room", "Underwater Cave", "Dragon Chamber", "Floor 1", "Floor 2", "Treasure Chamber", "Rakdos Throne Room" };
	for (i = 0; i < 13; i++)
	{
	strcpy_s((rooms+i)->name, names[i]);
	}
	for (i = 0; i < 13; i++)
	{
		printf("%i) %s\n", i, (rooms + i)->name);
	}

char *descriptions[] =
{
	"This is my room, what a mess.\nI can hear a very strange noise coming from under my bed.\nI should take a look.",
	"We are in Grimgar, Simon.\nIt's the capital city of Aincrad, this beautiful fantasy world.",
	"In this tavern we can buy new items and weapons to improve our abilities.",
	"What an enormous lake!\nIt's a nice day to take a dip.\nIf you stare at the bottom you can see a small grotto.",
	"This is the highest hill in the city.\nYou can see everything wonderful about Aincrad from up here, and the Tower of Rakdos, the Devil King...",
	"We are at the entrance of Rakdos Tower, the hell...\nNext to it the Super Generator is installed.\nThis huge device is the responsible for providing all the energy of the city.",
	"We have entered in a magical Room.\nCan you see the big Portal with a very strange inscriptions?\nIf you jump into it you can teleport to another place.",
	"Echo, echo, echo ...\nWe have to care if we want to leave this cave alive.\nIt's a very big and deep cave, so we will have to defeat powerful enemies if you want to continue.",
	"It's very hot here...Wait!\nThis is the Dragon chamber.\nWe have to leave quickly before the Dragon returns.",
	"This is the first floor of the tower.\nScary monsters and skeletons can appear, so let's fight them!\nWe have to care, some trapps have been scatteret throughout the building.",
	"Good Job, Simon! We have reached the second floor.\nIt's a big room with some inscriptions on the walls.",
	"Yeah! Simon, this is the final room before the ultimate battle.\nThere is a key on the ground, and seems to fit the lock of these two big chests in front of us.",
	"What a big chamber!\nSimon, Rakdos is there, let's fight and defeat him! " };

for (i = 0; i < 13; i++)
{
	strcpy_s((rooms + i)->description, descriptions[i]);
}
for (i = 0; i < 13; i++)
{
	printf("%i) %s\n\n", i, (rooms + i)->description);
}

//CARDINAL POINTS OF ROOMS
//Bedroom
strcpy_s((rooms + 0)->north, "-");
strcpy_s((rooms + 0)->south, "-");
strcpy_s((rooms + 0)->east, "-");
strcpy_s((rooms + 0)->west, "-");
strcpy_s((rooms + 0)->up, "-");
strcpy_s((rooms + 0)->down, names[1]);

//Aincrad
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

for (i = 1; i < 5; i++)
{
	printf("%s\n", (rooms + i)->name);
	printf("North: %s\nSouth: %s\nEast: %s\nWest: %s\n", (rooms + i)->north, (rooms + i)->south, (rooms + i)->east, (rooms + i)->west);
}


//EXITS: connections
//Bedroom->Aincrad
strcpy_s((exits + 0)->to, names[1]);
strcpy_s((exits + 0)->from, names[0]);

//Aincrad->tavern/lake/cliff
for (i = 1; i < 4; i++)
{
	strcpy_s((exits + i)->to, names[i + 1]);
	strcpy_s((exits + i)->from, names[1]);
}

//Tavern/lake/cliff->Aincrad
for (i = 4; i < 7; i++)
{
	strcpy_s((exits + i)->to, names[1]);
	strcpy_s((exits + i)->from, names[i - 2]);
}

//Cliff<->Generator
strcpy_s((exits + 7)->to, names[5]);
strcpy_s((exits + 7)->from, names[4]);
strcpy_s((exits + 8)->to, names[4]);
strcpy_s((exits + 8)->from, names[5]);

for (i = 0; i < 9; i++)
{
	printf("From %s to %s\n", (exits + i)->from, (exits + i)->to);
}

}

void World::Movement(char direction,int *j)
{
	int i;
	switch (direction)
	{
	case 'n':
	{
		printf("You are in %s\n", (rooms + *j)->name);
		printf("North is %s\n", (rooms + *j)->north);
		if (strcmp((rooms + *j)->north, "-") == 0)
		{
			printf("You can't go that way.\n");
		}
		else
		{
			for (i = 0; i < 13; i++)
			{
				if (strcmp((rooms + i)->name, (rooms + *j)->north) == 0)
				{
					*j = i;
					break;
				}
			}
		}
		break;
	}
	case 's':
	{
		printf("You are in %s\n", (rooms + *j)->name);
		printf("South is %s\n", (rooms + *j)->south);
		if (strcmp((rooms + *j)->south, "-") == 0)
		{
			printf("You can't go that way.\n");
		}
		else
		{
			for (i = 0; i < 13; i++)
			{
				if (strcmp((rooms + i)->name, (rooms + *j)->south) == 0)
				{
					*j = i;
					break;
				}
			}
		}
		break;
	}
	case 'e':
	{
		printf("You are in %s\n", (rooms + *j)->name);
		printf("East is %s\n", (rooms + *j)->east);
		if (strcmp((rooms + *j)->east, "-") == 0)
		{
			printf("You can't go that way.\n");
		}
		else
		{
			for (i = 0; i < 13; i++)
			{
				if (strcmp((rooms + i)->name, (rooms + *j)->east) == 0)
				{
					*j = i;
					break;
				}
			}
		}
		break;
	}
	case 'w':
	{
		printf("You are in %s\n", (rooms + *j)->name);
		printf("West is %s\n", (rooms + *j)->west);
		if (strcmp((rooms + *j)->west, "-") == 0)
		{
			printf("You can't go that way.\n");
		}
		else
		{
			for (i = 0; i < 13; i++)
			{
				if (strcmp((rooms + i)->name, (rooms + *j)->west) == 0)
				{
					*j = i;
					break;
				}
			}
		}
		break;
	}

	case 'u':
	{
		printf("You are in %s\n", (rooms + *j)->name);
		printf("Up is %s\n", (rooms + *j)->up);
		if (strcmp((rooms + *j)->up, "-") == 0)
		{
			printf("You can't go that way.\n");
		}
		else
		{
			for (i = 0; i < 13; i++)
			{
				if (strcmp((rooms + i)->name, (rooms + *j)->up) == 0)
				{
					*j = i;
					break;
				}
			}
		}
		break;
	}
	case 'd':
	{
		printf("You are in %s\n", (rooms + *j)->name);
		printf("Down is %s\n", (rooms + *j)->down);
		if (strcmp((rooms + *j)->down, "-") == 0)
		{
			printf("You can't go that way.\n");
		}
		else
		{
			for (i = 0; i < 13; i++)
			{
				if (strcmp((rooms + i)->name, (rooms + *j)->down) == 0)
				{
					*j = i;
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

World::~World()
{
	delete[] rooms;
	delete player;
	delete[] exits;
}
