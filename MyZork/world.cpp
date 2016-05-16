#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#include"world.h"

World::World()
{

}

void World::CreateWorld() 
{
	/*---CREATE ROOMS---*/

	//BEDROOM (entities[0])
	entities.push_back(new Room("BEDROOM", "This is my room, what a mess.\nI can hear a very strange noise coming from under my bed.\nI should take a look.\n",ROOM));

	//GRIMGAR (entities[1])
	entities.push_back(new Room("GRIMGAR", "We are in Grimgar, Simon.\nIt's the capital city of Aincrad, this beautiful fantasy world.\nThis world is living a nightmare since the arrival of Rakdos,\nlord of the desolation.\n",ROOM));

	//TAVERN (entities[2])
	entities.push_back(new Room("TAVERN", "In this tavern we can buy new items and weapons to improve our abilities.\n", ROOM));

	//LAKE (entities[3])
	entities.push_back(new Room("LAKE", "What an enormous lake!\nIt's a nice day to take a dip.\nIf you stare at the bottom you can see a small grotto.\n", ROOM));

	//HILL (entities[4])
	entities.push_back(new Room("HILL", "This is the highest hill in the city.\nYou can see everything wonderful about Aincrad from up here,\nand the Tower of Rakdos, the Devil King...\n", ROOM));

	//SUPER GENERATOR (entities[5])
	entities.push_back(new Room("SUPER GENERATOR", "We are at the entrance of Rakdos Tower, the hell...\nNext to it the Super Generator is installed.\nThis huge device is the responsible for providing all the energy of the city.\n", ROOM));

	//PORTAL ROOM (entities[6])
	entities.push_back(new Room("PORTAL ROOM", "We have entered in a magical Room.\nCan you see the big Portal with a very strange inscriptions?\nIf you jump into it you can teleport to another place.\n", ROOM));

	//UNDERWATER CAVE (entities[7])
	entities.push_back(new Room("UNDERWATER CAVE", "Echo, echo, echo ...\nWe have to care if we want to leave this cave alive.\nIt's a very big and deep cave, so we will\nhave to defeat powerful enemies if you want to continue.\n", ROOM));

	//DRAGON'S RIFT (entities[8])
	entities.push_back(new Room("DRAGON'S RIFT", "It's very hot here...Wait!\nThis is the Dragon chamber.\nWe have to leave quickly before the Dragon returns.\n", ROOM));

	//FLOOR 1 (entities[9])
	entities.push_back(new Room("FLOOR 1", "This is the first floor of the tower.\nScary monsters and skeletons can appear, so let's fight them!\nWe have to care, some trapps have been scatteret throughout the building.\n", ROOM));

	//FLOOR 2 (entities[10])
	entities.push_back(new Room("FLOOR 2", "Good Job, Simon! We have reached the second floor.\nIt's a big room with some inscriptions on the walls.\n", ROOM));

	//TREASURE CHAMBER (entities[11])
	entities.push_back(new Room("TREASURE CHAMBER", "Yeah! Simon, this is the final room before the ultimate battle.\nLook all the fortune around us. It seems that this chamber is used to keep\nthe treasures Rakdos has stolen until now.\n", ROOM));
	
	//RAKDOS THRONE ROOM (entities[12])
	entities.push_back(new Room("RAKDOS THRONE ROOM", "What a big chamber!\nSimon, Rakdos is there, let's fight and defeat him!\n", ROOM));



	/*---CREATE EXITS---*/

	//PORTAL (entities[13])
	entities.push_back(new Exit("PORTAL\n", "What an strange Portal, let's cross it.\n", (Room*)entities[0], (Room*)entities[1], down, false, true, EXIT));

	//FOREST (entities[14])
	entities.push_back(new Exit("FOREST\n", "It's a big forest. So many people came\ninto the forest and never have returned.\n", (Room*)entities[1], (Room*)entities[3], west, false, true, EXIT));

	//SAND PATH (entities[15])
	entities.push_back(new Exit("SAND PATH\n", "A long path that connects this big lake with Grimgar.\n", (Room*)entities[3], (Room*)entities[1], east, false, true, EXIT));

	//TAVERN ENTRANCE (entities[16])
	entities.push_back(new Exit("TAVERN ENTRACE\n", "A big door to enter to the tavern.\n", (Room*)entities[1], (Room*)entities[2], east, true, false, EXIT));

	//TAVERN EXIT (entities[17])
	entities.push_back(new Exit("TAVERN EXIT\n", "It's the big door to exit the tavern.\n", (Room*)entities[2], (Room*)entities[1], west, true, true, EXIT));

	//STONE PATH (entities[18])
	entities.push_back(new Exit("STONE PATH\n", "At the end of this path you can see the Hill.\n", (Room*)entities[1], (Room*)entities[4], north, false, true, EXIT));

	//STONE PATH (entities[19])
	entities.push_back(new Exit("STONE PATH\n", "At the end of this path you can see Grimgar.\n", (Room*)entities[4], (Room*)entities[1], south, false, true, EXIT));

	//TENEBROUS PATH (entities[20])
	entities.push_back(new Exit("TENEBROUS PATH\n", "This road leads to the entrance of the tower,\nwhere the super-generator is installed\n", (Room*)entities[4], (Room*)entities[5], north, false, true, EXIT));

	//ROCKY CLIMB (entities[21])
	entities.push_back(new Exit("ROCKY CLIMB\n", "You have to climb this steep path if you want to return to the high cliff.\n", (Room*)entities[5], (Room*)entities[4], south, false, true, EXIT));

	//THE BIG ENTRANCE (entities[22])
	entities.push_back(new Exit("THE BIG ENTRANCE\n", "Wow, this door is too big, and scary...\nAre you sure you want to enter?\n", (Room*)entities[5], (Room*)entities[9], west, true, false, EXIT));

	//CHALLENGE 1 (entities[23])
	entities.push_back(new Exit("THE STONE DOOR\n", "This door is too heavy and big.\nYou have to use your magic abilities if you want to continue to the next floor.\n", (Room*)entities[9], (Room*)entities[10], up, true, false, EXIT));

	//CHALLENGE 2 (entities[24])
	entities.push_back(new Exit("INVISIBLE STAIRS\n", "What is going on? There are no stairs to keep going up.\nLook, there's a hatch in the roof with a padlock that maybe we can open with our key.\n", (Room*)entities[10], (Room*)entities[11], up, true, false, EXIT));

	//FINAL DOOR (entities[25])
	entities.push_back(new Exit("THE FINAL DOOR\n", "Are you sure you want to open this door?\nThe ultimate challenge is waiting behind it...\n", (Room*)entities[11], (Room*)entities[12], east, true, false, EXIT));

	//TELEPORTER (entities[26])
	entities.push_back(new Exit("TELEPORTER\n", "It's the end of the travel, Simon.\nYou can return to your real world by crossing this teleporter.\n", (Room*)entities[12], (Room*)entities[0], south, false, true, EXIT));

	//UNDERWATER PATH (entities[27])
	entities.push_back(new Exit("UNDERWATER PATH\n", "At the end of this path we can access to the underground zone of Aincrad.\n", (Room*)entities[3], (Room*)entities[7], down, false, true, EXIT));

	//UNDERGROUND CORRIDOR (entities[28])
	entities.push_back(new Exit("UNDERGROUND CORRIDOR\n", "Continue straight through this corridor to arrive at the Dragon Rift.\n", (Room*)entities[7], (Room*)entities[8], east, false, true, EXIT));

	//NARROW PATH (entities[29])
	entities.push_back(new Exit("NARROW PATH\n", "This path will take you to the magical room, where the portal is placed.\n", (Room*)entities[8], (Room*)entities[6], south, false, true, EXIT));

	//MAGIC TUNNEL (entities[30])
	entities.push_back(new Exit("MAGIC TUNNEL\n", "This tunnel accessible through the portal connects with Grimgar.\n", (Room*)entities[6], (Room*)entities[1], south, false, true, EXIT));


	/*---CREATE ITEMS---*/

	//SWORD (entities[31])
	entities.push_back(new Item("SWORD", "This weapon is forged by The Five Blacksmiths, the best\nartisans of Aincrad, with materials whose origin is unknown.\n", (Room*)entities[1], RHand, 10, 0, 0, 0, ITEM));

	//SHIELD (entities[32])
	entities.push_back(new Item("SHIELD", "This emblematic blue, red and white shield belonged to the Sergeant\nEurope, the protector of Aincrad. It's made with the most resistant material\nin the world: Amadantium\n", (Room*)entities[2], LHand, 0, 0, 0, 10, ITEM));

	//KEY (entities[33])
	entities.push_back(new Item("KEY", "With this magic key you will be able to open all the doors and trapdoors\nto continue with our journey, Simon.\n", (Room*)entities[6], Non_Equipable, 0, 0, 0, 0, ITEM));

	//HELMET (entities[34])
	entities.push_back(new Item("HELMET", "I've heard that the one who goes to battle with this\niron helmet equipped is invencible, but this story is just a myth.\n", (Room*)entities[5], Head, 0, 0, 5, 5, ITEM));

	//BREADSPLATE (entities[35])
	entities.push_back(new Item("BREADSPLATE", "What a beautiful armor! It gives more stamina and resistance\nagainst monsters and creatures\n", (Room*)entities[4], Body, 0, 0, 5, 5, ITEM));

	//GREAVES (entities[36])
	entities.push_back(new Item("GREAVES", "This greaves will give you more speed, but this is not useful in this game...\n", (Room*)entities[9], Legs, 0, 0, 0, 5, ITEM));

	//AXE (entities[37])
	entities.push_back(new Item("AXE", "Use this powerful and big axe to destroy hundreds and hundreds of enemies,\nlike Nanoc the Barbarian.\n", (Room*)entities[7], RHand, 10, 0, 0, 0, ITEM));

	//RING (entities[38])
	entities.push_back(new Item("RING", "This magic artefact is called 'The One Ring' it can increase your magical\npower.Look closely, there is an inscription: 'One ring to rule them all'.\n", (Room*)entities[8], LHand, 0, 20, 10, 0, ITEM));

	//TRUNK (entities[39])
	entities.push_back(new Item("TRUNK", "You can put all the items you want into this magic trunk if\nyou run out of inventory space.\n", (Room*)entities[2], Non_Equipable, 0, 0, 0, 0, ITEM));
	((Item*)entities[39])->container = true;

	/*----------------------*/

	/*  Magic Gems  */
	//AKA (entities[40])
	entities.push_back(new Item("AKA", "This is the red gem. It allows you to control fire\n", (Room*)entities[8], Non_Equipable, 0, 0, 0, 0, ITEM));
	((Item*)entities[40])->magic_gem = true;

	//AO (entities[41])
	entities.push_back(new Item("AO", "This is the blue gem. It allows you to control water\n", (Room*)entities[3], Non_Equipable, 0, 0, 0, 0, ITEM));
	((Item*)entities[41])->magic_gem = true;

	//KIIRO (entities[42])
	entities.push_back(new Item("KIIRO", "This is the yellow gem. It allows you to control electricity\n", (Room*)entities[5], Non_Equipable, 0, 0, 0, 0, ITEM));
	((Item*)entities[42])->magic_gem = true;

	//KURO (entities[43])
	entities.push_back(new Item("KURO", "This is the black gem. It allows you to control darkness\n", (Room*)entities[6], Non_Equipable, 0, 0, 0, 0, ITEM));
	((Item*)entities[43])->magic_gem = true;

	//SHIRO (entities[44])
	entities.push_back(new Item("SHIRO", "This is the white gem. It allows you to control brightness\n", (Room*)entities[9], Non_Equipable, 0, 0, 0, 0, ITEM));
	((Item*)entities[44])->magic_gem = true;
	
	/*----------------------*/

	//EXCALIBUR (entities[45])
	entities.push_back(new Item("EXCABILUR", "This legendary weapon belonged to King Bradley, the king of kings,\nwho has goberned Aincriad since his death, 500 years ago.\nIt's said this sword has extraordinary properties.\n", (Room*)entities[11], RHand, 50, 50, 0, 0, ITEM));

	//EAGIS (entities[46])
	entities.push_back(new Item("EAGIS", "What is that!? This is the mythic shield of Seuz,\nthe strongest god of all times! I think it will give you the enough\nresistance to withstand the last battle.\n", (Room*)entities[11], LHand, 0, 50, 0, 50, ITEM));

	//VEST (entities[47])
	entities.push_back(new Item("VEST", "Look at this strange vest. I heared that the bearer of\nthis magic clothing gets magical powers like super strength, enhaced\nstamina and mind control.\n", (Room*)entities[11], Body, 20, 20, 20, 20, ITEM));

	//PLAYER (entities[48])
	entities.push_back(new Player("SIMON", "A nice kid\n", PLAYER, 100, 500, 20, 0));

	player = (Player*)entities[48];
}


