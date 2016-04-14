#include"world.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


World::World()
{
	player = new Player;
}

void World::CreateWorld() 
{
	/* CREATE ROOMS: names & descriptions */

	//BEDROOM
	/*(rooms)->name = "BEDROOM";
	(rooms)->description = "This is my room, what a mess.\nI can hear a very strange noise coming from under my bed.\nI should take a look.\n";*/

	rooms.push_back(new Room("BEDROOM", "This is my room, what a mess.\nI can hear a very strange noise coming from under my bed.\nI should take a look.\n"));

	//GRIMGAR
	/*(rooms + 1)->name = "GRIMGAR";
	(rooms + 1)->description = "We are in Grimgar, Simon.\nIt's the capital city of Aincrad, this beautiful fantasy world.\nThis world is living a nightmare since the arrival of Rakdos, lord of the desolation.\n";*/

	rooms.push_back(new Room("GRIMGAR", "We are in Grimgar, Simon.\nIt's the capital city of Aincrad, this beautiful fantasy world.\nThis world is living a nightmare since the arrival of Rakdos, lord of the desolation.\n"));

	//TAVERN
	/*(rooms + 2)->name = "TAVERN";
	(rooms + 2)->description = "In this tavern we can buy new items and weapons to improve our abilities.\n";*/

	rooms.push_back(new Room("TAVERN", "In this tavern we can buy new items and weapons to improve our abilities.\n"));

	//LAKE
	/*(rooms + 3)->name = "LAKE";
	(rooms + 3)->description = "What an enormous lake!\nIt's a nice day to take a dip.\nIf you stare at the bottom you can see a small grotto.\n";*/

	rooms.push_back(new Room("LAKE", "What an enormous lake!\nIt's a nice day to take a dip.\nIf you stare at the bottom you can see a small grotto.\n"));

	//HILL
	/*(rooms + 4)->name = "HILL";
	(rooms + 4)->description = "This is the highest hill in the city.\nYou can see everything wonderful about Aincrad from up here,\nand the Tower of Rakdos, the Devil King...\n";*/

	rooms.push_back(new Room("HILL", "This is the highest hill in the city.\nYou can see everything wonderful about Aincrad from up here,\nand the Tower of Rakdos, the Devil King...\n"));

	//SUPER GENERATOR
	/*(rooms + 5)->name = "SUPER GENERATOR";
	(rooms + 5)->description = "We are at the entrance of Rakdos Tower, the hell...\nNext to it the Super Generator is installed.\nThis huge device is the responsible for providing all the energy of the city.\n";*/

	rooms.push_back(new Room("SUPER GENERATOR", "We are at the entrance of Rakdos Tower, the hell...\nNext to it the Super Generator is installed.\nThis huge device is the responsible for providing all the energy of the city.\n"));

	//PORTAL ROOM
	/*(rooms + 6)->name = "PORTAL ROOM";
	(rooms + 6)->description = "We have entered in a magical Room.\nCan you see the big Portal with a very strange inscriptions?\nIf you jump into it you can teleport to another place.\n";*/

	rooms.push_back(new Room("PORTAL ROOM", "We have entered in a magical Room.\nCan you see the big Portal with a very strange inscriptions?\nIf you jump into it you can teleport to another place.\n"));


	//UNDERWATER CAVE
	/*(rooms + 7)->name = "UNDERWATER CAVE";
	(rooms + 7)->description = "Echo, echo, echo ...\nWe have to care if we want to leave this cave alive.\nIt's a very big and deep cave, so we will\nhave to defeat powerful enemies if you want to continue.\n";*/

	rooms.push_back(new Room("UNDERWATER CAVE", "Echo, echo, echo ...\nWe have to care if we want to leave this cave alive.\nIt's a very big and deep cave, so we will\nhave to defeat powerful enemies if you want to continue.\n"));


	//DRAGON'S RIFT
	/*(rooms + 8)->name = "DRAGON'S RIFT";
	(rooms + 8)->description = "It's very hot here...Wait!\nThis is the Dragon chamber.\nWe have to leave quickly before the Dragon returns.\n";*/

	rooms.push_back(new Room("DRAGON'S RIFT", "It's very hot here...Wait!\nThis is the Dragon chamber.\nWe have to leave quickly before the Dragon returns.\n"));

	//FLOOR 1
	/*(rooms + 9)->name = "FLOOR 1";
	(rooms + 9)->description = "This is the first floor of the tower.\nScary monsters and skeletons can appear, so let's fight them!\nWe have to care, some trapps have been scatteret throughout the building.\n";*/

	rooms.push_back(new Room("FLOOR 1", "This is the first floor of the tower.\nScary monsters and skeletons can appear, so let's fight them!\nWe have to care, some trapps have been scatteret throughout the building.\n"));

	//FLOOR 2
	/*(rooms + 10)->name = "FLOOR 2";
	(rooms + 10)->description = "Good Job, Simon! We have reached the second floor.\nIt's a big room with some inscriptions on the walls.\n";*/

	rooms.push_back(new Room("FLOOR 2", "Good Job, Simon! We have reached the second floor.\nIt's a big room with some inscriptions on the walls.\n"));


	//TREASURE CHAMBER
	/*(rooms + 11)->name = "TREASURE CHAMBER";
	(rooms + 11)->description = "Yeah! Simon, this is the final room before the ultimate battle.\nThere is a key on the ground, and seems to fit the lock of these two big chests in front of us.\n";*/

	rooms.push_back(new Room("TREASURE CHAMBER", "Yeah! Simon, this is the final room before the ultimate battle.\nThere is a key on the ground, and seems to fit the lock of these two big chests in front of us.\n"));

	//RAKDOS THRONE ROOM
	/*(rooms + 12)->name = "RAKDOS THRONE ROOM";
	(rooms + 12)->description = "What a big chamber!\nSimon, Rakdos is there, let's fight and defeat him!\n";*/

	rooms.push_back(new Room("RAKDOS THRONE ROOM", "What a big chamber!\nSimon, Rakdos is there, let's fight and defeat him!\n"));

	/* CREATE EXITS: names & descriptions */

	//PORTAL
	/*(exits)->name = "PORTAL\n";
	(exits)->description = "What an strange Portal, let's cross it.\n";
	(exits)->src = rooms + 0;
	(exits)->dst = rooms + 1;
	(exits)->direction = down;*/

	exits.push_back(new Exit("PORTAL\n", "What an strange Portal, let's cross it.\n", rooms[0], rooms[1], down,false,true));


	//FOREST
	/*(exits + 1)->name = "FOREST\n";
	(exits + 1)->description = "It's a big forest.\n";
	(exits + 1)->src = rooms + 1;
	(exits + 1)->dst = rooms + 3;
	(exits + 1)->direction = west`*/

	exits.push_back(new Exit("FOREST\n", "It's a big forest.\n", rooms[1], rooms[3], west, false, true));

	//SAND PATH
	/*(exits + 2)->name = "SAND PATH\n";
	(exits + 2)->description = "A long path that connects this big lake with Grimgar.\n";
	(exits + 2)->src = rooms + 3;
	(exits + 2)->dst = rooms + 1;
	(exits + 2)->direction = east;*/

	exits.push_back(new Exit("SAND PATH\n", "A long path that connects this big lake with Grimgar.\n", rooms[3], rooms[1], east, false, true));

	//TAVERN ENTRANCE
	/*(exits + 3)->name = "TAVERN ENTRACE\n";
	(exits + 3)->description = "A big door to enter to the tavern.\n";
	(exits + 3)->src = rooms + 1;
	(exits + 3)->dst = rooms + 2;
	(exits + 3)->direction = east;
	(exits + 3)->door = true;
	(exits + 3)->open = false;*/

	exits.push_back(new Exit("TAVERN ENTRACE\n", "A big door to enter to the tavern.\n", rooms[1], rooms[2], east, true, false));

	//TAVERN EXIT
	/*(exits + 4)->name = "TAVERN EXIT\n";
	(exits + 4)->description = "It's the big door to exit the tavern.\n";
	(exits + 4)->src = rooms + 2;
	(exits + 4)->dst = rooms + 1;
	(exits + 4)->direction = west;
	(exits + 4)->door = true;
	(exits + 4)->open = true;*/

	exits.push_back(new Exit("TAVERN EXIT\n", "It's the big door to exit the tavern.\n", rooms[2], rooms[1], west, true, true));

	//STONE PATH
	/*(exits + 5)->name = "STONE PATH\n";
	(exits + 5)->description = "At the end of this path you can see the Hill.\n";
	(exits + 5)->src = rooms + 1;
	(exits + 5)->dst = rooms + 4;
	(exits + 5)->direction = north;*/

	exits.push_back(new Exit("STONE PATH\n", "At the end of this path you can see the Hill.\n", rooms[1], rooms[4], north, false, true));

	//STONE PATH
	/*(exits + 6)->name = "STONE PATH\n";
	(exits + 6)->description = "At the end of this path you can see Grimgar.\n";
	(exits + 6)->src = rooms + 4;
	(exits + 6)->dst = rooms + 1;
	(exits + 6)->direction = south;*/

	exits.push_back(new Exit("STONE PATH\n", "At the end of this path you can see Grimgar.\n", rooms[4], rooms[1], south, false, true));

	//TENEBROUS PATH
	/*(exits + 7)->name = "TENEBROUS PATH\n";
	(exits + 7)->description = "This road leads to the entrance of the tower,\nwhere the super-generator is installed\n";
	(exits + 7)->src = rooms + 4;
	(exits + 7)->dst = rooms + 5;
	(exits + 7)->direction = north;*/

	exits.push_back(new Exit("TENEBROUS PATH\n", "This road leads to the entrance of the tower,\nwhere the super-generator is installed\n", rooms[4], rooms[5], north, false, true));


	//ROCKY CLIMB
	/*(exits + 8)->name = "ROCKY CLIMB\n";
	(exits + 8)->description = "You have to climb this steep path if you want to return to the high cliff.\n";
	(exits + 8)->src = rooms + 5;
	(exits + 8)->dst = rooms + 4;
	(exits + 8)->direction = south;*/

	exits.push_back(new Exit("ROCKY CLIMB\n", "You have to climb this steep path if you want to return to the high cliff.\n", rooms[5], rooms[4], south, false, true));


	//THE BIG ENTRANCE
	/*(exits + 9)->name = "THE BIG ENTRANCE\n";
	(exits + 9)->description = "Wow, this door is too big, and scary...\nAre you sure you want to enter?\n";
	(exits + 9)->src = rooms + 5;
	(exits + 9)->dst = rooms + 9;
	(exits + 9)->direction = west;
	(exits + 9)->door = true;
	(exits + 9)->open = false;*/

	exits.push_back(new Exit("THE BIG ENTRANCE\n", "Wow, this door is too big, and scary...\nAre you sure you want to enter?\n", rooms[5], rooms[9], west, true, false));

	//CHALLENGE 1
	/*(exits + 10)->name = "THE STONE DOOR\n";
	(exits + 10)->description = "This door is too heavy and big.\nYou have to use your magic abilities if you want to continue to the next floor.\n";
	(exits + 10)->src = rooms + 9;
	(exits + 10)->dst = rooms + 10;
	(exits + 10)->direction = up;
	(exits + 10)->door = true;
	(exits + 10)->open = false;*/

	exits.push_back(new Exit("THE STONE DOOR\n", "This door is too heavy and big.\nYou have to use your magic abilities if you want to continue to the next floor.\n", rooms[9], rooms[10], up, true, false));

	//CHALLENGE 2
	/*(exits + 11)->name = "INVISIBLE STAIRS\n";
	(exits + 11)->description = "What is going on? There are no stairs to keep going up.\nLook, there's a padlock there maybe we can open with the correct key.\n";
	(exits + 11)->src = rooms + 10;
	(exits + 11)->dst = rooms + 11;
	(exits + 11)->direction = up;
	(exits + 11)->door = true;
	(exits + 11)->open = false;*/

	exits.push_back(new Exit("INVISIBLE STAIRS\n", "What is going on? There are no stairs to keep going up.\nLook, there's a padlock there maybe we can open with the correct key.\n", rooms[10], rooms[11], up, true, false));


	//FINAL DOOR
	/*(exits + 12)->name = "THE FINAL DOOR\n";
	(exits + 12)->description = "Are you sure you want to open this door?\nThe ultimate challenge is waiting behind it...\n";
	(exits + 12)->src = rooms + 11;
	(exits + 12)->dst = rooms + 12;
	(exits + 12)->direction = east;
	(exits + 12)->door = true;
	(exits + 12)->open = false;*/

	exits.push_back(new Exit("THE FINAL DOOR\n", "Are you sure you want to open this door?\nThe ultimate challenge is waiting behind it...\n", rooms[11], rooms[12], east, true, false));

	//TELEPORTER
	/*(exits + 13)->name = "TELEPORTER\n";
	(exits + 13)->description = "It's the end of the travel, Simon.\nYou can return to your real world by crossing this teleporter.\n";
	(exits + 13)->src = rooms + 12;
	(exits + 13)->dst = rooms + 0;
	(exits + 13)->direction = south;*/

	exits.push_back(new Exit("TELEPORTER\n", "It's the end of the travel, Simon.\nYou can return to your real world by crossing this teleporter.\n", rooms[12], rooms[0], south, false, true));


	//UNDERWATER PATH
	/*(exits + 14)->name = "UNDERWATER PATH\n";
	(exits + 14)->description = "At the end of this path we can access to the underground zone of Aincrad.\n";
	(exits + 14)->src = rooms + 3;
	(exits + 14)->dst = rooms + 7;
	(exits + 14)->direction = down;*/

	exits.push_back(new Exit("UNDERWATER PATH\n", "At the end of this path we can access to the underground zone of Aincrad.\n", rooms[3], rooms[7], down, false, true));

	//UNDERGROUND CORRIDOR
	/*(exits + 15)->name = "UNDERGROUND CORRIDOR\n";
	(exits + 15)->description = "Continue straight through this corridor to arrive at the Dragon Rift.\n";
	(exits + 15)->src = rooms + 7;
	(exits + 15)->dst = rooms + 8;
	(exits + 15)->direction = east;*/

	exits.push_back(new Exit("UNDERGROUND CORRIDOR\n", "Continue straight through this corridor to arrive at the Dragon Rift.\n", rooms[7], rooms[8], east, false, true));


	//NARROW PATH
	/*(exits + 16)->name = "NARROW PATH\n";
	(exits + 16)->description = "This path will take you to the magical room, where the portal is placed.\n";
	(exits + 16)->src = rooms + 8;
	(exits + 16)->dst = rooms + 6;
	(exits + 16)->direction = south;*/

	exits.push_back(new Exit("NARROW PATH\n", "This path will take you to the magical room, where the portal is placed.\n", rooms[8], rooms[6], south, false, true));

	//MAGIC TUNNEL
	/*(exits + 17)->name = "MAGIC TUNNEL\n";
	(exits + 17)->description = "This tunnel accessible through the portal connects with Grimgar.\n";
	(exits + 17)->src = rooms + 6;
	(exits + 17)->dst = rooms + 1;
	(exits + 17)->direction = south;*/

	exits.push_back(new Exit("MAGIC TUNNEL\n", "This tunnel accessible through the portal connects with Grimgar.\n", rooms[6], rooms[1], south, false, true));


	/* CREATE ITEMS: names & descriptions */
	/*(items)->name = "SWORD";
	(items)->description = "A nice sword.\n";
	(items)->src = rooms + 1;*/

	items.push_back(new Item("SWORD", "A nice sword.\n", rooms[1], false));


	/*(items + 1)->name = "SHIELD";
	(items + 1)->description = "A nice shield.\n";
	(items + 1)->src = rooms + 2;*/

	items.push_back(new Item("SHIELD", "A nice shield.\n", rooms[2], false));




}


