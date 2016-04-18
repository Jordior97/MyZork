#include"world.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


World::World()
{
	player = new Player;
}

void World::CreateWorld() 
{
	/*---CREATE ROOMS---*/

	//BEDROOM (rooms[0])
	rooms.push_back(new Room("BEDROOM", "This is my room, what a mess.\nI can hear a very strange noise coming from under my bed.\nI should take a look.\n"));

	//GRIMGAR (rooms[1])
	rooms.push_back(new Room("GRIMGAR", "We are in Grimgar, Simon.\nIt's the capital city of Aincrad, this beautiful fantasy world.\nThis world is living a nightmare since the arrival of Rakdos,\nlord of the desolation.\n"));

	//TAVERN (rooms[2])
	rooms.push_back(new Room("TAVERN", "In this tavern we can buy new items and weapons to improve our abilities.\n"));

	//LAKE (rooms[3])
	rooms.push_back(new Room("LAKE", "What an enormous lake!\nIt's a nice day to take a dip.\nIf you stare at the bottom you can see a small grotto.\n"));

	//HILL (rooms[4])
	rooms.push_back(new Room("HILL", "This is the highest hill in the city.\nYou can see everything wonderful about Aincrad from up here,\nand the Tower of Rakdos, the Devil King...\n"));

	//SUPER GENERATOR (rooms[5])
	rooms.push_back(new Room("SUPER GENERATOR", "We are at the entrance of Rakdos Tower, the hell...\nNext to it the Super Generator is installed.\nThis huge device is the responsible for providing all the energy of the city.\n"));

	//PORTAL ROOM (rooms[6])
	rooms.push_back(new Room("PORTAL ROOM", "We have entered in a magical Room.\nCan you see the big Portal with a very strange inscriptions?\nIf you jump into it you can teleport to another place.\n"));

	//UNDERWATER CAVE (rooms[7])
	rooms.push_back(new Room("UNDERWATER CAVE", "Echo, echo, echo ...\nWe have to care if we want to leave this cave alive.\nIt's a very big and deep cave, so we will\nhave to defeat powerful enemies if you want to continue.\n"));

	//DRAGON'S RIFT (rooms[8])
	rooms.push_back(new Room("DRAGON'S RIFT", "It's very hot here...Wait!\nThis is the Dragon chamber.\nWe have to leave quickly before the Dragon returns.\n"));

	//FLOOR 1 (rooms[9])
	rooms.push_back(new Room("FLOOR 1", "This is the first floor of the tower.\nScary monsters and skeletons can appear, so let's fight them!\nWe have to care, some trapps have been scatteret throughout the building.\n"));

	//FLOOR 2 (rooms[10])
	rooms.push_back(new Room("FLOOR 2", "Good Job, Simon! We have reached the second floor.\nIt's a big room with some inscriptions on the walls.\n"));

	//TREASURE CHAMBER (rooms[11])
	rooms.push_back(new Room("TREASURE CHAMBER", "Yeah! Simon, this is the final room before the ultimate battle.\nLook all the fortune around us. It seems that this chamber is used to keep\nthe treasures Rakdos has stolen until now.\n"));
	
	//RAKDOS THRONE ROOM (rooms[12])
	rooms.push_back(new Room("RAKDOS THRONE ROOM", "What a big chamber!\nSimon, Rakdos is there, let's fight and defeat him!\n"));



	/*---CREATE EXITS---*/

	//PORTAL (exits[0])
	exits.push_back(new Exit("PORTAL\n", "What an strange Portal, let's cross it.\n", rooms[0], rooms[1], down, false, true));

	//FOREST (exits[1])
	exits.push_back(new Exit("FOREST\n", "It's a big forest. So many people came\ninto the forest and never have returned.\n", rooms[1], rooms[3], west, false, true));

	//SAND PATH (exits[2])
	exits.push_back(new Exit("SAND PATH\n", "A long path that connects this big lake with Grimgar.\n", rooms[3], rooms[1], east, false, true));

	//TAVERN ENTRANCE (exits[3])
	exits.push_back(new Exit("TAVERN ENTRACE\n", "A big door to enter to the tavern.\n", rooms[1], rooms[2], east, true, false));

	//TAVERN EXIT (exits[4])
	exits.push_back(new Exit("TAVERN EXIT\n", "It's the big door to exit the tavern.\n", rooms[2], rooms[1], west, true, true));

	//STONE PATH (exits[5])
	exits.push_back(new Exit("STONE PATH\n", "At the end of this path you can see the Hill.\n", rooms[1], rooms[4], north, false, true));

	//STONE PATH (exits[6])
	exits.push_back(new Exit("STONE PATH\n", "At the end of this path you can see Grimgar.\n", rooms[4], rooms[1], south, false, true));

	//TENEBROUS PATH (exits[7])
	exits.push_back(new Exit("TENEBROUS PATH\n", "This road leads to the entrance of the tower,\nwhere the super-generator is installed\n", rooms[4], rooms[5], north, false, true));

	//ROCKY CLIMB (exits[8])
	exits.push_back(new Exit("ROCKY CLIMB\n", "You have to climb this steep path if you want to return to the high cliff.\n", rooms[5], rooms[4], south, false, true));

	//THE BIG ENTRANCE (exits[9])
	exits.push_back(new Exit("THE BIG ENTRANCE\n", "Wow, this door is too big, and scary...\nAre you sure you want to enter?\n", rooms[5], rooms[9], west, true, false));

	//CHALLENGE 1 (exits[10])
	exits.push_back(new Exit("THE STONE DOOR\n", "This door is too heavy and big.\nYou have to use your magic abilities if you want to continue to the next floor.\n", rooms[9], rooms[10], up, true, false));

	//CHALLENGE 2 (exits[11])
	exits.push_back(new Exit("INVISIBLE STAIRS\n", "What is going on? There are no stairs to keep going up.\nLook, there's a hatch in the roof with a padlock that maybe we can open with our key.\n", rooms[10], rooms[11], up, true, false));

	//FINAL DOOR (exits[12])
	exits.push_back(new Exit("THE FINAL DOOR\n", "Are you sure you want to open this door?\nThe ultimate challenge is waiting behind it...\n", rooms[11], rooms[12], east, true, false));

	//TELEPORTER (exits[13])
	exits.push_back(new Exit("TELEPORTER\n", "It's the end of the travel, Simon.\nYou can return to your real world by crossing this teleporter.\n", rooms[12], rooms[0], south, false, true));

	//UNDERWATER PATH (exits[14])
	exits.push_back(new Exit("UNDERWATER PATH\n", "At the end of this path we can access to the underground zone of Aincrad.\n", rooms[3], rooms[7], down, false, true));

	//UNDERGROUND CORRIDOR (exits[15])
	exits.push_back(new Exit("UNDERGROUND CORRIDOR\n", "Continue straight through this corridor to arrive at the Dragon Rift.\n", rooms[7], rooms[8], east, false, true));

	//NARROW PATH (exits[16])
	exits.push_back(new Exit("NARROW PATH\n", "This path will take you to the magical room, where the portal is placed.\n", rooms[8], rooms[6], south, false, true));

	//MAGIC TUNNEL (exits[17])
	exits.push_back(new Exit("MAGIC TUNNEL\n", "This tunnel accessible through the portal connects with Grimgar.\n", rooms[6], rooms[1], south, false, true));


	/*---CREATE ITEMS---*/

	//SWORD (items[0])
	items.push_back(new Item("SWORD", "This weapon is forged by The Five Blacksmiths, the best\nartisans of Aincrad, with materials whose origin is unknown.\n", rooms[1], RHand, 10, 0, 0, 0));

	//SHIELD (items[1])
	items.push_back(new Item("SHIELD", "This emblematic blue, red and white shield belonged to the Sergeant\nEurope, the protector of Aincrad. It's made with the most resistant material\nin the world: Amadantium\n", rooms[2], LHand, 0, 0, 0, 10));

	//KEY (items[2])
	items.push_back(new Item("KEY", "With this magic key you will be able to open all the doors and trapdoors\nto continue with our journey, Simon.\n", rooms[6], Non_Equipable, 0, 0, 0, 0));

	//HELMET (items[3])
	items.push_back(new Item("HELMET", "I've heard that the one who goes to battle with this\niron helmet equipped is invencible, but this story is just a myth.\n", rooms[5], Head, 0, 0, 5, 5));

	//BREADSPLATE (items[4])
	items.push_back(new Item("BREADSPLATE", "What a beautiful armor! It gives more stamina and resistance\nagainst monsters and creatures\n", rooms[4], Body, 0, 0, 5, 5));

	//GREAVES (items[5])
	items.push_back(new Item("GREAVES", "This greaves will give you more speed, but this is not useful in this game...\n", rooms[9], Legs, 0, 0, 0, 5));

	//AXE (items[6])
	items.push_back(new Item("AXE", "Use this powerful and big axe to destroy hundreds and hundreds of enemies,\nlike Nanoc the Barbarian.\n", rooms[7], RHand, 10, 0, 0, 0));

	//RING (items[7])
	items.push_back(new Item("RING", "This magic artefact is called 'The One Ring' it can increase your magical\npower.Look closely, there is an inscription: 'One ring to rule them all'.\n", rooms[8], LHand, 0, 20, 10, 0));

	//TRUNK (items[8])
	items.push_back(new Item("TRUNK", "You can put all the items you want into this magic trunk if\nyou run out of inventory space.\n", rooms[2], Non_Equipable, 0, 0, 0, 0));
	items[8]->container = true;

	/*----------------------*/

	/*  Magic Gems  */
	//AKA (items[9])
	items.push_back(new Item("AKA", "This is the red gem. It allows you to control fire\n", rooms[8], Non_Equipable, 0, 0, 0, 0));
	items[9]->magic_gem = true;

	//AO (items[10])
	items.push_back(new Item("AO", "This is the blue gem. It allows you to control water\n", rooms[3], Non_Equipable, 0, 0, 0, 0));
	items[10]->magic_gem = true;

	//KIIRO (items[11])
	items.push_back(new Item("KIIRO", "This is the yellow gem. It allows you to control electricity\n", rooms[5], Non_Equipable, 0, 0, 0, 0));
	items[11]->magic_gem = true;

	//KURO (items[12])
	items.push_back(new Item("KURO", "This is the black gem. It allows you to control darkness\n", rooms[6], Non_Equipable, 0, 0, 0, 0));
	items[12]->magic_gem = true;

	//SHIRO (items[13])
	items.push_back(new Item("SHIRO", "This is the white gem. It allows you to control brightness\n", rooms[9], Non_Equipable, 0, 0, 0, 0));
	items[13]->magic_gem = true;
	
	/*----------------------*/

	//EXCALIBUR (items[14])
	items.push_back(new Item("EXCABILUR", "This legendary weapon belonged to King Bradley, the king of kings,\nwho has goberned Aincriad since his death, 500 years ago.\nIt's said this sword has extraordinary properties.\n", rooms[11], RHand, 50, 50, 0, 0));

	//EAGIS (items[15])
	items.push_back(new Item("EAGIS", "What is that!? This is the mythic shield of Seuz,\nthe strongest god of all times! I think it will give you the enough\nresistance to withstand the last battle.\n", rooms[11], LHand, 0, 50, 0, 50));

	//VEST
	items.push_back(new Item("VEST", "Look at this strange vest. I heared that the bearer of\nthis magic clothing gets magical powers like super strength, enhaced\nstamina and mind control.\n",rooms[11], Body, 20, 20, 20, 20));
}


