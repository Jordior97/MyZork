#include "KikkiJikki.h"
#include "stdlib.h"
#include "world.h"
#include <time.h>

void Goblin::Movement()
{
	
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
						
						if (hp < 200)
						{
							actual_state = ATTACK;
						}
						else
						{
							actual_state = WALK;
						}
						return;
					}
				}
			}
		}
	}
}


void Goblin::Attack()
{
	srand(time(NULL));
	int a = rand() % 2;

	printf("Attacking\n");

	if (a == 0)
	{
		actual_state = ATTACK;
	}
	else
	{
		actual_state = DIE;
	}
}

void Goblin::Die()
{
	srand(time(NULL));
	int a = rand() % 2;

	printf("Dying\n");

	if (a == 0)
	{
		actual_state = DIE;
	}
	else
	{
		actual_state = WALK;
	}

}

void Goblin::Update()
{
	unsigned int Delay = 5000;
	actual_time = GetTickCount();

	if (actual_time >= timer + Delay)
	{
		timer = actual_time;

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
}

