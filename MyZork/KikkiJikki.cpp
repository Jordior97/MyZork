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
	unsigned int Delay = 5000;
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
							printf("%s is now in %s\n", this->name.c_str(), location->name.c_str());
							actual_state = WALK;
	
							return;
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
			int damage = attack / 2;
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
	 world->player->enemy == nullptr;
	if (list.first != nullptr)
	{
		printf("%s died and dropped:\n", this->name.c_str());
		DList<Entity*>::DNode* it = list.first;
		for (; it != nullptr; it = it->next)
		{
			printf("- %s\n",it->data->name.c_str());
			location->list.push_back(it->data);
			list.erase(it);
		}
	}
	else
	{
		printf("%s died.\n");
	}
	DList<Entity*>::DNode* to_erase = location->list.first;
	for (; to_erase != nullptr; to_erase = to_erase->next)
	{
		if (to_erase->data == this)
		{
			location->list.erase(to_erase);
			return;
		}
	}
	
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


