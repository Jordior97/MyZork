#include"world.h"
#include<stdio.h>
#include<string.h>


World::World()
{
	rooms = new Room[13];
	player = new Player;
	exits = new Exit[13];
}

void World::CreateWorld() const
{
	int  i;
	char *names[] = { "Bedroom", "Aincrad", "Tavern", "Lake", "Underwater Cave", "Dragon Chamber", "Portal Room", "Cliff", "Super Generator", "Floor 1", "Floor 2", "Treasure Chamber", "Rakdos Throne Room" };
	for (i = 0; i < 13; i++)
	{
	strcpy_s((rooms+i)->name, names[i]);
	}
	for (i = 0; i < 13; i++)
	{
		printf("%i) %s\n", i + 1, (rooms + i)->name);
	}

	char *descriptions[] = { 
		"This is my room, what a mess.\nI can hear a very strange noise coming from under my bed.\nI should take a look.",
		"We are in Grimgar, Simon.\nIt's the capital city of Aincrad, this beautiful fantasy world.", 
		"In this tavern we can buy new items and weapons to improve our abilities.", 
		"What an enormous lake!\nIt's a nice day to take a dip.\nIf you stare at the bottom you can see a small grotto.", 
		"Echo, echo, echo ...\nWe have to care if we want to leave this cave alive.\nIt's a very big and deep cave, so we will have to defeat powerful enemies if you want to continue.", 
		"It's very hot here...Wait!\nThis is the Dragon chamber.\nWe have to leave quickly before the Dragon returns.", 
		"We have entered in a magical Room.\nCan you see the big Portal with a very strange inscriptions?\nIf you jump into it you can teleport to another place.", 
		"This is the highest hill in the city.\nYou can see everything wonderful about Aincrad from up here, and the Tower of Rakdos, the Devil King...", 
		"We are at the entrance of Rakdos Tower, the hell...\nNext to it the Super Generator is installed.\nThis huge device is the responsible for providing all the energy of the city.", 
		"This is the first floor of the tower.\nScary monsters and skeletons can appear, so let's fight them!\nWe have to care, some trapps have been scatteret throughout the building.", 
		"Good Job, Simon! We have reached the second floor.\nIt's a big room with some inscriptions on the walls.", 
		"Yeah! Simon, this is the final room before the ultimate battle.\nThere is a key on the ground, and seems to fit the lock of these two big chests in front of us.",
		"What a big chamber!\nSimon, Rakdos is there, let's fight and defeat him! " };
	for (i = 0; i < 13; i++)
	{
		strcpy_s((rooms+i)->description, descriptions[i]);
	}
	for (i = 0; i < 13; i++)
	{
		printf("%i) %s\n\n", i + 1, (rooms + i)->description);
	}
}

World::~World()
{
	delete[] rooms;
	delete player;
	delete[] exits;
}
