#include"Rakdos.h"
#include "stdlib.h"
#include "world.h"
#include <time.h>

void Rakdos::Waiting()
{
	if (world->player->location == location)
	{
		enemy = world->player;
		actual_state = ATTACKING;
	}
	else
	{
		actual_state = WAITING;
	}
}

void Rakdos::Attacking()
{
	if (hp > 0)
	{
		srand(time(NULL));
		attack_type = rand() % 3;

		if (actual_time >= timer + at_delay)
		{
			timer = actual_time;
			if (attack_type == ATTACK1)
			{
				int damage = attack - enemy->armor;
				printf("%s attacked you with his big cursed axe, dealing %i damage.\n",this->name.c_str(), damage);
				enemy->hp -= damage;
				printf("Simon, you have %i hp.\n", enemy->hp);
			}
			else if (attack_type == ATTACK2)
			{
				printf("%s casted a strange spell that reduces 10 points all your stats.\n", this->name.c_str());
				enemy->armor -= 10;
				enemy->attack -= 10;
				enemy->mana -= 10;
				enemy->hp -= 10;
				printf("You have %i hp.\n", enemy->hp);
			}
			else if (attack_type == HEAL)
			{
				printf("%s is healing 100 hp, what a problem!\n");
				hp += 100;
			}			
		}
		actual_state = ATTACKING;
	}
	else
	{
		actual_state = R_DIE;
	}
}

void Rakdos::Update()
{
	actual_time = GetTickCount();

	switch (actual_state)
	{
	case WAITING:
	{
		Waiting();
		break;
	}
	case ATTACKING:
	{
		Attacking();
		break;
	}

	case R_DIE:
	{
		Die();
		break;
	}
	}
}