#include"world.h"
#include"player.h"

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