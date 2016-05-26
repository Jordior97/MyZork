#include"world.h"
#include"player.h"
#include"Functions.h"
#include"creature.h"
#include<time.h>
#include<stdlib.h>

Player::Player(const char* name, const char* desc, Type type, int at, int h, int m, int ar) :
Creature(name, desc, type,  at, h, m, ar){}


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
	int dir = SetDirMove(commands);
	location = (Room*)world->entities[pos];
	
	if (dir >= north && dir <= down)
	{
		for (i = 0; i < world->entities.size(); i++)
		{
			if (world->entities[i]->type == EXIT && ((Exit*)world->entities[i])->src == location && ((Exit*)world->entities[i])->direction == dir)
			{
				location = ((Exit*)world->entities[i])->dst;
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
		if (location->list.first != nullptr)
		{
			DList<Entity*>::DNode* it = location->list.first;
			for (; it != nullptr; it = it->next)
			{
				//checks if the commands introduced are correct (first command == pick && second command == <item_name>) and if the item is not in the inventory yet
				if (it->data->type == ITEM && commands.size() == 2 && commands[1] == it->data->name)
				{
					if (it->data != (Item*)world->entities[39])
					{
						printf("You picked %s\n", it->data->name.c_str());
						list.push_back(it->data);
						location->list.erase(it);
						num_items++;
						return;
					}
					else
					{
						printf("This item is too big to carry it.\n");
						return;
					}
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
	if (list.first != nullptr)
	{
		for (int i = 0; i < world->entities.size(); i++)
		{
			DList<Entity*>::DNode* it = list.first;
			for (; it != nullptr; it = it->next)
			{
				//checks if the commands introduced are correct (first command == drop && second command == <item_name>) and if the item is in the inventory
				if (it->data->type == ITEM && commands.size() == 2 && commands[1] == it->data->name)
				{
					//checks if the the item is not equipped...
					if (((Item*)it->data)->equipped == false)
					{
						int random = rand() % NUM_ROOMS;

						printf("\n");
						printf("d8888b. db       .d88b.  d8888b. db\n");
						printf("88  `8D 88      .8P  Y8. 88  `8D 88\n");
						printf("88oodD' 88      88    88 88oodD' YP\n");
						printf("88~~~   88      88    88 88~~~\n");
						printf("88      88booo. `8b  d8' 88      db\n");
						printf("88      Y88888P  `Y88P'  88      YP\n");
						printf("\n");

						printf("You dropped %s and the Wormhole made it desappear.\n", it->data->name.c_str());
						
						((Room*)world->entities[random])->list.push_back(it->data);
						list.erase(it);
						num_items--;
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
		DList<Entity*>::DNode* it_player = nullptr;
		DList<Entity*>::DNode* it_room = nullptr;
		for (it_player = list.first; it_player != nullptr; it_player = it_player->next)
		{
			if (it_player->data->type == ITEM)
			{
				//checks if the item you want to put is in your inventory and if it's not equipped
				if (commands[1] == it_player->data->name && ((Item*)it_player->data)->equipped == false)
				{
					for (it_room = location->list.first; it_room != nullptr; it_room = it_room->next)
					{
						if (it_room->data->type == ITEM && it_room->data->name == commands[3])
						{
							//checks if the last command introduced is the name of the container
							if (((Item*)it_room->data)->container == true)
							{
								//checks if the container is in the room
								printf("You put %s into %s\n", it_player->data->name.c_str(), it_room->data->name.c_str());
								it_room->data->list.push_back(it_player->data);
								list.erase(it_player);
								num_items--;
								return;
							}

							else if (((Item*)it_room->data)->container == false)
							{
								printf("You are trying to put an item inside a non-container item.\nIt's an impossible action.\n");
								return;
							}
						}
					}
					printf("Sorry, you can't do this.\n");
					return;
				}
				else if (commands[1] == it_player->data->name && ((Item*)it_player->data)->equipped == true)
				{
					printf("You have to unequip this item first.\n");
					return;
				}
			}
		}
		printf("You haven't got this item in you inventory.\n");
		return;
	}
	printf("Make sure you have introduced the correct commands.\n");
	return;
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
			DList<Entity*>::DNode* it_player = nullptr;
			DList<Entity*>::DNode* it_room = nullptr;
			DList<Entity*>::DNode* it_container = nullptr;

			for (it_player = list.first; it_player != nullptr; it_player = it_player->next)
			{
				if (it_player->data->type == ITEM && commands[1] == it_player->data->name)
				{
					printf("You already have this item in your inventory.\n");
					return;
				}
			}

			for (it_room = location->list.first; it_room != nullptr; it_room = it_room->next)
			{
				if (it_room->data->name == commands[3] && ((Item*)it_room->data)->container == true)
				{
					for (it_container = it_room->data->list.first; it_container != nullptr; it_container = it_container->next)
					{
						if (it_container->data->name == commands[1])
						{
							printf("You got %s from %s\n", it_container->data->name.c_str(), it_room->data->name.c_str());
							list.push_back(it_container->data);
							it_room->data->list.erase(it_container);
							num_items++;
							return;
						}
					}
					printf("The item you are trying to get is not in this container.\n");
					return;
				}
				else if (it_room->data->name == commands[3] && ((Item*)it_room->data)->container == false)
				{
					printf("You are trying to get an item from a non-container item.\nIt's an impossible action.\n");
					return;
				}
			}
			printf("Sorry, you can't do this.\n");
			return;
		}
		else
		{
			printf("Your inventory is full, so you can't get more items.\n");
			return;
		}
	}
	printf("You have introduced some invalid commands.\n");
	return;
}

		/*
			//checks if the item you want to get isn't in your inventory, it's not equipped and it's in the room
			else if (commands[1] == ((Item*)world->entities[i])->name && ((Item*)world->entities[i])->picked == false && ((Item*)world->entities[i])->inside == true && ((Item*)world->entities[i])->src && player_pos)
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
				}
			printf("Make sure you have introduced the correct names of the items.\n");
			return;
		}
		else
		{
			printf("Your inventory is full, so you can't get more items.\n");
		}
	}
	printf("You have introduced some invalid commands.\n");
}*/