/* MOVEMENT FUNCTION */
void World::Movement(int &pos, Vector<MyString> &commands)
{
	fflush(stdin);

	int i, j; //counters that consider the correct room/exit when you move.

	player->player_pos = rooms[pos];

	if (commands.size() == 2 && commands[0] == "go" && (commands[1] == "north" && commands[1] == "n") || commands[0] == "north" || commands[0] == "n")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == north)
			{
				player->player_pos = exits[i]->dst;
				for (j = 0; j < NUM_ROOMS; j++)
				{
					if (exits[i]->dst == rooms[j])
					{
						if (exits[i]->door == true && exits[i]->open == false)  //Case 1: the exit has a closed door you have to open first
						{
							printf("\nThere's a door locked here.\n");
							return;
						}
						else  //Case 2: there is a room in the chosen direction and there isn't a closed door (sets a new position for the player).
						{
							pos = j;
							printf("\n%s\n%s", rooms[j]->name.c_str(), rooms[j]->description.c_str());
							return;
						}
					}
				}
			}
		}
		printf("\nYou can't move into that direction.\n");  //Case 3: there isn't any room in the chosen direction
	}

	else if (commands.size() == 2 && commands[0] == "go" && (commands[1] == "south" || commands[1] == "s") || commands[0] == "south" || commands[0] == "s")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == south)
			{
				player->player_pos = exits[i]->dst;
				for (j = 0; j < NUM_ROOMS; j++)
				{
					if (exits[i]->dst == rooms[j])
					{
						if (exits[i]->door == true && exits[i]->open == false)
						{
							printf("\nThere's a door locked here.\n");
							return;
						}
						else
						{
							pos = j;
							printf("\n%s\n%s", rooms[j]->name.c_str(), rooms[j]->description.c_str());
							return;
						}
					}
				}
			}
		}
		printf("\nYou can't move into that way.\n");
	}

	else if (commands.size() == 2 && commands[0] == "go" && (commands[1] == "east" || commands[1] == "e") || commands[0] == "east" || commands[0] == "e")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == east)
			{
				player->player_pos = exits[i]->dst;
				for (j = 0; j < NUM_ROOMS; j++)
				{
					if (exits[i]->dst == rooms[j])
					{
						if (exits[i]->door == true && exits[i]->open == false)
						{
							printf("\nThere's a door locked here.\n");
							return;
						}
						else
						{
							pos = j;
							printf("\n%s\n%s", rooms[j]->name.c_str(), rooms[j]->description.c_str());
							return;
						}
					}
				}
			}
		}
		printf("\nYou can't move into that direction.\n");
	}

	else if (commands.size() == 2 && commands[0] == "go" && (commands[1] == "west" || commands[1] == "w") || commands[0] == "west" || commands[0] == "w")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == west)
			{
				player->player_pos = exits[i]->dst;
				for (j = 0; j < NUM_ROOMS; j++)
				{
					if (exits[i]->dst == rooms[j])
					{
						if (exits[i]->door == true && exits[i]->open == false)
						{
							printf("\nThere's a door locked here.\n");
							return;
						}
						else
						{
							pos = j;
							printf("\n%s\n%s", rooms[j]->name.c_str(), rooms[j]->description.c_str());
							return;
						}
					}
				}
			}
		}
		printf("\nYou can't move into that way.\n");
	}

	else if (commands.size() == 2 && commands[0] == "go" && (commands[1] == "down" || commands[1] == "d") || commands[0] == "down" || commands[0] == "d")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == down)
			{
				player->player_pos = exits[i]->dst;
				for (j = 0; j < NUM_ROOMS; j++)
				{
					if (exits[i]->dst == rooms[j])
					{
						if (exits[i]->door == true && exits[i]->open == false)
						{
							printf("\nThere's a door locked here.\n");
							return;
						}
						else
						{
							pos = j;
							printf("\n%s\n%s", rooms[j]->name.c_str(), rooms[j]->description.c_str());
							return;
						}
					}
				}
			}
		}
		printf("\nYou can't move into that direction.\n");
	}

	else if (commands.size() == 2 && commands[0] == "go" && (commands[1] == "up" || commands[1] == "u") || commands[0] == "up" || commands[0] == "u")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == up)
			{
				player->player_pos = exits[i]->dst;
				for (j = 0; j < NUM_ROOMS; j++)
				{
					if (exits[i]->dst == rooms[j])
					{
						if (exits[i]->door == true && exits[i]->open == false)
						{
							printf("\nThere's a door locked here.\n");
							return;
						}
						else
						{
							pos = j;
							printf("\n%s\n%s\n", rooms[j]->name.c_str(), rooms[j]->description.c_str());
							return;
						}
					}
				}
			}	
		}
		printf("\nYou can't move into that way.\n");
	}

	else
	{
		printf("\nYou have to specify in which direction you want to move.\n");
		return;
	}
}

