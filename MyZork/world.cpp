#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#include"world.h"

World::World(){}

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
	entities.push_back(new Item("SWORD", "This weapon is forged by The Five Blacksmiths, the best\nartisans of Aincrad, with materials whose origin is unknown.\n", (Room*)entities[1], RHand, 10, 0, 0, 0, ITEM, 150));

	//SHIELD (entities[32])
	entities.push_back(new Item("SHIELD", "This emblematic blue, red and white shield belonged to the Sergeant\nEurope, the protector of Aincrad. It's made with the most resistant material\nin the world: Amadantium\n", (Room*)entities[2], LHand, 0, 0, 0, 10, ITEM, 150));

	//KEY (entities[33])
	entities.push_back(new Item("KEY", "With this magic key you will be able to open all the doors and trapdoors\nto continue with our journey, Simon.\n", (Room*)entities[6], Non_Equipable, 0, 0, 0, 0, ITEM, 0));

	//HELMET (entities[34])
	entities.push_back(new Item("HELMET", "I've heard that the one who goes to battle with this\niron helmet equipped is invencible, but this story is just a myth.\n", (Room*)entities[5], Head, 0, 0, 5, 5, ITEM,100));
	entities[5]->list.push_back(entities[34]);

	//BREADSPLATE (entities[35])
	entities.push_back(new Item("BREADSPLATE", "What a beautiful armor! It gives more stamina and resistance\nagainst monsters and creatures\n", (Room*)entities[4], Body, 0, 0, 5, 5, ITEM,200));
	entities[4]->list.push_back(entities[35]);

	//GREAVES (entities[36])
	entities.push_back(new Item("GREAVES", "This greaves will give you more speed, but this is not useful in this game...\n", (Room*)entities[9], Legs, 0, 0, 0, 5, ITEM, 50));

	//AXE (entities[37])
	entities.push_back(new Item("AXE", "Use this powerful and big axe to destroy hundreds and hundreds of enemies,\nlike Nanoc the Barbarian.\n", (Room*)entities[7], RHand, 10, 0, 0, 0, ITEM, 150));
	entities[7]->list.push_back(entities[37]);

	//RING (entities[38])
	entities.push_back(new Item("RING", "This magic artefact is called 'The One Ring' it can increase your magical\npower.Look closely, there is an inscription: 'One ring to rule them all'.\n", (Room*)entities[8], LHand, 0, 20, 10, 0, ITEM,200));
	entities[8]->list.push_back(entities[38]);

	//TRUNK (entities[39])
	entities.push_back(new Item("TRUNK", "You can put all the items you want into this magic trunk if\nyou run out of inventory space.\n", (Room*)entities[2], Non_Equipable, 0, 0, 0, 0, ITEM, 0));
	((Item*)entities[39])->container = true;
	entities[2]->list.push_back(entities[39]);

	/*----------------------*/

	/*  Magic Gems  */
	//AKA (entities[40])
	entities.push_back(new Item("AKA", "This is the red gem. It allows you to control fire\n", (Room*)entities[8], Non_Equipable, 0, 0, 0, 0, ITEM, 0));
	((Item*)entities[40])->magic_gem = true;
	

	//AO (entities[41])
	entities.push_back(new Item("AO", "This is the blue gem. It allows you to control water\n", (Room*)entities[3], Non_Equipable, 0, 0, 0, 0, ITEM, 0));
	((Item*)entities[41])->magic_gem = true;
	

	//KIIRO (entities[42])
	entities.push_back(new Item("KIIRO", "This is the yellow gem. It allows you to control electricity\n", (Room*)entities[5], Non_Equipable, 0, 0, 0, 0, ITEM, 0));
	((Item*)entities[42])->magic_gem = true;
	

	//KURO (entities[43])
	entities.push_back(new Item("KURO", "This is the black gem. It allows you to control darkness\n", (Room*)entities[6], Non_Equipable, 0, 0, 0, 0, ITEM, 0));
	((Item*)entities[43])->magic_gem = true;
	

	//SHIRO (entities[44])
	entities.push_back(new Item("SHIRO", "This is the white gem. It allows you to control brightness\n", (Room*)entities[9], Non_Equipable, 0, 0, 0, 0, ITEM, 0));
	((Item*)entities[44])->magic_gem = true;

	
	/*----------------------*/

	//EXCABILUR (entities[45])
	entities.push_back(new Item("EXCABILUR", "This legendary weapon belonged to King Bradley, the king of kings,\nwho has goberned Aincriad since his death, 500 years ago.\nIt's said this sword has extraordinary properties.\n", (Room*)entities[11], RHand, 50, 50, 0, 0, ITEM,500));
	entities[11]->list.push_back(entities[45]);

	//EAGIS (entities[46])
	entities.push_back(new Item("EAGIS", "What is that!? This is the mythic shield of Seuz,\nthe strongest god of all times! I think it will give you the enough\nresistance to withstand the last battle.\n", (Room*)entities[11], LHand, 0, 50, 0, 50, ITEM, 500));
	entities[11]->list.push_back(entities[46]);

	//VEST (entities[47])
	entities.push_back(new Item("VEST", "Look at this strange vest. I heared that the bearer of\nthis magic clothing gets magical powers like super strength, enhaced\nstamina and mind control.\n", (Room*)entities[11], Body, 20, 20, 20, 20, ITEM, 500));
	entities[11]->list.push_back(entities[47]);


	/*---CREATE CREATURES---*/

	//PLAYER (entities[48])
	entities.push_back(new Player("SIMON", "A nice kid.\n", PLAYER, 50, 500, 20, 30, HERO, 50,0));
	player = (Player*)entities[48];
	player->list.push_back(entities[40]);
	player->list.push_back(entities[41]);
	player->list.push_back(entities[42]);
	player->list.push_back(entities[43]);
	player->list.push_back(entities[44]);
	player->num_items = 5;


	//GOBLIN(entities[49])
	entities.push_back(new Goblin("JIKKI", "The goblin guide. He looks like a little cute monster.\nTry to fight him to take his shiny key.\n", NPC, 20, 200, 0, 10,PASSIVE,100,1000));
	entities[5]->list.push_back(entities[49]);
	((Creature*)entities[49])->location = (Room*)world->entities[5];
	entities[49]->list.push_back(entities[33]);
	

	//SKELETONS(entities[50])
	entities.push_back(new Skeletons("SKELETONS", "Six weak and fragile skeletons wandering aimlessly.\nThey are so much agressive, so prepare for fight them.\n", NPC, 50, 500, 0, 0, HOSTILE,200,2000));
	entities[9]->list.push_back(entities[50]);
	((Creature*)entities[50])->location = (Room*)world->entities[9];
	entities[50]->list.push_back(entities[36]);

	//RAKDOS(entities[51])
	entities.push_back(new Rakdos("RAKDOS", "The Lord of the despair and desolation. He destroyed entire\nwith his own hands, so care, Simon.\n", NPC, 150, 1000, 0, 200, HOSTILE, 1000,3000));
	entities[12]->list.push_back(entities[51]);

	//THE INNKEEPER(entities[52])
	entities.push_back(new Karla("KARLA", "She's the dwarven partron of the tavern.\nShe has some interesting items you can buy.\n", NPC, 100, 500, 0, 0, SELLER,500,500));
	entities[2]->list.push_back(entities[52]);
	//you can buy the sword and the shield from the innkeeper
	entities[52]->list.push_back(entities[31]);
	entities[52]->list.push_back(entities[32]);
	
	//DRAGON(entities[53])
	entities.push_back(new Dragon("SMUAG", "He is a powerful, intelligent, malevolent and fearsome dragon\nwho invaded this zone 1000 years ago.\n ", NPC, 100, 500, 0, 0, HOSTILE,400,2500));
	entities[8]->list.push_back(entities[53]);

	//TOTEM(entities[54])
	entities.push_back(new Totem("SHOK'TAR", "This magical totem was created by a powerful shamman\ncalled Throll. It's unique prupose is to keep the treasure\nroom safe.Try to talk to him but care, it loves riddles.\n", NPC, 100, 500, 0, 0, TALKER, 500,1000));
	entities[10]->list.push_back(entities[54]);

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
	printf("If you want to keep your items safe,\nyou have to put them into the trunk.\n\n");

}




World::~World()
{
	int i;
	for (i = 0; i < entities.size(); i++)
	{
		delete entities[i];
	}

}


