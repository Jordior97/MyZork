#include"world.h"
#include"player.h"
#include"Functions.h"
#include<time.h>
#include<stdlib.h>

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
							DList<Entity*>::DNode* it_npc = ((Room*)world->entities[pos])->list.first;
							if (it_npc != nullptr)
							{
								printf("\n--------------------------\n");
								printf("\nThere are some creatures around:\n\n");
								for (; it_npc != nullptr; it_npc = it_npc->next)
								{
									if (it_npc->data->type == NPC)
									{
										it_npc->data->Look();
									}
								}
							}
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
void Player::Look(int pos, const Vector<MyString> &commands) 
{
	int i; //Counters to consider the correct room/exit when you are looking
	location = (Room*)world->entities[pos];
	int dir = SetDirLook(commands);

	if (dir >= north && dir <= down)
	{
		for (i = 0; i < world->entities.size(); i++)
		{
			if (world->entities[i]->type == EXIT && ((Exit*)world->entities[i])->src == location && ((Exit*)world->entities[i])->direction == dir)
			{
				((Exit*)world->entities[i])->Look();
				return;
			}
		}
		printf("\nThere's nothing to look here.\n");
	}

	else if (dir == 6) //Look Trunk
	{
		DList<Entity*>::DNode* it_room = world->player->location->list.first;
		for (; it_room != nullptr; it_room = it_room->next)
		{
			if (it_room->data == world->entities[39])
			{
				DList<Entity*>::DNode* it_trunk = it_room->data->list.first;
				printf("Items inside the TRUNK:\n\n");
				for (; it_trunk != nullptr; it_trunk = it_trunk->next)
				{
					printf("%s\n%s\n", it_trunk->data->name.c_str(), it_trunk->data->description.c_str());
				}
				return;
			}
		}
		printf("The TRUNK is not here.\n");
	}

	else if (commands.size() == 1)//Case 3: name and description of the room you are. It shows items that are in the room too.
	{
		((Room*)world->entities[pos])->Look();
		DList<Entity*>::DNode* it_items = ((Room*)world->entities[pos])->list.first;
		if (it_items != nullptr)
		{
			printf("\n--------------------------\n");
			printf("\nItems you can find here:\n\n");
			for (; it_items != nullptr; it_items = it_items->next)
			{
				if (it_items->data->type == ITEM)
				{
					it_items->data->Look();
				}
			}
		}
		DList<Entity*>::DNode* it_npc = ((Room*)world->entities[pos])->list.first;
		if (it_npc != nullptr)
		{
			printf("\n--------------------------\n");
			printf("\nThere are some creatures around:\n\n");
			for (; it_npc != nullptr; it_npc = it_npc->next)
			{
				if (it_npc->data->type == NPC)
				{
					it_npc->data->Look();
				}
			}
		}
	}

	else
	{
		printf("Introduce a valid command if you want to look properly.\n");
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

/*---OPEN FUNCTION---*/
void Player::Open(int pos, const Vector<MyString>&commands) 
{
	int i;  //Counter to consider the correct exit
	location = ((Room*)world->entities[pos]);
	int dir = SetDirOpenClose(commands);
	bool key = false;
	DList<Entity*>::DNode* it = world->player->list.first;

	for (; it != nullptr; it = it->next)
	{
		if (it->data == world->entities[33])
		{
			key = true;
		}
	}

	if (key == true) //checks if you have the key picked (necessary to open doors)
	{
		if (dir >= north && dir <= down && commands[2] == "door") //checks if commands introduced are correct
		{
			for (i = 0; i < world->entities.size(); i++)
			{
				//OPEN CONDITION: the exit you want to "open" has a door, and its door is closed
				if (world->entities[i]->type == EXIT && ((Exit*)world->entities[i])->src == location
					&& ((Exit*)world->entities[i])->open == false && ((Exit*)world->entities[i])->door == true
					&& ((Exit*)world->entities[i])->direction == dir)
				{
					((Exit*)world->entities[i])->open = true;
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
void Player::Close(int pos, const Vector<MyString> &commands) 
{
	int i;
	location = (Room*)world->entities[pos];
	int dir = SetDirOpenClose(commands);

	if (dir >= north && dir <= down && commands[2] == "door") //checks if commands introduced are correct
	{
		for (i = 0; i < world->entities.size(); i++)
		{
			//CLOSE CONDITION: the exit you want to "close" has a door, and its door is opened
			if (world->entities[i]->type == EXIT && ((Exit*)world->entities[i])->src == location 
				&& ((Exit*)world->entities[i])->open == true && ((Exit*)world->entities[i])->door == true 
				&& ((Exit*)world->entities[i])->direction == dir)
			{
				((Exit*)world->entities[i])->open = false;
				printf("\nYou closed the door.\n");
				return;
			}
		}
		printf("\nThere's nothing to close here.\n");
	}
	else
	{
		printf("\nYou have to specify which door you want to close.\n");
		return;
	}
}

/*---INVENTORY FUNCTION---*/
void Player::Inventory() const
{
	int i;
	//checks if the player has got items in his inventory
	if (num_items > 0)
	{
		printf("In your inventory you have (%i/%i):\n\n", num_items, max_items);
		DList<Entity*>::DNode* it = nullptr;
		for (it = list.first; it != nullptr; it = it->next)
		{
			//shows the names and descriptions of the picked items
			if (((Item*)it->data)->magic_gem == false)
			{
				it->data->Look();
			}
		}
		printf("------------------\n");
		printf("MAGIC GEMS:\n\n");
		for (it = list.first; it != nullptr; it = it->next)
		{
			//shows the names and descriptions of the picked gems
			if (((Item*)it->data)->magic_gem == true)
			{
				it->data->Look();
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
void Player::Equip(const Vector<MyString> &commands) 
{
	DList<Entity*>::DNode* it = list.first;
	for (; it != nullptr; it = it->next)
	{
		//checks if the commands introduced are correct (first command == equip && second command == <item_name>) 
		//it checks the slot it occupies (the part of the player where it will be equipped) too
		if (it->data->type == ITEM && commands.size() == 2 && commands[1] == it->data->name && ((Item*)it->data)->part == Head)
		{
			//checks if there isn't an item equipped on that part yet
			if (head_item == false)
			{
				head_item = true;
				((Item*)it->data)->equipped = true;
				armor += ((Item*)it->data)->armor;
				attack += ((Item*)it->data)->attack;
				hp += ((Item*)it->data)->hp;
				mana += ((Item*)it->data)->mana;
				printf("You equipped %s on your head.\n", it->data->name.c_str());
				return;
			}
			else
			{
				printf("You have an item equipped on your head already.\n");
				return;
			}
		}

		else if (it->data->type == ITEM && commands.size() == 2 && commands[1] == it->data->name && ((Item*)it->data)->part == Body)
		{
			if (body_item == false)
			{
				body_item = true;
				((Item*)it->data)->equipped = true;
				armor += ((Item*)it->data)->armor;
				attack += ((Item*)it->data)->attack;
				hp += ((Item*)it->data)->hp;
				mana += ((Item*)it->data)->mana;
				printf("You equipped %s on your body.\n", it->data->name.c_str());
				return;
			}
			else
			{
				printf("You have an item equipped on your body already.\n");
				return;
			}
		}

		else if (it->data->type == ITEM && commands.size() == 2 && commands[1] == it->data->name && ((Item*)it->data)->part == RHand)
		{
			if (RHand_item == false)
			{
				RHand_item = true;
				((Item*)it->data)->equipped = true;
				armor += ((Item*)it->data)->armor;
				attack += ((Item*)it->data)->attack;
				hp += ((Item*)it->data)->hp;
				mana += ((Item*)it->data)->mana;
				printf("You equipped %s on your right hand.\n", it->data->name.c_str());
				return;
			}
			else
			{
				printf("You have an item equipped on your right hand already.\n");
				return;
			}
		}

		else if (it->data->type == ITEM && commands.size() == 2 && commands[1] == it->data->name && ((Item*)it->data)->part == LHand)
		{

			if (LHand_item == false)
			{
				LHand_item = true;
				((Item*)it->data)->equipped = true;
				armor += ((Item*)it->data)->armor;
				attack += ((Item*)it->data)->attack;
				hp += ((Item*)it->data)->hp;
				mana += ((Item*)it->data)->mana;
				printf("You equipped %s on your left hand.\n", it->data->name.c_str());
				return;
			}
			else
			{
				printf("You have an item equipped on your left hand already.\n");
				return;
			}
		}

		else if (it->data->type == ITEM && commands.size() == 2 && commands[1] == it->data->name && ((Item*)it->data)->part == Legs)
		{
			if (legs_item == false)
			{
				legs_item = true;
				((Item*)it->data)->equipped = true;
				armor += ((Item*)it->data)->armor;
				attack += ((Item*)it->data)->attack;
				hp += ((Item*)it->data)->hp;
				mana += ((Item*)it->data)->mana;
				printf("You equipped %s on your legs.\n", it->data->name.c_str());
				return;
			}
			else
			{
				printf("You have an item equipped on your legs already.\n");
				return;
			}
		}

		else if (it->data->type == ITEM && commands.size() == 2 && commands[1] == it->data->name && ((Item*)it->data)->part == Non_Equipable)
		{
			printf("You can't equip this item.\n");
			return;
		}
	}
	printf("You don't have any item to equip with that name.\n");
}

/*---UNEQUIP FUNCTION---*/
void Player::Unequip(const Vector<MyString> &commands) 
{
	DList<Entity*>::DNode* it = list.first;
	for (; it != nullptr; it = it->next)
	{
		if (it->data->type == ITEM)
		{
			//checks if the commands introduced are correct (first command == unequip && second command == <item_name>) 
			if (commands.size() == 2 && commands[1] == it->data->name)
			{
				//checks if the item is equipped
				if (((Item*)it->data)->equipped == true)
				{
					//to empty the slot the item occupied
					switch (((Item*)it->data)->part)
					{
					case Head:
					{
						head_item = false;
						break;
					}
					case Body:
					{
						body_item = false;
						break;
					}
					case RHand:
					{
						RHand_item = false;
						break;
					}
					case LHand:
					{
						LHand_item = false;
						break;
					}
					case Legs:
					{
						legs_item = false;
						break;
					}
					default:
					{
						printf("Unequipment failed.\n");
						break;
					}
					}

					((Item*)it->data)->equipped = false;
					armor -= ((Item*)it->data)->armor;
					attack -= ((Item*)it->data)->attack;
					hp -= ((Item*)it->data)->hp;
					mana -= ((Item*)it->data)->mana;
					printf("You have unequipped %s.\n", it->data->name.c_str());
					return;
				}
			}
		}
	}
	printf("You haven't got any item equipped with that name.\n");
}

/*---EQUIPMENT FUNCTION---*/
void Player::Equipment() const
{
	MyString Head_item;
	MyString Body_item;
	MyString Legs_item;
	MyString LeftH_item;
	MyString RightH_item;

	//to show every item equipped 
	for (int i = 0; i < world->entities.size(); i++)
	{
		if (world->entities[i]->type == ITEM)
		{
			if (((Item*)world->entities[i])->equipped == true)
			{
				if (((Item*)world->entities[i])->part == Head)
				{
					Head_item = ((Item*)world->entities[i])->name;
				}
				else if (((Item*)world->entities[i])->part == Body)
				{
					Body_item = ((Item*)world->entities[i])->name;
				}
				else if (((Item*)world->entities[i])->part == Legs)
				{
					Legs_item = ((Item*)world->entities[i])->name;
				}
				else if (((Item*)world->entities[i])->part == LHand)
				{
					LeftH_item = ((Item*)world->entities[i])->name;
				}
				else if (((Item*)world->entities[i])->part == RHand)
				{
					RightH_item = ((Item*)world->entities[i])->name;
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