/*---LOOK FUNCTION---*/
void World::Look(int pos, const Vector<MyString> &commands) const
{
	int i; //Counters to consider the correct room/exit when you are looking
	player->player_pos = (Room*)entities[pos];

	if (commands.size() == 2 && (commands[1] == "north" || commands[1] == "n")) //checks if commands introduced are correct
	{
		for (i = 0; i < entities.size(); i++)
		{
			if (entities[i]->type == EXIT && ((Exit*)entities[i])->src == player->player_pos && ((Exit*)entities[i])->direction == north) //Case 1: shows the name and description of the exit placed in the chosen direction
			{
				((Exit*)entities[i])->Look();
				return;
			}
		}
		printf("\nThere's nothing to look here.\n");  //Case 2: there isn't any exit placed in the chosen direction
	}

	else if (commands.size() == 2 && (commands[1] == "south" || commands[1] == "s"))
	{
		for (i = 0; i < entities.size(); i++)
		{
			if (entities[i]->type == EXIT && ((Exit*)entities[i])->src == player->player_pos && ((Exit*)entities[i])->direction == south)
			{
				((Exit*)entities[i])->Look();
				return;
			}
		}
		printf("\nThere's nothing to look here.\n");
	}

	else if (commands.size() == 2 && (commands[1] == "east" || commands[1] == "e"))
	{
		for (i = 0; i < entities.size(); i++)
		{
			if (entities[i]->type == EXIT && ((Exit*)entities[i])->src == player->player_pos && ((Exit*)entities[i])->direction == east)
			{
				((Exit*)entities[i])->Look();
				return;
			}
		}
		printf("\nThere's nothing to look here.\n");
	}

	else if (commands.size() == 2 && (commands[1] == "west" || commands[1] == "w"))
	{
		for (i = 0; i < entities.size(); i++)
		{
			if (entities[i]->type == EXIT && ((Exit*)entities[i])->src == player->player_pos && ((Exit*)entities[i])->direction == west)
			{
				((Exit*)entities[i])->Look();
				return;
			}
		}
		printf("\nThere's nothing to look here.\n");
	}

	else if (commands.size() == 2 && (commands[1] == "up" || commands[1] == "u"))
	{
		for (i = 0; i < entities.size(); i++)
		{
			if (entities[i]->type == EXIT && ((Exit*)entities[i])->src == player->player_pos && ((Exit*)entities[i])->direction == up)
			{
				((Exit*)entities[i])->Look();
				return;
			}
		}
		printf("\nThere's nothing to look here.\n");
	}

	else if (commands.size() == 2 && (commands[1] == "down" || commands[1] == "d"))
	{
		for (i = 0; i < entities.size(); i++)
		{
			if (entities[i]->type == EXIT && ((Exit*)entities[i])->src == player->player_pos && ((Exit*)entities[i])->direction == down)
			{
				((Exit*)entities[i])->Look();
				return;
			}
		}
		printf("\nThere's nothing to look here.\n");
	}

	else if (commands.size() == 2 && (commands[1] == "trunk"))
	{
		if (((Item*)entities[39])->src == player->player_pos)
		{
			printf("Items inside the TRUNK:\n\n");
			for (i = 0; i < entities.size(); i++)
			{
				if (entities[i]->type == ITEM && ((Item*)entities[i])->inside == true)
				{
					printf("%s\n%s\n", ((Item*)entities[i])->name.c_str(), ((Item*)entities[i])->description.c_str());
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
		((Room*)entities[pos])->Look();
		printf("\n--------------------------\n");
		printf("\nItems you can find here:\n\n");
		for (i = 0; i < entities.size(); i++)
		{
			if (entities[i]->type == ITEM && player->player_pos == ((Item*)entities[i])->src && ((Item*)entities[i])->picked == false && ((Item*)entities[i])->inside == false)
			{
				((Item*)entities[i])->Look();
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
	printf("get <item> from <containter> = to get an item that's inside\nanother item (container).\n");
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
void World::Open(int pos, const Vector<MyString>&commands) const
{
	int i;  //Counter to consider the correct exit
	player->player_pos = ((Room*)entities[pos]);

	if (((Item*)entities[33])->picked == true) //checks if you have the key picked (necessary to open doors)
	{

		if (commands.size() == 3 && (commands[1] == "north" || commands[1] == "n") && commands[2] == "door") //checks if commands introduced are correct
		{
			for (i = 0; i < entities.size(); i++)
			{
				//OPEN CONDITION: the exit you want to "open" has a door, and its door is closed
				if (entities[i]->type == EXIT && ((Exit*)entities[i])->src == player->player_pos && ((Exit*)entities[i])->direction == north && ((Exit*)entities[i])->open == false)
				{
					((Exit*)entities[i])->open = true;
					printf("\nYou opened the door.\n");
					return;
				}
			}
			printf("\nThere's nothing to open here.\n");
		}

		else if (commands.size() == 3 && (commands[1] == "south" || commands[1] == "s"))
		{
			for (i = 0; i < entities.size(); i++)
			{
				if (entities[i]->type == EXIT && ((Exit*)entities[i])->src == player->player_pos && ((Exit*)entities[i])->direction == south && ((Exit*)entities[i])->open == false)
				{
					((Exit*)entities[i])->open = true;
					printf("\nYou opened the door.\n");
					return;
				}
			}
			printf("\nThere's nothing to open here.\n");
		}

		else if (commands.size() == 3 && (commands[1] == "east" || commands[1] == "e") && commands[2] == "door")
		{
			for (i = 0; i < entities.size(); i++)
			{
				if (entities[i]->type == EXIT && ((Exit*)entities[i])->src == player->player_pos && ((Exit*)entities[i])->direction == east && ((Exit*)entities[i])->open == false)
				{
					((Exit*)entities[i])->open = true;
					printf("\nYou opened the door.\n");
					return;
				}
			}
			printf("\nThere's nothing to open here.\n");
		}

		else if (commands.size() == 3 && (commands[1] == "west" || commands[1] == "w") && commands[2] == "door")
		{
			for (i = 0; i < entities.size(); i++)
			{
				if (entities[i]->type == EXIT && ((Exit*)entities[i])->src == player->player_pos && ((Exit*)entities[i])->direction == west && ((Exit*)entities[i])->open == false)
				{
					((Exit*)entities[i])->open = true;
					printf("You opened the door.\n");
					return;
				}
			}
			printf("\nThere's nothing to open here.\n");
		}

		else if (commands.size() == 3 && (commands[1] == "up" || commands[1] == "u") && commands[2] == "door")
		{
			for (i = 0; i < entities.size(); i++)
			{
				if (entities[i]->type == EXIT && ((Exit*)entities[i])->src == player->player_pos && ((Exit*)entities[i])->direction == up && ((Exit*)entities[i])->open == false)
				{
					((Exit*)entities[i])->open = true;
					printf("\nYou opened the door.\n");
					return;
				}
			}
			printf("\nThere's nothing to open here.\n");
		}

		else if (commands.size() == 3 && (commands[1] == "down" || commands[1] == "d") && commands[2] == "door")
		{
			for (i = 0; i < entities.size(); i++)
			{
				if (entities[i]->type == EXIT && ((Exit*)entities[i])->src == player->player_pos && ((Exit*)entities[i])->direction == down && ((Exit*)entities[i])->open == false)
				{
					((Exit*)entities[i])->open = true;
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
void World::Close(int pos, const Vector<MyString> &commands) const
{
	int i;
	player->player_pos = (Room*)entities[pos];

	if (commands.size() == 3 && (commands[1] == "north" || commands[1] == "n") && commands[2] == "door") //checks if commands introduced are correct
	{
		for (i = 0; i < entities.size(); i++)
		{
			//CLOSE CONDITION: the exit you want to "close" has a door, and its door is opened
			if (entities[i]->type == EXIT && ((Exit*)entities[i])->src == player->player_pos && ((Exit*)entities[i])->direction == north && ((Exit*)entities[i])->open == true && ((Exit*)entities[i])->door == true)
			{
				((Exit*)entities[i])->open = false;
				printf("\nYou closed the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to close here.\n");
	}

	else if (commands.size() == 3 && (commands[1] == "south" || commands[1] == "s") && commands[2] == "door")
	{
		for (i = 0; i < entities.size(); i++)
		{
			if (entities[i]->type == EXIT && ((Exit*)entities[i])->src == player->player_pos && ((Exit*)entities[i])->direction == south && ((Exit*)entities[i])->open == true && ((Exit*)entities[i])->door == true)
			{
				((Exit*)entities[i])->open = false;
				printf("\nYou closed the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to close here.\n");
	}

	else if (commands.size() == 3 && (commands[1] == "east" || commands[1] == "e") && commands[2] == "door")
	{
		for (i = 0; i < entities.size(); i++)
		{
			if (entities[i]->type == EXIT && ((Exit*)entities[i])->src == player->player_pos && ((Exit*)entities[i])->direction == east && ((Exit*)entities[i])->open == true && ((Exit*)entities[i])->door == true)
			{
				((Exit*)entities[i])->open = false;
				printf("\nYou closed the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to close here.\n");
	}

	else if (commands.size() == 3 && (commands[1] == "west" || commands[1] == "w") && commands[2] == "door")
	{
		for (i = 0; i < entities.size(); i++)
		{
			if (entities[i]->type == EXIT && ((Exit*)entities[i])->src == player->player_pos && ((Exit*)entities[i])->direction == west && ((Exit*)entities[i])->open == true && ((Exit*)entities[i])->door == true)
			{
				((Exit*)entities[i])->open = false;
				printf("\nYou closed the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to close here.\n");
	}

	else if (commands.size() == 3 && (commands[1] == "up" || commands[1] == "u") && commands[2] == "door")
	{
		for (i = 0; i < entities.size(); i++)
		{
			if (entities[i]->type == EXIT && ((Exit*)entities[i])->src == player->player_pos && ((Exit*)entities[i])->direction == up && ((Exit*)entities[i])->open == true && ((Exit*)entities[i])->door == true)
			{
				((Exit*)entities[i])->open = false;
				printf("\nYou closed the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to close here.\n");
	}

	else if (commands.size() == 3 && (commands[1] == "down" || commands[1] == "d") && commands[2] == "door")
	{
		for (i = 0; i < entities.size(); i++)
		{
			if (entities[i]->type == EXIT && ((Exit*)entities[i])->src == player->player_pos && ((Exit*)entities[i])->direction == down && ((Exit*)entities[i])->open == true && ((Exit*)entities[i])->door == true)
			{
				((Exit*)entities[i])->open = false;
				printf("\nYou closed the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to close here.\n");
	}
}

/*---PICK FUNCTION---*/
void World::Pick(const Vector<MyString> &commands) const
{
	//checks if inventory is full (so you can't pick more objects)
	if (player->num_items < player->max_items)
	{
		for (int i = 0; i < entities.size(); i++)
		{
			//checks if the commands introduced are correct (first command == pick && second command == <item_name>) and if the item is not in the inventory yet
			if (entities[i]->type == ITEM && commands.size() == 2 && commands[1] == ((Item*)entities[i])->name && ((Item*)entities[i])->src == player->player_pos && ((Item*)entities[i])->picked == false)
			{
				if (((Item*)entities[i])->container == false)
				{
					((Item*)entities[i])->picked = true;
					player->num_items++;
					printf("You picked %s\n", ((Item*)entities[i])->name.c_str());
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
void World::Drop(const Vector<MyString> &commands) const
{
	srand(time(NULL));
	for (int i = 0; i < entities.size(); i++)
	{
		//checks if the commands introduced are correct (first command == drop && second command == <item_name>) and if the item is in the inventory
		if (entities[i]->type == ITEM && commands.size() == 2 && ((Item*)entities[i])->name == commands[1] && ((Item*)entities[i])->picked == true)
		{
			//checks if the the item is not equipped...
			if (((Item*)entities[i])->equipped == false)
			{
				int random = rand() % NUM_ROOMS;
				((Item*)entities[i])->picked = false;
				((Item*)entities[i])->src = ((Room*)entities[random]);//WormHole: sends the item to a random room.
				player->num_items--;

				printf("\n");
				printf("d8888b. db       .d88b.  d8888b. db\n");
				printf("88  `8D 88      .8P  Y8. 88  `8D 88\n");
				printf("88oodD' 88      88    88 88oodD' YP\n");
				printf("88~~~   88      88    88 88~~~\n");
				printf("88      88booo. `8b  d8' 88      db\n");
				printf("88      Y88888P  `Y88P'  88      YP\n");
				printf("\n");
                                         				       
				printf("You dropped %s and the Wormhole made it desappear.\n", ((Item*)entities[i])->name.c_str());
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
		for (i = 0; i < entities.size(); i++)
		{
			//shows the names and descriptions of the picked items
			if (entities[i]->type == ITEM && ((Item*)entities[i])->picked == true && ((Item*)entities[i])->magic_gem == false)
			{
				((Item*)entities[i])->Look();
			}
		}
		printf("------------------\n");
		printf("MAGIC GEMS:\n\n");
		for (i = 0; i < entities.size(); i++)
		{
			//shows the names and descriptions of the picked gems
			if (entities[i]->type == ITEM && ((Item*)entities[i])->picked == true && ((Item*)entities[i])->magic_gem == true)
			{
				((Item*)entities[i])->Look();
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
void World::Equip(const Vector<MyString> &commands) const
{
	for (int i = 0; i < entities.size(); i++)
	{
		//checks if the commands introduced are correct (first command == equip && second command == <item_name>) 
		//it checks the slot it occupies (the part of the player where it will be equipped) too
		if (entities[i]->type == ITEM && commands.size() == 2 && ((Item*)entities[i])->part == Head && commands[1] == ((Item*)entities[i])->name)
		{
			//checks if the item is in the inventory
			if (((Item*)entities[i])->picked == true)
			{
				//checks if there isn't an item equipped on that part yet
				if (player->head_item == false)
				{
					player->head_item = true;
					((Item*)entities[i])->equipped = true;
					player->armor += ((Item*)entities[i])->armor;
					player->attack += ((Item*)entities[i])->attack;
					player->hp += ((Item*)entities[i])->hp;
					player->mana += ((Item*)entities[i])->mana;
					printf("You equipped %s on your head.\n", ((Item*)entities[i])->name.c_str());
					return;
				}
				else
				{
					printf("You have an item equipped on your head already.\n");
					return;
				}
			}
		}	

		else if (entities[i]->type == ITEM && commands.size() == 2 && ((Item*)entities[i])->part == Body && commands[1] == ((Item*)entities[i])->name)
		{
			if (((Item*)entities[i])->picked == true)
			{
				if (player->body_item == false)
				{
					player->body_item = true;
					((Item*)entities[i])->equipped = true;
					player->armor += ((Item*)entities[i])->armor;
					player->attack += ((Item*)entities[i])->attack;
					player->hp += ((Item*)entities[i])->hp;
					player->mana += ((Item*)entities[i])->mana;
					printf("You equipped %s on your body.\n", ((Item*)entities[i])->name.c_str());
					return;
				}
				else
				{
					printf("You have an item equipped on your body already.\n");
					return;
				}
			}
		}

		else if (entities[i]->type == ITEM && commands.size() == 2 && ((Item*)entities[i])->part == RHand && commands[1] == ((Item*)entities[i])->name)
		{
			if (((Item*)entities[i])->picked == true)
			{
				if (player->RHand_item == false)
				{
					player->RHand_item = true;
					((Item*)entities[i])->equipped = true;
					player->armor += ((Item*)entities[i])->armor;
					player->attack += ((Item*)entities[i])->attack;
					player->hp += ((Item*)entities[i])->hp;
					player->mana += ((Item*)entities[i])->mana;
					printf("You equipped %s on your right hand.\n", ((Item*)entities[i])->name.c_str());
					return;
				}
				else
				{
					printf("You have an item equipped on your right hand already.\n");
					return;
				}
			}
		}

		else if (entities[i]->type == ITEM && commands.size() == 2 && ((Item*)entities[i])->part == LHand && commands[1] == ((Item*)entities[i])->name)
		{
			if (((Item*)entities[i])->picked == true)
			{
				if (player->LHand_item == false)
				{
					player->LHand_item = true;
					((Item*)entities[i])->equipped = true;
					player->armor += ((Item*)entities[i])->armor;
					player->attack += ((Item*)entities[i])->attack;
					player->hp += ((Item*)entities[i])->hp;
					player->mana += ((Item*)entities[i])->mana;
					printf("You equipped %s on your left hand.\n", ((Item*)entities[i])->name.c_str());
					return;
				}
				else
				{
					printf("You have an item equipped on your left hand already.\n");
					return;
				}
			}
		}

		else if (entities[i]->type == ITEM && commands.size() == 2 && ((Item*)entities[i])->part == Legs && commands[1] == ((Item*)entities[i])->name)
		{
			if (((Item*)entities[i])->picked == true)
			{
				if (player->legs_item == false)
				{
					player->legs_item = true;
					((Item*)entities[i])->equipped = true;
					player->armor += ((Item*)entities[i])->armor;
					player->attack += ((Item*)entities[i])->attack;
					player->hp += ((Item*)entities[i])->hp;
					player->mana += ((Item*)entities[i])->mana;
					printf("You equipped %s on your legs.\n", ((Item*)entities[i])->name.c_str());
					return;
				}
				else
				{
					printf("You have an item equipped on your legs already.\n");
					return;
				}
			}
		}
		else if (entities[i]->type == ITEM && commands.size() == 2 && ((Item*)entities[i])->part == Non_Equipable && commands[1] == ((Item*)entities[i])->name)
		{
			if (((Item*)entities[i])->picked == true)
			{
				printf("You can't equip this item.\n");
				return;
			}
		}
	}
	printf("You don't have any item to equip with that name.\n");
}

/*---UNEQUIP FUNCTION---*/
void World::Unequip(const Vector<MyString> &commands) const
{
	int i;
	for (i = 0; i < entities.size(); i++)
	{
		if (entities[i]->type == ITEM)
		{
			//checks if the commands introduced are correct (first command == unequip && second command == <item_name>) 
			if (commands.size() == 2 && commands[1] == ((Item*)entities[i])->name)
			{
				//checks if the item is equipped
				if (((Item*)entities[i])->equipped == true)
				{
					//to empty the slot the item occupied
					switch (((Item*)entities[i])->part)
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

					((Item*)entities[i])->equipped = false;
					player->armor -= ((Item*)entities[i])->armor;
					player->attack -= ((Item*)entities[i])->attack;
					player->hp -= ((Item*)entities[i])->hp;
					player->mana -= ((Item*)entities[i])->mana;
					printf("You have unequipped %s.\n", ((Item*)entities[i])->name.c_str());
					return;
				}
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
	for (int i = 0; i < entities.size(); i++)
	{
		if (entities[i]->type == ITEM)
		{
			if (((Item*)entities[i])->equipped == true)
			{
				if (((Item*)entities[i])->part == Head)
				{
					Head_item = ((Item*)entities[i])->name;
				}
				else if (((Item*)entities[i])->part == Body)
				{
					Body_item = ((Item*)entities[i])->name;
				}
				else if (((Item*)entities[i])->part == Legs)
				{
					Legs_item = ((Item*)entities[i])->name;
				}
				else if (((Item*)entities[i])->part == LHand)
				{
					LeftH_item = ((Item*)entities[i])->name;
				}
				else if (((Item*)entities[i])->part == RHand)
				{
					RightH_item = ((Item*)entities[i])->name;
				}
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
void World::Put(const Vector<MyString> &commands) const
{
	//checks if the commands introduced are correct
	if (commands.size() == 4 && commands[2] == "into")
	{
		for (int i = 0; i < entities.size(); i++)
		{
			if (entities[i]->type == ITEM)
			{
				//checks if the item you want to put is in your inventory and if it's not equipped
				if (commands[1] == ((Item*)entities[i])->name && ((Item*)entities[i])->picked == true && ((Item*)entities[i])->equipped == false)
				{
					for (int j = 0; j < entities.size(); j++)
					{
						if (entities[j]->type == ITEM)
						{
							//checks if the last command introduced is the name of the container
							if (((Item*)entities[j])->name == commands[3] && ((Item*)entities[j])->container == true)
							{
								//checks if the container is in the room
								if (((Item*)entities[j])->src == player->player_pos)
								{
									((Item*)entities[i])->inside = true;
									((Item*)entities[i])->src = ((Item*)entities[j])->src;
									((Item*)entities[i])->picked = false;
									player->num_items--;
									printf("You put %s into %s\n", ((Item*)entities[i])->name.c_str(), ((Item*)entities[j])->name.c_str());
									return;
								}
								else if (((Item*)entities[j])->src != player->player_pos)
								{
									printf("You are trying to put an object inside a container that is not in this room.\n");
									return;
								}
							}
							else if (((Item*)entities[j])->name == commands[3] &&((Item*)entities[j])->container == false)
							{
								printf("You are trying to put an item inside a non-container item.\nIt's an impossible action.\n");
								return;
							}
						}
					}
				}
				else if (commands[1] == ((Item*)entities[i])->name && ((Item*)entities[i])->picked == false)
				{
					printf("You haven't got this item in you inventory.\n");
					return;
				}
				else if (commands[1] == ((Item*)entities[i])->name && ((Item*)entities[i])->equipped == true)
				{
					printf("You have to unequip this item first.\n");
					return;
				}
			}
		}
		printf("Make sure you have introduced the correct names of the items.\n");
		return;
	}
	printf("You have introduced some invalid commands.\n");
}

/*---GET FUNCTION---*/
void World::Get(const Vector<MyString> &commands) const
{
	//checks if the commands introduced are correct
	if (commands.size() == 4 && commands[2] == "from")
	{
		//checks if your inventory is full
		if (player->num_items < player->max_items)
		{
			for (int i = 0; i < entities.size(); i++)
			{
				if (entities[i]->type == ITEM)
				{
					//checks if the item you want to get isn't in your inventory, it's not equipped and it's in the room
					if (commands[1] == ((Item*)entities[i])->name && ((Item*)entities[i])->picked == false && ((Item*)entities[i])->inside == true && ((Item*)entities[i])->src && player->player_pos)
					{
						for (int j = 0; j < entities.size(); j++)
						{
							if (entities[j]->type == ITEM)
							{
								//checks if the last command introduced is the name of the container
								if (((Item*)entities[j])->name == commands[3] && ((Item*)entities[j])->container == true)
								{
									//checks if the container is in the room
									if (((Item*)entities[j])->src == player->player_pos)
									{
										((Item*)entities[i])->inside = false;
										((Item*)entities[i])->picked = true;
										player->num_items++;
										printf("You got %s from %s\n", ((Item*)entities[i])->name.c_str(), ((Item*)entities[j])->name.c_str());
										return;
									}
									else if (((Item*)entities[j])->src != player->player_pos)
									{
										printf("You are trying to get an object from a container that is not in this room.\n");
										return;
									}
								}
								else if (((Item*)entities[j])->name == commands[3] && ((Item*)entities[j])->container == false)
								{
									printf("You are trying to get an item from a non-container item.\nIt's an impossible action.\n");
									return;
								}
							}
						}
					}
					else if (commands[1] == ((Item*)entities[i])->name && ((Item*)entities[i])->picked == true)
					{
						printf("You already have this item in your inventory.\n");
						return;
					}
				}
				printf("Make sure you have introduced the correct names of the items.\n");
				return;
			}
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
	int i;
	delete player;
	for (i = 0; i < entities.size(); i++)
	{
		delete entities[i];
	}

}