void World::Look(int pos, Vector<MyString> &commands) const
{
	int i; //Countes to consider the correct room/exit when you are looking
	player->player_pos = rooms[pos];

	if (commands.size() == 2 && (commands[1] == "north" || commands[1] == "n" ))
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == north) //Case 2: name and description of the exit placed in the chosen direction
			{
				exits[i]->Look();
				return;
			}
		}
		printf("\nThere's nothing to look here.\n");  //Case 3: there's no exit placed in the chosen direction
	}

	else if (commands.size() == 2 && (commands[1] == "south" || commands[1] == "s"))
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == south)
			{
				exits[i]->Look();
				return;
			}
		}
		printf("\nThere's nothing to look here.\n");
	}

	else if (commands.size() == 2 && (commands[1] == "east" || commands[1] == "e"))
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == east)
			{
				exits[i]->Look();
				return;
			}
		}
		printf("\nThere's nothing to look here.\n");
	}

	else if (commands.size() == 2 && (commands[1] == "west" || commands[1] == "w"))
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == west)
			{
				exits[i]->Look();
				return;
			}
		}
		printf("\nThere's nothing to look here.\n");
	}

	else if (commands.size() == 2 && (commands[1] == "up" || commands[1] == "u"))
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == up)
			{
				exits[i]->Look();
				return;
			}
		}
		printf("\nThere's nothing to look here.\n");
	}

	else if (commands.size() == 2 && (commands[1] == "down" || commands[1] == "d"))
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == down)
			{
				exits[i]->Look();
				return;
			}
		}
		printf("\nThere's nothing to look here.\n");
	}

	else //Case 1: name and description of the room you are.
	{
		rooms[pos]->Look();
		for (i = 0; i < NUM_ITEMS; i++)
		{
			if (player->player_pos == items[i]->src && items[i]->picked == false)
			{
				printf("\nItems you can find here:\n");
				items[i]->Look();
			}
		}
	}
}

