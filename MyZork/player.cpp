#include"world.h"
#include"player.h"
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
	player_pos = (Room*)world->entities[pos];

	if (commands.size() == 2 && commands[0] == "go" && (commands[1] == "north" || commands[1] == "n") || commands[0] == "north" || commands[0] == "n") //Checks if commands introduced are correct
	{
		for (i = 0; i < world->entities.size(); i++)
		{
			if (world->entities[i]->type == EXIT && ((Exit*)world->entities[i])->src == player_pos && ((Exit*)world->entities[i])->direction == north) //Looks for an exit in the direction introduced
			{
				player_pos = ((Exit*)world->entities[i])->dst;
				for (j = 0; j < world->entities.size(); j++)
				{
					if (((Exit*)world->entities[i])->dst == ((Room*)world->entities[j]))
					{
						if (((Exit*)world->entities[i])->door == true && ((Exit*)world->entities[i])->open == false)  //Case 1: the exit has a closed door you have to open first
						{
							printf("\nThere's a door locked here.\n");
							return;
						}
						else  //Case 2: there is a room in the chosen direction and there isn't a closed door (sets a new position for the player).
						{
							pos = j;
							printf("\n%s\n%s", ((Room*)world->entities[j])->name.c_str(), ((Room*)world->entities[j])->description.c_str());
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
		for (i = 0; i < world->entities.size(); i++)
		{
			if (world->entities[i]->type == EXIT && ((Exit*)world->entities[i])->src == player_pos && ((Exit*)world->entities[i])->direction == south)
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
							printf("\n%s\n%s", ((Room*)world->entities[j])->name.c_str(), ((Room*)world->entities[j])->description.c_str());
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
		for (i = 0; i < world->entities.size(); i++)
		{
			if (world->entities[i]->type == EXIT && ((Exit*)world->entities[i])->src == player_pos && ((Exit*)world->entities[i])->direction == east)
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
							printf("\n%s\n%s", ((Room*)world->entities[j])->name.c_str(), ((Room*)world->entities[j])->description.c_str());
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
		for (i = 0; i < world->entities.size(); i++)
		{
			if (world->entities[i]->type == EXIT && ((Exit*)world->entities[i])->src == player_pos && ((Exit*)world->entities[i])->direction == west)
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
							printf("\n%s\n%s", ((Room*)world->entities[j])->name.c_str(), ((Room*)world->entities[j])->description.c_str());
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
		for (i = 0; i < world->entities.size(); i++)
		{
			if (world->entities[i]->type == EXIT && ((Exit*)world->entities[i])->src == player_pos && ((Exit*)world->entities[i])->direction == down)
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
							printf("\n%s\n%s", ((Room*)world->entities[j])->name.c_str(), ((Room*)world->entities[j])->description.c_str());
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
		for (i = 0; i < world->entities.size(); i++)
		{
			if (world->entities[i]->type == EXIT && ((Exit*)world->entities[i])->src == player_pos && ((Exit*)world->entities[i])->direction == up)
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