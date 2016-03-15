#include"world.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NUM_ROOMS 13
#define NUM_EXITS 18

World::World()
{
	rooms = new Room[NUM_ROOMS];
	player = new Player;
	exits = new Exit[NUM_EXITS];
}

void World::CreateWorld() const
{
	int  i;

	/* CREATE ROOMS: NAMES & DESCRIPTIONS */
	//BEDROOM
	strcpy_s((rooms)->name, "BEDROOM");
	strcpy_s((rooms)->description, "This is my room, what a mess.\nI can hear a very strange noise coming from under my bed.\nI should take a look.\n");

	//GRIMGAR
	strcpy_s((rooms + 1)->name, "GRIMGAR");
	strcpy_s((rooms + 1)->description, "We are in Grimgar, Simon.\nIt's the capital city of Aincrad, this beautiful fantasy world.\nThis world is living a nightmare since the arrival of Rakdos, lord of the desolation.");

	//TAVERN
	strcpy_s((rooms + 2)->name, "TAVERN");
	strcpy_s((rooms + 2)->description, "In this tavern we can buy new items and weapons to improve our abilities.\n");

	//LAKE
	strcpy_s((rooms + 3)->name, "LAKE");
	strcpy_s((rooms + 3)->description, "What an enormous lake!\nIt's a nice day to take a dip.\nIf you stare at the bottom you can see a small grotto.\n");

	//HILL
	strcpy_s((rooms + 4)->name, "HILL");
	strcpy_s((rooms + 4)->description, "This is the highest hill in the city.\nYou can see everything wonderful about Aincrad from up here,\nand the Tower of Rakdos, the Devil King...\n");

	//SUPER GENERATOR
	strcpy_s((rooms + 5)->name, "SUPER GENERATOR");
	strcpy_s((rooms + 5)->description, "We are at the entrance of Rakdos Tower, the hell...\nNext to it the Super Generator is installed.\nThis huge device is the responsible for providing all the energy of the city.\n");

	//PORTAL ROOM
	strcpy_s((rooms + 6)->name, "PORTAL ROOM");
	strcpy_s((rooms + 6)->description, "We have entered in a magical Room.\nCan you see the big Portal with a very strange inscriptions?\nIf you jump into it you can teleport to another place.\n");

	//UNDERWATER CAVE
	strcpy_s((rooms + 7)->name, "UNDERWATER CAVE");
	strcpy_s((rooms + 7)->description, "Echo, echo, echo ...\nWe have to care if we want to leave this cave alive.\nIt's a very big and deep cave, so we will\nhave to defeat powerful enemies if you want to continue.\n");

	//DRAGON'S RIFT
	strcpy_s((rooms + 8)->name, "DRAGON'S RIFT");
	strcpy_s((rooms + 8)->description, "It's very hot here...Wait!\nThis is the Dragon chamber.\nWe have to leave quickly before the Dragon returns.\n");

	//FLOOR 1
	strcpy_s((rooms + 9)->name, "FLOOR 1");
	strcpy_s((rooms + 9)->description, "This is the first floor of the tower.\nScary monsters and skeletons can appear, so let's fight them!\nWe have to care, some trapps have been scatteret throughout the building.\n");

	//FLOOR 2
	strcpy_s((rooms + 10)->name, "FLOOR 2");
	strcpy_s((rooms + 10)->description, "Good Job, Simon! We have reached the second floor.\nIt's a big room with some inscriptions on the walls.\n");

	//TREASURE CHAMBER
	strcpy_s((rooms + 11)->name, "TREASURE CHAMBER");
	strcpy_s((rooms + 11)->description, "Yeah! Simon, this is the final room before the ultimate battle.\nThere is a key on the ground, and seems to fit the lock of these two big chests in front of us.\n");

	//RAKDOS THRONE ROOM
	strcpy_s((rooms + 12)->name, "RAKDOS THRONE ROOM");
	strcpy_s((rooms + 12)->description, "What a big chamber!\nSimon, Rakdos is there, let's fight and defeat him!\n");


	/* CREATE EXITS */
	//PORTAL
	strcpy_s((exits)->name, "PORTAL\n");
	strcpy_s((exits)->description, "What an strange Portal, let's cross it.\n");
	(exits)->src = rooms + 0;
	(exits)->dst = rooms + 1;
	(exits)->direction = down;

	//FOREST
	strcpy_s((exits + 1)->name, "FOREST\n");
	strcpy_s((exits + 1)->description, "It's a big forest.\n");
	(exits + 1)->src = rooms + 1;
	(exits + 1)->dst = rooms + 3;
	(exits + 1)->direction = west;

	//SAND PATH
	strcpy_s((exits + 2)->name, "SAND PATH\n");
	strcpy_s((exits + 2)->description, "A long path that connects this big lake with Grimgar.\n");
	(exits + 2)->src = rooms + 3;
	(exits + 2)->dst = rooms + 1;
	(exits + 2)->direction = east;

	//TAVERN ENTRANCE
	strcpy_s((exits + 3)->name, "TAVERN ENTRACE\n");
	strcpy_s((exits + 3)->description, "A big door to enter to the tavern.\n");
	(exits + 3)->src = rooms + 1;
	(exits + 3)->dst = rooms + 2;
	(exits + 3)->direction = east;
	(exits + 3)->door = true;
	(exits + 3)->open = false;

	//TAVERN EXIT
	strcpy_s((exits + 4)->name, "TAVERN EXIT\n");
	strcpy_s((exits + 4)->description, "A little wood door to exit the tavern (I don't understand why\nthere is a door to enter and another different one to exit...)\n");
	(exits + 4)->src = rooms + 2;
	(exits + 4)->dst = rooms + 1;
	(exits + 4)->direction = west;
	(exits + 4)->door = true;
	(exits + 4)->open = false;

	//STONE PATH
	strcpy_s((exits + 5)->name, "STONE PATH\n");
	strcpy_s((exits + 5)->description, "At the end of this path you can see the Hill.\n");
	(exits + 5)->src = rooms + 1;
	(exits + 5)->dst = rooms + 4;
	(exits + 5)->direction = north;

	//STONE PATH
	strcpy_s((exits + 6)->name, "STONE PATH\n");
	strcpy_s((exits + 6)->description, "At the end of this path you can see Grimgar.\n");
	(exits + 6)->src = rooms + 4;
	(exits + 6)->dst = rooms + 1;
	(exits + 6)->direction = south;

	//TENEBROUS PATH
	strcpy_s((exits + 7)->name, "TENEBROUS PATH\n");
	strcpy_s((exits + 7)->description, "This road leads to the entrance of the towe,\nwhere the super-generator is installed\n");
	(exits + 7)->src = rooms + 4;
	(exits + 7)->dst = rooms + 5;
	(exits + 7)->direction = north;

	//ROCKY CLIMB
	strcpy_s((exits + 8)->name, "ROCKY CLIMB\n");
	strcpy_s((exits + 8)->description, "You have to climb this steep path if you want to return to the high cliff.\n");
	(exits + 8)->src = rooms + 5;
	(exits + 8)->dst = rooms + 4;
	(exits + 8)->direction = south;

	//THE BIG ENTRANCE
	strcpy_s((exits + 9)->name, "THE BIG ENTRANCE\n");
	strcpy_s((exits + 9)->description, "Wow, this door is too big, and scary...\nAre you sure you want to enter?\n");
	(exits + 9)->src = rooms + 5;
	(exits + 9)->dst = rooms + 9;
	(exits + 9)->direction = west;
	(exits + 9)->door = true;
	(exits + 9)->open = false;

	//CHALLENGE 1
	strcpy_s((exits + 10)->name, "THE STONE DOOR\n");
	strcpy_s((exits + 10)->description, "This door is too heavy and big.\nYou have to use your magic abilities if you want to continue to the next floor.\n");
	(exits + 10)->src = rooms + 9;
	(exits + 10)->dst = rooms + 10;
	(exits + 10)->direction = up;
	(exits + 10)->door = true;
	(exits + 10)->open = false;

	//CHALLENGE 2
	strcpy_s((exits + 11)->name, "INVISIBLE STAIRS\n");
	strcpy_s((exits + 11)->description, "What is going on? There are no stairs to keep going up.\nLook, there's a padlock there maybe we can open with the correct key.\n");
	(exits + 11)->src = rooms + 10;
	(exits + 11)->dst = rooms + 11;
	(exits + 11)->direction = up;
	(exits + 11)->door = true;
	(exits + 11)->open = false;

	//FINAL DOOR
	strcpy_s((exits + 12)->name, "THE FINAL DOOR\n");
	strcpy_s((exits + 12)->description, "Are you sure you want to open this door?\nThe ultimate challenge is waiting behind it...\n");
	(exits + 12)->src = rooms + 11;
	(exits + 12)->dst = rooms + 12;
	(exits + 12)->direction = east;
	(exits + 12)->door = true;
	(exits + 12)->open = false;

	//TELEPORTER
	strcpy_s((exits + 13)->name, "TELEPORTER\n");
	strcpy_s((exits + 13)->description, "It's the end of the travel, Simon.\nYou can return to your real world by crossing this teleporter.\n");
	(exits + 13)->src = rooms + 12;
	(exits + 13)->dst = rooms + 0;
	(exits + 13)->direction = south;

	//UNDERWATER PATH
	strcpy_s((exits + 14)->name, "UNDERWATER PATH\n");
	strcpy_s((exits + 14)->description, "At the end of this path we can access to the underground zone of Aincrad.\n");
	(exits + 14)->src = rooms + 3;
	(exits + 14)->dst = rooms + 7;
	(exits + 14)->direction = down;

	//UNDERGROUND CORRIDOR
	strcpy_s((exits + 15)->name, "UNDERGROUND CORRIDOR\n");
	strcpy_s((exits + 15)->description, "Continue straight through this corridor to arrive at the Dragon Rift.\n");
	(exits + 15)->src = rooms + 7;
	(exits + 15)->dst = rooms + 8;
	(exits + 15)->direction = east;

	//NARROW PATH
	strcpy_s((exits + 16)->name, "NARROW PATH\n");
	strcpy_s((exits + 16)->description, "This path will take you to the magical room, where the portal is placed.\n");
	(exits + 16)->src = rooms + 8;
	(exits + 16)->dst = rooms + 6;
	(exits + 16)->direction = south;



	//MAGIC TUNNEL
	strcpy_s((exits + 17)->name, "MAGIC TUNNEL\n");
	strcpy_s((exits + 17)->description, "This tunnel accessible through the portal connects with Grimgar.\n");
	(exits + 17)->src = rooms + 6;
	(exits + 17)->dst = rooms + 1;
	(exits + 17)->direction = south;



}