void World::Help() const
{
	printf("\nThis is 'Simon & Baxter: the magical stones'\n\nIt's an interactive textual game in which you have to explore\n");
	printf("a fantasy world full of enemies and challenges to get\nmagical stones. With their power you will be able to defeat Rakdos,\nthe Devil King.\n");
	printf("\nINSTRUCTIONS:\n");
	printf("The commands that you can enter:\ngo / look / open _ door / close _ door / help / quit.\n\n");
	printf("To specify the direction you want:\nnorth(n) / south(s) / east(e) / west(w) / up(u) / down(d)\n");
}


void World::Open(int pos, Vector<MyString>&commands) const
{
	int i;  //Counter to consider the correct exit
	player->player_pos = rooms[pos];

	/*if ((commands.size() == 2 && (commands[1] == "north" || commands[1] == "n"))
	{
		printf("\nYou have to specify which door you want to open.\n");
		return;
	}*/

	if (commands.size() == 3 && (commands[1] == "north" || commands[1] == "n") && commands[2] == "door")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			//OPEN CONDITION: the exit you want to "open" has a door, and its door is closed
			if (exits[i]->src == player->player_pos && exits[i]->direction == north && exits[i]->open == false)
			{
				exits[i]->open = true;
				printf("\nYou opened the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to open here.\n");
	}

	else if (commands.size() == 3 && (commands[1] == "south" || commands[1] == "s"))
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == south && exits[i]->open == false)
			{
				exits[i]->open = true;
				printf("\nYou opened the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to open here.\n");
	}

	else if (commands.size() == 3 && (commands[1] == "east" || commands[1] == "e") && commands[2] == "door")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == east && exits[i]->open == false)
			{
				exits[i]->open = true;
				printf("\nYou opened the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to open here.\n");
	}

	else if (commands.size() == 3 && (commands[1] == "west" || commands[1] == "w") && commands[2] == "door")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == west && exits[i]->open == false)
			{
				exits[i]->open = true;
				printf("You opened the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to open here.\n");
	}

	else if (commands.size() == 3 && (commands[1] == "up" || commands[1] == "u") && commands[2] == "door")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == up && exits[i]->open == false)
			{
				exits[i]->open = true;
				printf("\nYou opened the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to open here.\n");
	}

	else if (commands.size() == 3 && (commands[1] == "down" || commands[1] == "d") && commands[2] == "door")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == down && exits[i]->open == false)
			{
				exits[i]->open = true;
				printf("\nYou opened the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to open here.\n");
	}

	else
	{
	printf("\nYou have to specify which door you want to open.\n");
	return;
	}
}