/*---MOVEMENT FUNCTION---*/
void World::Movement(int &pos, Vector<MyString> &commands)
{
	fflush(stdin);

	int i, j; //counters that consider the correct room/exit when you move.

	player->player_pos = rooms[pos];

	if (commands.size() == 2 && commands[0] == "go" && (commands[1] == "north" && commands[1] == "n") || commands[0] == "north" || commands[0] == "n") //Checks if commands introduced are correct
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == north) //Looks for an exit in the direction introduced
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

/*---LOOK FUNCTION---*/
void World::Look(int pos, Vector<MyString> &commands) const
{
	int i; //Counters to consider the correct room/exit when you are looking
	player->player_pos = rooms[pos];

	if (commands.size() == 2 && (commands[1] == "north" || commands[1] == "n" )) //checks if commands introduced are correct
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			if (exits[i]->src == player->player_pos && exits[i]->direction == north) //Case 1: shows the name and description of the exit placed in the chosen direction
			{
				exits[i]->Look();
				return;
			}
		}
		printf("\nThere's nothing to look here.\n");  //Case 2: there isn't any exit placed in the chosen direction
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

	else if (commands.size() == 2 && (commands[1] == "trunk"))
	{
		if (items[8]->src == player->player_pos)
		{
			printf("Items inside the TRUNK:\n\n");
			for (i = 0; i < NUM_ITEMS; i++)
			{
				if (items[i]->inside == true)
				{
					printf("%s\n%s\n", items[i]->name.c_str(), items[i]->description.c_str());
				}
			}
		}
		else
		{
			printf("The TRUNK is not here.\n");
		}
	}

	else if(commands.size()==1)//Case 3: name and description of the room you are. It shows items that are in the room too.
	{
		rooms[pos]->Look();
		printf("\n--------------------------\n");
		printf("\nItems you can find here:\n\n");
		for (i = 0; i < NUM_ITEMS; i++)
		{
			if (player->player_pos == items[i]->src && items[i]->picked == false && items[i]->inside == false)
			{
				items[i]->Look();
			}
		}
	}

	else
	{
		printf("Introduce a valid command if you want to look properly.\n");
	}
}