void World::Movement(int &pos,char option_move[])
{
	fflush(stdin);
	int i, j;

	player->player_pos = (rooms + pos);

	if (strcmp(option_move, "go") == 0)
	{
		printf("Which direction do you want to go? ");
		gets_s(option_move, 20);
	}

	if (strcmp(option_move, "n") == 0 || strcmp(option_move, "north") == 0 || strcmp(option_move, "go north") == 0)
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if ((exits + i)->src == player->player_pos && (exits + i)->direction == north)
			{
				player->player_pos = (exits + i)->dst;
				for (j = 0; j < NUM_ROOMS; j++)
				{
					if ((exits + i)->dst == (rooms + j))
					{
						if ((exits + i)->door == true && (exits + i)->open == false)
						{
							printf("\nThere's a door locked here.\n");
							return;
						}
						else
						{
							pos = j;
							printf("\n%s\n%s\n", (rooms + j)->name, (rooms + j)->description);
							return;
						}
					}
				}
			}
		}
		printf("\nYou can't move into that direction.\n");
	}

	else if (strcmp(option_move, "s") == 0 || strcmp(option_move, "south") == 0 || strcmp(option_move, "go south") == 0)
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if ((exits + i)->src == player->player_pos && (exits + i)->direction == south)
			{
				player->player_pos = (exits + i)->dst;
				for (j = 0; j < NUM_ROOMS; j++)
				{
					if ((exits + i)->dst == (rooms + j))
					{
						if ((exits + i)->door == true && (exits + i)->open == false)
						{
							printf("\nThere's a door locked here.\n");
							return;
						}
						else
						{
							pos = j;
							printf("\n%s\n%s\n", (rooms + j)->name, (rooms + j)->description);
							return;
						}
					}
				}
			}
		}
		printf("\nYou can't move into that way.\n");
	}

	else if (strcmp(option_move, "e") == 0 || strcmp(option_move, "east") == 0 || strcmp(option_move, "go east") == 0)
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if ((exits + i)->src == player->player_pos && (exits + i)->direction == east)
			{
				player->player_pos = (exits + i)->dst;
				for (j = 0; j < NUM_ROOMS; j++)
				{
					if ((exits + i)->dst == (rooms + j))
					{
						if ((exits + i)->door == true && (exits + i)->open == false)
						{
							printf("\nThere's a door locked here.\n");
							return;
						}
						else
						{
							pos = j;
							printf("\n%s\n%s\n", (rooms + j)->name, (rooms + j)->description);
							return;
						}
					}
				}
			}
		}
		printf("\nYou can't move into that direction.\n");
	}

	else if (strcmp(option_move, "w") == 0 || strcmp(option_move, "west") == 0 || strcmp(option_move, "go west") == 0)
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if ((exits + i)->src == player->player_pos && (exits + i)->direction == west)
			{
				player->player_pos = (exits + i)->dst;
				for (j = 0; j < NUM_ROOMS; j++)
				{
					if ((exits + i)->dst == (rooms + j))
					{
						if ((exits + i)->door == true && (exits + i)->open == false)
						{
							printf("\nThere's a door locked here.\n");
							return;
						}
						else
						{
							pos = j;
							printf("\n%s\n%s\n", (rooms + j)->name, (rooms + j)->description);
							return;
						}
					}
				}
			}
		}
		printf("\nYou can't move into that way.\n");
	}

	else if (strcmp(option_move, "d") == 0 || strcmp(option_move, "down") == 0 || strcmp(option_move, "go down") == 0)
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if ((exits + i)->src == player->player_pos && (exits + i)->direction == down)
			{
				player->player_pos = (exits + i)->dst;
				for (j = 0; j < NUM_ROOMS; j++)
				{
					if ((exits + i)->dst == (rooms + j))
					{
						if ((exits + i)->door == true && (exits + i)->open == false)
						{
							printf("\nThere's a door locked here.\n");
							return;
						}
						else
						{
							pos = j;
							printf("\n%s\n%s\n", (rooms + j)->name, (rooms + j)->description);
							return;
						}
					}
				}
			}
		}
		printf("\nYou can't move into that direction.\n");
	}

	else if (strcmp(option_move, "u") == 0 || strcmp(option_move, "up") == 0 || strcmp(option_move, "go up") == 0)
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if ((exits + i)->src == player->player_pos && (exits + i)->direction == up)
			{
				player->player_pos = (exits + i)->dst;
				for (j = 0; j < NUM_ROOMS; j++)
				{
					if ((exits + i)->dst == (rooms + j))
					{
						if ((exits + i)->door == true && (exits + i)->open == false)
						{
							printf("\nThere's a door locked here.\n");
							return;
						}
						else
						{
							pos = j;
							printf("\n%s\n%s\n", (rooms + j)->name, (rooms + j)->description);
							return;
						}
					}
				}
			}	
		}
		printf("\nYou can't move into that way.\n");
	}
}

