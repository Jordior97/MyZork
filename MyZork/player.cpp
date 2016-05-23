#include"world.h"
#include"player.h"
#include"Functions.h"
#include<time.h>
#include<stdlib.h>

Player::Player(const char* name, const char* desc, Type type, int at, int h, int m, int ar) :
Entity(name, desc, type),  attack(at), hp(h), mana(m), armor(ar){}


void Player::Stats()
{
	printf("\n------------\n");
	printf("HP = %i\n", hp);
	printf("ARMOR = %i\n", armor);
	printf("ATTACK = %i\n", attack);
	printf("MANA = %i", mana);
	printf("\n------------\n");
}

void Player::Movement(int &pos, const Vector<MyString> &commands)
{
	fflush(stdin);

	int i, j; //counters that consider the correct room/exit when you move.
	int dir = SetDirection(commands);
	player_pos = (Room*)world->entities[pos];
	
	if (dir >= north && dir <= down)
	{
		for (i = 0; i < world->entities.size(); i++)
		{
			if (world->entities[i]->type == EXIT && ((Exit*)world->entities[i])->src == player_pos && ((Exit*)world->entities[i])->direction == dir)
			{
				player_pos = ((Exit*)world->entities[i])->dst;
				for (j = 0; j < world->entities.size(); j++)
				{
					if (((Exit*)world->entities[i])->dst == ((Room*)world->entities[j]))
					{
						if (((Exit*)world->entities[i])->door == true && ((Exit*)world->entities[i])->open == false)
						{
							printf("\nThere's a door locked here.\n");
							return;
						}
						else
						{
							pos = j;
							printf("\n%s\n%s\n", ((Room*)world->entities[j])->name.c_str(), ((Room*)world->entities[j])->description.c_str());
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

/*---PICK FUNCTION---*/
void Player::Pick(const Vector<MyString> &commands) 
{
	//checks if inventory is full (so you can't pick more objects)
	if (num_items < max_items)
	{
		for (int i = 0; i < world->entities.size(); i++)
		{
			//checks if the commands introduced are correct (first command == pick && second command == <item_name>) and if the item is not in the inventory yet
			if (world->entities[i]->type == ITEM && commands.size() == 2 && commands[1] == ((Item*)world->entities[i])->name && ((Item*)world->entities[i])->src == player_pos && ((Item*)world->entities[i])->picked == false)
			{
				if (((Item*)world->entities[i])->container == false)
				{
					((Item*)world->entities[i])->picked = true;
					num_items++;
					printf("You picked %s\n", ((Item*)world->entities[i])->name.c_str());
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
void Player::Drop(const Vector<MyString> &commands) 
{
	srand(time(NULL));
	for (int i = 0; i < world->entities.size(); i++)
	{
		//checks if the commands introduced are correct (first command == drop && second command == <item_name>) and if the item is in the inventory
		if (world->entities[i]->type == ITEM && commands.size() == 2 && ((Item*)world->entities[i])->name == commands[1] && ((Item*)world->entities[i])->picked == true)
		{
			//checks if the the item is not equipped...
			if (((Item*)world->entities[i])->equipped == false)
			{
				int random = rand() % NUM_ROOMS;
				((Item*)world->entities[i])->picked = false;
				((Item*)world->entities[i])->src = ((Room*)world->entities[random]);//WormHole: sends the item to a random room.
				num_items--;

				printf("\n");
				printf("d8888b. db       .d88b.  d8888b. db\n");
				printf("88  `8D 88      .8P  Y8. 88  `8D 88\n");
				printf("88oodD' 88      88    88 88oodD' YP\n");
				printf("88~~~   88      88    88 88~~~\n");
				printf("88      88booo. `8b  d8' 88      db\n");
				printf("88      Y88888P  `Y88P'  88      YP\n");
				printf("\n");

				printf("You dropped %s and the Wormhole made it desappear.\n", ((Item*)world->entities[i])->name.c_str());
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

/*---PUT FUNCTION---*/
void Player::Put(const Vector<MyString> &commands) 
{
	//checks if the commands introduced are correct
	if (commands.size() == 4 && commands[2] == "into")
	{
		for (int i = 0; i < world->entities.size(); i++)
		{
			if (world->entities[i]->type == ITEM)
			{
				//checks if the item you want to put is in your inventory and if it's not equipped
				if (commands[1] == ((Item*)world->entities[i])->name && ((Item*)world->entities[i])->picked == true && ((Item*)world->entities[i])->equipped == false)
				{
					for (int j = 0; j < world->entities.size(); j++)
					{
						if (world->entities[j]->type == ITEM)
						{
							//checks if the last command introduced is the name of the container
							if (((Item*)world->entities[j])->name == commands[3] && ((Item*)world->entities[j])->container == true)
							{
								//checks if the container is in the room
								if (((Item*)world->entities[j])->src == world->player->player_pos)
								{
									((Item*)world->entities[i])->inside = true;
									((Item*)world->entities[i])->src = ((Item*)world->entities[j])->src;
									((Item*)world->entities[i])->picked = false;
									num_items--;
									printf("You put %s into %s\n", ((Item*)world->entities[i])->name.c_str(), ((Item*)world->entities[j])->name.c_str());
									return;
								}
								else if (((Item*)world->entities[j])->src != player_pos)
								{
									printf("You are trying to put an object inside a container that is not in this room.\n");
									return;
								}
							}
							else if (((Item*)world->entities[j])->name == commands[3] && ((Item*)world->entities[j])->container == false)
							{
								printf("You are trying to put an item inside a non-container item.\nIt's an impossible action.\n");
								return;
							}
						}
					}
				}
				else if (commands[1] == ((Item*)world->entities[i])->name && ((Item*)world->entities[i])->picked == false)
				{
					printf("You haven't got this item in you inventory.\n");
					return;
				}
				else if (commands[1] == ((Item*)world->entities[i])->name && ((Item*)world->entities[i])->equipped == true)
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
void Player::Get(const Vector<MyString> &commands) 
{
	//checks if the commands introduced are correct
	if (commands.size() == 4 && commands[2] == "from")
	{
		//checks if your inventory is full
		if (num_items < max_items)
		{
			for (int i = 0; i < world->entities.size(); i++)
			{
				if (world->entities[i]->type == ITEM)
				{
					//checks if the item you want to get isn't in your inventory, it's not equipped and it's in the room
					if (commands[1] == ((Item*)world->entities[i])->name && ((Item*)world->entities[i])->picked == false && ((Item*)world->entities[i])->inside == true && ((Item*)world->entities[i])->src && player_pos)
					{
						for (int j = 0; j < world->entities.size(); j++)
						{
							if (world->entities[j]->type == ITEM)
							{
								//checks if the last command introduced is the name of the container
								if (((Item*)world->entities[j])->name == commands[3] && ((Item*)world->entities[j])->container == true)
								{
									//checks if the container is in the room
									if (((Item*)world->entities[j])->src == player_pos)
									{
										((Item*)world->entities[i])->inside = false;
										((Item*)world->entities[i])->picked = true;
										num_items++;
										printf("You got %s from %s\n", ((Item*)world->entities[i])->name.c_str(), ((Item*)world->entities[j])->name.c_str());
										return;
									}
									else if (((Item*)world->entities[j])->src != player_pos)
									{
										printf("You are trying to get an object from a container that is not in this room.\n");
										return;
									}
								}
								else if (((Item*)world->entities[j])->name == commands[3] && ((Item*)world->entities[j])->container == false)
								{
									printf("You are trying to get an item from a non-container item.\nIt's an impossible action.\n");
									return;
								}
							}
						}
					}
					else if (commands[1] == ((Item*)world->entities[i])->name && ((Item*)world->entities[i])->picked == true)
					{
						printf("You already have this item in your inventory.\n");
						return;
					}
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