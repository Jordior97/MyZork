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
	
	if (actual_time >= timer + WALK_DELAY)
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
	if (hp > 0)
	{
		if (actual_time >= timer + at_delay)
		{
			timer = actual_time;
			int damage = attack / 2 - enemy->armor / 10;
			printf("\n%s hits you for %i points of damage.\n", this->name.c_str(), damage);
			enemy->hp -= damage;
			if (enemy->hp < 0)
			{
				enemy->hp = 0;
			}
			printf(">> You have %i hp now.\n", enemy->hp);
			actual_state = ATTACK;
		}
	}
	else
	{
		actual_state = DIE;
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