void World::Look(int pos, char direction[]) const
{
	int i, j;
	player->player_pos = (rooms + pos);
	if (strcmp(direction, "look") == 0)
	{
		printf("\n%s\n%s", (rooms + pos)->name, (rooms + pos)->description);
		printf("\nWhich direction do you want to look? ");
		gets_s(direction, 20);
	}

	if (strcmp(direction, "look north") == 0 || strcmp(direction, "north") == 0)
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if ((exits + i)->src == player->player_pos && (exits + i)->direction == north)
			{
				printf("\n%s%s", (exits + i)->name, (exits + i)->description);
				return;
			}
		}
		printf("\nThere's nothing to look here.\n");
	}

	else if (strcmp(direction, "look south") == 0 || strcmp(direction, "south") == 0)
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if ((exits + i)->src == player->player_pos && (exits + i)->direction == south)
			{
				printf("\n%s%s", (exits + i)->name, (exits + i)->description);
				return;
			}
		}
		printf("\nThere's nothing to look here.\n");
	}

	else if (strcmp(direction, "look east") == 0 || strcmp(direction, "east") == 0)
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if ((exits + i)->src == player->player_pos && (exits + i)->direction == east)
			{
				printf("\n%s%s", (exits + i)->name, (exits + i)->description);
				return;
			}
		}
		printf("\nThere's nothing to look here.\n");
	}

	else if (strcmp(direction, "look west") == 0 || strcmp(direction, "west") == 0)
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if ((exits + i)->src == player->player_pos && (exits + i)->direction == west)
			{
				printf("\n%s%s", (exits + i)->name, (exits + i)->description);
				return;
			}
		}
		printf("\nThere's nothing to look here.\n");
	}

	else if (strcmp(direction, "look up") == 0 || strcmp(direction, "up") == 0)
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if ((exits + i)->src == player->player_pos && (exits + i)->direction == up)
			{
				printf("\n%s%s", (exits + i)->name, (exits + i)->description);
				return;
			}
		}
		printf("\nThere's nothing to look here.\n");
	}

	else if (strcmp(direction, "look down") == 0 || strcmp(direction, "down") == 0)
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if ((exits + i)->src == player->player_pos && (exits + i)->direction == down)
			{
				printf("\n%s%s", (exits + i)->name, (exits + i)->description);
				return;
			}
		}
		printf("\nThere's nothing to look here.\n");
	}

	else
	{
		printf("\nInvalid command.\n");
	}
	
}