/*---HELP FUNCTION---*/
void World::Help() const
{
	printf("\nThis is 'Simon & Baxter: the magical gems'\n\nIt's an interactive textual game in which you have to explore\n");
	printf("a fantasy world full of enemies and challenges to get\nmagical gems. With their power you will be able to defeat Rakdos,\nthe Devil King.\n");
	printf("\nINSTRUCTIONS:\n\n");
	printf("The BASIC COMMANDS that you can enter:\ngo / look / open ... door / close ... door / help / quit.\n\n");
	printf("To specify the DIRECTION you want:\nnorth(n) / south(s) / east(e) / west(w) / up(u) / down(d)\n\n");
	printf("To INTERACT with OBJECTS you can introduce these commands:\n");
	printf("pick / drop <item> = to put items in your inventory / leave items\nin the room you are.\n");
	printf("equip / unequip <item> = to equip/unequip items that are in the inventory.\n");
	printf("put <item> into <containter> = to put an item into another item (container).\n");
	printf("get <item> from <containter> = to get an item that's inside\nanother item container).\n");
	printf("look trunk = to look items that are inside this container.\n\n");
	printf("To know basic INFORMATION related to the character:\n");
	printf("You can't see which objects are in the room when you move between them.\n");
	printf("To see the items, you have to insert the command 'look'.\n");
	printf("inventory / inv / i = it shows all the items the player is carrying.\n");
	printf("equipment(eq) = it shows the equipped items.\n");
	printf("stats(st) = to look the statistics of the character.\n");
	printf("\nSPECIAL FEATURE: WormHole\nYou have to think twice before dropping an item. Why? Because of the physical\nlaws of this world, a wormhole is created when you drop items,\nmaking them appear into another room. ");
	printf("If you want to keep your items safe,\nyou have to put them into the trunk.\n");

}