void World::Close(int pos, Vector<MyString> &commands) const
{
	int i;
	player->player_pos = rooms[pos];

	/*if (close == close_door)
	{
		printf("\nYou have to specify which door you want to close.\n");
		return;
	}*/


	if (commands.size() == 3 && (commands[1] == "north" || commands[1] == "n") && commands[2] == "door")
	{
		//CLOSE CONDITION: the exit you want to "close" has a door, and its door is opened
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == north && exits[i]->open == true && exits[i]->door == true)
			{
				exits[i]->open = false;
				printf("\nYou closed the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to close here.\n");
	}

	else if (commands.size() == 3 && (commands[1] == "south" || commands[1] == "s") && commands[2] == "door")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == south && exits[i]->open == true && exits[i]->door == true)
			{
				exits[i]->open = false;
				printf("\nYou closed the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to close here.\n");
	}

	else if (commands.size() == 3 && (commands[1] == "east" || commands[1] == "e") && commands[2] == "door")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == east && exits[i]->open == true && exits[i]->door == true)
			{
				exits[i]->open = false;
				printf("\nYou closed the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to close here.\n");
	}

	else if (commands.size() == 3 && (commands[1] == "west" || commands[1] == "w") && commands[2] == "door")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == west && exits[i]->open == true && exits[i]->door == true)
			{
				exits[i]->open = false;
				printf("\nYou closed the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to close here.\n");
	}

	else if (commands.size() == 3 && (commands[1] == "up" || commands[1] == "u") && commands[2] == "door")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == up && exits[i]->open == true && exits[i]->door == true)
			{
				exits[i]->open = false;
				printf("\nYou closed the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to close here.\n");
	}

	else if (commands.size() == 3 && (commands[1] == "down" || commands[1] == "d") && commands[2] == "door")
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == down && exits[i]->open == true && exits[i]->door == true)
			{
				exits[i]->open = false;
				printf("\nYou closed the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to close here.\n");
	}
}


void World::Pick(Vector<MyString> &commands)
{
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		if (commands.size() == 2 && items[i]->name == commands[1] && exits[i]->src == player->player_pos && items[i]->picked == false)
		{
			items[i]->picked = true;
			player->num_items++;
			printf("You picked %s", items[i]->name.c_str());
			return;
		}
	}
	printf("There's any object with that name here.\n");
}

void World::Drop(Vector<MyString> &commands)
{
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		if (commands.size() == 2 && items[i]->name == commands[1] && items[i]->picked == true)
		{
			items[i]->picked = false;
			items[i]->src = player->player_pos;
			printf("You droped %s", items[i]->name.c_str());
			return;
		}
	}
	printf("There's any object with that name here.\n");
}


World::~World()
{
	delete player;
	delete[] inventory;
}