void World::Help()
{
	printf("\nThis is 'Simon & Baxter: the magical stones'\nIt's an interactive textual game in which you have to explore\n");
	printf("a fantasy world full of enemies and challenges to get\nmagical stones. Whith their power you will be able to defeat Rakdos, the Devil King.\n");
	printf("\nINSTRUCTIONS:\n");
	printf("The commands that you can enter are: go/look/open/close/help/quit.\n");
	printf("To specify the direction you want: north/south/east/west/up/down\n");
}


void World::Open(int pos, char open[])
{
	int i;
	player->player_pos = (rooms + pos);
	if (strcmp(open, "open door") == 0)
	{
		printf("Which door do you want to open? ");
		gets_s(open, 20);
	}

	if (strcmp(open, "north") == 0 || strcmp(open, "open north door") == 0)
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if ((exits + i)->src == player->player_pos && (exits + i)->direction == north && (exits + i)->open == false)
			{
				(exits + i)->open = true;
				printf("You opened the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to open here.\n");
	}

	else if (strcmp(open, "south") == 0 || strcmp(open, "open south door") == 0)
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if ((exits + i)->src == player->player_pos && (exits + i)->direction == south && (exits + i)->open == false)
			{
				(exits + i)->open = true;
				printf("You opened the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to open here.\n");
	}

	else if (strcmp(open, "east") == 0 || strcmp(open, "open east door") == 0 )
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if ((exits + i)->src == player->player_pos && (exits + i)->direction == east && (exits + i)->open == false)
			{
				(exits + i)->open = true;
				printf("You opened the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to open here.\n");
	}

	else if (strcmp(open, "west") == 0 || strcmp(open, "open west door") == 0)
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if ((exits + i)->src == player->player_pos && (exits + i)->direction == west && (exits + i)->open == false)
			{
				(exits + i)->open = true;
				printf("You opened the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to open here.\n");
	}

	else if (strcmp(open, "up") == 0 || strcmp(open, "open up door") == 0)
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if ((exits + i)->src == player->player_pos && (exits + i)->direction == up && (exits + i)->open == false)
			{
				(exits + i)->open = true;
				printf("You opened the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to open here.\n");
	}

	else if (strcmp(open, "down") == 0 || strcmp(open, "open down door") == 0)
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if ((exits + i)->src == player->player_pos && (exits + i)->direction == down && (exits + i)->open == false)
			{
				(exits + i)->open = true;
				printf("You opened the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to open here.\n");
	}
}