/*---OPEN FUNCTION---*/
void World::Open(int pos, Vector<MyString>&commands) const
{
	int i;  //Counter to consider the correct exit
	player->player_pos = rooms[pos];

	if (items[2]->picked == true) //checks if you have the key picked (necessary to open doors)
	{

		if (commands.size() == 3 && (commands[1] == "north" || commands[1] == "n") && commands[2] == "door") //checks if commands introduced are correct
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
	else
	{
		printf("You have to find the key if you want to open doors.\n");
	}
}

/*---CLOSE FUNCTION---*/
void World::Close(int pos, Vector<MyString> &commands) const
{
	int i;
	player->player_pos = rooms[pos];

	if (commands.size() == 3 && (commands[1] == "north" || commands[1] == "n") && commands[2] == "door") //checks if commands introduced are correct
	{
		for (i = 0; i < NUM_EXITS; i++)
		{
			//CLOSE CONDITION: the exit you want to "close" has a door, and its door is opened
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

/*---PICK FUNCTION---*/
void World::Pick(Vector<MyString> &commands) const
{
	//checks if inventory is full (so you can't pick more objects)
	if (player->num_items < player->max_items)
	{
		for (int i = 0; i < NUM_ITEMS; i++)
		{
			//checks if the commands introduced are correct (first command == pick && second command == <item_name>) and if the item is not in the inventory yet
			if (commands.size() == 2 && commands[1] == items[i]->name && items[i]->src == player->player_pos && items[i]->picked == false)
			{
				if (items[i]->container == false)
				{
					items[i]->picked = true;
					player->num_items++;
					printf("You picked %s\n", items[i]->name.c_str());
					return;
				}
				else
				{
					printf("This item is too big to carry it.\n");
					return;
				}
			}
		}
		printf("There's any object with that name here in this place.\n");
	}
	else
	{
		printf("Your inventory is full, you have to drop some items\n");
	}
}

/*---DROP FUNCTION---*/
void World::Drop(Vector<MyString> &commands) const
{
	srand(time(NULL));
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		//checks if the commands introduced are correct (first command == drop && second command == <item_name>) and if the item is in the inventory
		if (commands.size() == 2 && items[i]->name == commands[1] && items[i]->picked == true)
		{
			//checks if the the item is not equipped...
			if (items[i]->equipped == false)
			{
				int random = rand() % NUM_ROOMS;
				items[i]->picked = false;
				items[i]->src = rooms[random];//WormHole: sends the item to a random room.
				player->num_items--;
				printf("You dropped %s and the Wormhole made it desappear.\n", items[i]->name.c_str());
				return;
			}
			//...because you can't drop an equipped item
			else
			{
				printf("You have to unequip this item first before drop it.\n");
				return;
			}
		}
	}
	printf("There's any object with that name in your inventory.\n");
}

/*---INVENTORY FUNCTION---*/
void World::Inventory() const
{
	int i;
	//checks if the player has got items in his inventory
	if (player->num_items > 0)
	{
		printf("In your inventory you have (%i/%i):\n\n", player->num_items, player->max_items);
		for (i = 0; i < NUM_ITEMS; i++)
		{
			//shows the names and descriptions of the picked items
			if (items[i]->picked == true && items[i]->magic_gem == false)
			{
				items[i]->Look();
			}
		}
		printf("------------------\n");
		printf("MAGIC GEMS:\n\n");
		for (i = 0; i < NUM_ITEMS; i++)
		{
			//shows the names and descriptions of the picked gems
			if (items[i]->picked == true && items[i]->magic_gem == true)
			{
				items[i]->Look();
			}
		}
		printf("------------------\n");
	}
	else
	{
		printf("You don't have items in your inventory\n");
	}
}

/*---EQUIP FUNCTION---*/
void World::Equip(Vector<MyString> &commands) const
{
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		//checks if the commands introduced are correct (first command == equip && second command == <item_name>) 
		//it checks the slot it occupies (the part of the player where it will be equipped) too
		if (commands.size() == 2 && items[i]->part == Head && commands[1] == items[i]->name)
		{
			//checks if the item is in the inventory
			if (items[i]->picked == true)
			{
				//checks if there isn't an item equipped on that part yet
				if (player->head_item == false)
				{
					player->head_item = true;
					items[i]->equipped = true;
					player->armor += items[i]->armor;
					player->attack += items[i]->attack;
					player->hp += items[i]->hp;
					player->mana += items[i]->mana;
					printf("You equipped %s on your head.\n", items[i]->name.c_str());
					return;
				}
				else
				{
					printf("You have an item equipped on your head already.\n");
					return;
				}
			}
		}	

		else if (commands.size() == 2 && items[i]->part == Body && commands[1] == items[i]->name)
		{
			if (items[i]->picked == true)
			{
				if (player->body_item == false)
				{
					player->body_item = true;
					items[i]->equipped = true;
					player->armor += items[i]->armor;
					player->attack += items[i]->attack;
					player->hp += items[i]->hp;
					player->mana += items[i]->mana;
					printf("You equipped %s on your body.\n", items[i]->name.c_str());
					return;
				}
				else
				{
					printf("You have an item equipped on your body already.\n");
					return;
				}
			}
		}

		else if (commands.size() == 2 && items[i]->part == RHand && commands[1] == items[i]->name)
		{
			if (items[i]->picked == true)
			{
				if (player->RHand_item == false)
				{
					player->RHand_item = true;
					items[i]->equipped = true;
					player->armor += items[i]->armor;
					player->attack += items[i]->attack;
					player->hp += items[i]->hp;
					player->mana += items[i]->mana;
					printf("You equipped %s on your right hand.\n", items[i]->name.c_str());
					return;
				}
				else
				{
					printf("You have an item equipped on your right hand already.\n");
					return;
				}
			}
		}

		else if (commands.size() == 2 && items[i]->part == LHand && commands[1] == items[i]->name)
		{
			if (items[i]->picked == true)
			{
				if (player->LHand_item == false)
				{
					player->LHand_item = true;
					items[i]->equipped = true;
					player->armor += items[i]->armor;
					player->attack += items[i]->attack;
					player->hp += items[i]->hp;
					player->mana += items[i]->mana;
					printf("You equipped %s on your left hand.\n", items[i]->name.c_str());
					return;
				}
				else
				{
					printf("You have an item equipped on your left hand already.\n");
					return;
				}
			}
		}

		else if (commands.size() == 2 && items[i]->part == Legs && commands[1] == items[i]->name)
		{
			if (items[i]->picked == true)
			{
				if (player->legs_item == false)
				{
					player->legs_item = true;
					items[i]->equipped = true;
					player->armor += items[i]->armor;
					player->attack += items[i]->attack;
					player->hp += items[i]->hp;
					player->mana += items[i]->mana;
					printf("You equipped %s on your legs.\n", items[i]->name.c_str());
					return;
				}
				else
				{
					printf("You have an item equipped on your legs already.\n");
					return;
				}
			}
		}
		else if (commands.size() == 2 && items[i]->part == Non_Equipable && commands[1] == items[i]->name)
		{
			if (items[i]->picked == true)
			{
				printf("You can't equip with this item.\n");
				return;
			}
		}
	}
	printf("You don't have any item to equip with that name.\n");
}

/*---UNEQUIP FUNCTION---*/
void World::Unequip(Vector<MyString> &commands) const
{
	int i;
	for (i = 0; i < NUM_ITEMS; i++)
	{
		//checks if the commands introduced are correct (first command == unequip && second command == <item_name>) 
		if (commands.size() == 2 && commands[1] == items[i]->name)
		{
			//checks if the item is equipped
			if (items[i]->equipped == true)
			{
				//to empty the slot the item occupied
				switch (items[i]->part)
				{
				case Head:
				{
					player->head_item = false;
					break;
				}
				case Body:
				{
					player->body_item = false;
					break;
				}
				case RHand:
				{
					player->RHand_item = false;
					break;
				}
				case LHand:
				{
					player->LHand_item = false;
					break;
				}
				case Legs:
				{
					player->legs_item = false;
					break;
				}
				default:
				{
					printf("Unequipment failed.\n");
					break;
				}	
				}

				items[i]->equipped = false;
				player->armor -= items[i]->armor;
				player->attack -= items[i]->attack;
				player->hp -= items[i]->hp;
				player->mana -= items[i]->mana;
				printf("You have unequipped %s.\n", items[i]->name.c_str());
				return;
			}
		}
	}
	printf("You haven't got any item equipped with that name.\n");
}

/*---EQUIPMENT FUNCTION---*/
void World::Equipment() const
{
	MyString Head_item;
	MyString Body_item;
	MyString Legs_item;
	MyString LeftH_item;
	MyString RightH_item;

	//to show every item equipped 
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		if(items[i]->equipped == true)
		{
			if (items[i]->part == Head)
			{
				Head_item = items[i]->name;
			}
			else if (items[i]->part == Body)
			{
				Body_item = items[i]->name;
			}
			else if (items[i]->part == Legs)
			{
				Legs_item = items[i]->name;
			}
			else if (items[i]->part == LHand)
			{
				LeftH_item = items[i]->name;
			}
			else if (items[i]->part == RHand)
			{
				RightH_item = items[i]->name;
			}
		}
	}

	printf("\n--------------------\n");
	printf("HEAD = %s\n", Head_item.c_str());
	printf("BODY = %s\n", Body_item.c_str());
	printf("RIGHT HAND = %s\n", RightH_item.c_str());
	printf("LEFT HAND = %s\n", LeftH_item.c_str());
	printf("LEGS = %s", Legs_item.c_str());
	printf("\n--------------------\n");
}


/*---PUT FUNCTION---*/
void World::Put(Vector<MyString> &commands) const
{
	//checks if the commands introduced are correct
	if (commands.size() == 4 && commands[2] == "into")
	{
		for (int i = 0; i < NUM_ITEMS; i++)
		{
			//checks if the item you want to put is in your inventory and if it's not equipped
			if (commands[1] == items[i]->name && items[i]->picked == true && items[i]->equipped==false)
			{
				for (int j = 0; j < NUM_ITEMS; j++)
				{
					//checks if the last command introduced is the name of the container
					if (items[j]->name == commands[3] && items[j]->container == true)
					{
						//checks if the container is in the room
						if (items[j]->src == player->player_pos)
						{
							items[i]->inside = true;
							items[i]->src = items[j]->src;
							items[i]->picked = false;
							player->num_items--;
							printf("You put %s into %s\n", items[i]->name.c_str(), items[j]->name.c_str());
							return;
						}
						else if (items[j]->src != player->player_pos)
						{
							printf("You are trying to put an object inside a container that is not in this room.\n");
							return;
						}
					}
					else if (items[j]->name == commands[3] && items[j]->container == false)
					{
						printf("You are trying to put an item inside a non-container item.\nIt's an impossible action.\n");
						return;
					}
				}
			}
			else if (commands[1] == items[i]->name && items[i]->picked == false)
			{
				printf("You haven't got this item in you inventory.\n");
				return;
			}
			else if (commands[1] == items[i]->name && items[i]->equipped == true)
			{
				printf("You have to unequip this item first.\n");
				return;
			}
		}
		printf("Make sure you have introduced the correct names of the items.\n");
		return;
	}
	printf("You have introduced some invalid commands.\n");
}

/*---GET FUNCTION---*/
void World::Get(Vector<MyString> &commands) const
{
	//checks if the commands introduced are correct
	if (commands.size() == 4 && commands[2] == "from")
	{
		//checks if your inventory is full
		if (player->num_items < player->max_items)
		{
			for (int i = 0; i < NUM_ITEMS; i++)
			{
				//checks if the item you want to get isn't in your inventory, it's not equipped and it's in the room
				if (commands[1] == items[i]->name && items[i]->picked == false && items[i]->inside == true && items[i]->src && player->player_pos)
				{
					for (int j = 0; j < NUM_ITEMS; j++)
					{
						//checks if the last command introduced is the name of the container
						if (items[j]->name == commands[3] && items[j]->container == true)
						{
							//checks if the container is in the room
							if (items[j]->src == player->player_pos)
							{
								items[i]->inside = false;
								items[i]->picked = true;
								player->num_items++;
								printf("You got %s from %s\n", items[i]->name.c_str(), items[j]->name.c_str());
								return;
							}
							else if (items[j]->src != player->player_pos)
							{
								printf("You are trying to get an object from a container that is not in this room.\n");
								return;
							}
						}
						else if (items[j]->name == commands[3] && items[j]->container == false)
						{
							printf("You are trying to get an item from a non-container item.\nIt's an impossible action.\n");
							return;
						}
					}
				}
				else if (commands[1] == items[i]->name && items[i]->picked == true)
				{
					printf("You already have this item in your inventory.\n");
					return;
				}
			}
			printf("Make sure you have introduced the correct names of the items.\n");
			return;
		}
		else
		{
			printf("Your inventory is full, so you can't get more items.\n");
		}
	}
	else
	{
		printf("You have introduced some invalid commands.\n");
	}
}

World::~World()
{
	delete player;
}


