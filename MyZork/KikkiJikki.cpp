#include "KikkiJikki.h"
#include "stdlib.h"
#include "world.h"
#include <time.h>

void Goblin::Movement()
{
	if (world->player->enemy == this)
	{
		enemy = world->player;
		actual_state = ATTACK;
	}
	unsigned int Delay = 3000;
	if (actual_time >= timer + Delay)
	{
		timer = actual_time;
		srand(time(NULL));
		int dir = rand() % 4;

		for (int i = 0; i < world->entities.size(); i++)
		{
			if (world->entities[i]->type == EXIT && ((Exit*)world->entities[i])->src == location && ((Exit*)world->entities[i])->direction == dir)
			{
				for (int j = 0; j < world->entities.size(); j++)
				{
					if (((Exit*)world->entities[i])->dst == ((Room*)world->entities[j]))
					{
						if (((Exit*)world->entities[i])->door == false && ((Exit*)world->entities[i])->open == true)
						{
							if (((Exit*)world->entities[i])->src == world->player->location)
							{
								printf("\n%s crossed the %s\n", this->name.c_str(), ((Exit*)world->entities[i])->name.c_str());
							}

							DList<Entity*>::DNode* it = location->list.first;
							for (; it != nullptr; it = it->next)
							{
								if (it->data == this)
								{
									break;
								}
							}

							location->list.erase(it);
							location = (Room*)world->entities[j];
							location->list.push_back(this);
							if (world->player->location == location)
							{
								printf("\n%s entered the room\n", this->name.c_str());
							}
							actual_state = WALK;
						}
					}
				}
			}
		}
	}
}

void Goblin::Attack()
{
	unsigned int Delay = 2000;

	if (hp > 0)
	{
		if (actual_time >= timer + Delay)
		{
			timer = actual_time;
			int damage = attack / 2 - enemy->armor / 10;
			printf("\n%s hits you for %i points of damage.\n", this->name.c_str(), damage);
			enemy->hp -= damage;
			actual_state = ATTACK;
		}
	}
	else
	{
		actual_state = DIE;
	}
}


void Goblin::Die()
 {
	world->player->enemy = nullptr;
	if (list.first != nullptr)
	{
		printf("\n%s died and dropped:\n", this->name.c_str());
		DList<Entity*>::DNode* it = list.first;
		for (int i = 0; i < list.size();i++)
		{
			printf("- %s\n",it->data->name.c_str());
			location->list.push_back(it->data);
			list.pop_front();
			it = it->next;
		}
	}
	else
	{
		printf("\n%s died.\n");
	}
	printf("You earned %i coins! Good job!\n", money);
	world->player->money += money;
	DList<Entity*>::DNode* to_erase = location->list.first;
	for (; to_erase != nullptr; to_erase = to_erase->next)
	{
		if (to_erase->data == this)
		{
			location->list.erase(to_erase);
			break;
		}
	}
	world->entities.erase(49);
	
}

void Goblin::Update()
{
	actual_time = GetTickCount();

	switch (actual_state)
	{
	case WALK:
	{
		Movement();
		break;
	}
	case ATTACK:
	{
		Attack();
		break;
	}
	case DIE:
	{
		Die();
		break;
	}
	}
}