void World::Close(int pos, char close[])
{
	int i;
	player->player_pos = (rooms + pos);
	if (strcmp(close, "close door") == 0)
	{
		printf("Which door do you want to close? ");
		gets_s(close, 20);
	}

	if (strcmp(close, "north") == 0 || strcmp(close, "close north door") == 0)
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if ((exits + i)->src == player->player_pos && (exits + i)->direction == north && (exits + i)->open == true && (exits + i)->door == true)
			{
				(exits + i)->open = false;
				printf("You closed the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to close here.\n");
	}

	else if (strcmp(close, "south") == 0 || strcmp(close, "close south door") == 0)
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if ((exits + i)->src == player->player_pos && (exits + i)->direction == south && (exits + i)->open == true && (exits + i)->door == true)
			{
				(exits + i)->open = false;
				printf("You closed the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to close here.\n");
	}

	else if (strcmp(close, "east") == 0 || strcmp(close, "close east door") == 0)
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if ((exits + i)->src == player->player_pos && (exits + i)->direction == east && (exits + i)->open == true && (exits + i)->door == true)
			{
				(exits + i)->open = false;
				printf("You closed the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to close here.\n");
	}

	else if (strcmp(close, "west") == 0 || strcmp(close, "close west door") == 0)
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if ((exits + i)->src == player->player_pos && (exits + i)->direction == west && (exits + i)->open == true && (exits + i)->door == true)
			{
				(exits + i)->open = false;
				printf("You closed the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to close here.\n");
	}

	else if (strcmp(close, "up") == 0 || strcmp(close, "close up door") == 0)
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if ((exits + i)->src == player->player_pos && (exits + i)->direction == up && (exits + i)->open == true && (exits + i)->door == true)
			{
				(exits + i)->open = false;
				printf("You closed the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to close here.\n");
	}

	else if (strcmp(close, "down") == 0 || strcmp(close, "close down door") == 0)
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if ((exits + i)->src == player->player_pos && (exits + i)->direction == down && (exits + i)->open == true && (exits + i)->door == true)
			{
				(exits + i)->open = false;
				printf("You closed the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to close here.\n");
	}
}



World::~World()
{
	delete[] rooms;
	delete player;
	delete[] exits;
}


