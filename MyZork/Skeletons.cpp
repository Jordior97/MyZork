#include"Skeletons.h"
#include "stdlib.h"
#include "world.h"
#include <time.h>

void Skeletons::SIdle()
{
	if (world->player->location == location)
	{
		enemy = world->player;
		world->player->enemy = this;
		actual_state = N_ATTACK;
	}
	else
	{
		actual_state = S_IDLE;
	}
}

void Skeletons::NormalAttack()
{
	if (hp > 250)
	{
		if (actual_time >= timer + at_delay)
		{
			timer = actual_time;
			int damage = attack / 2 - enemy->armor / 10;
			printf("\n%s hit you for %i points of damage.\n", this->name.c_str(), damage);
			enemy->hp -= damage;
			if (enemy->hp < 0)
			{
				enemy->hp = 0;
			}
			printf("You have %i hp now.\n", enemy->hp);
			actual_state = N_ATTACK;
		}
	}
	else
	{
		printf("Oh, no! %s are furious now! They attack damage and armor are increased!\nCare now, they have sharp swords to attack.\n", this->name.c_str());
		attack += 50;
		armor += 100;
		at_delay -= 1000;
		actual_state = RAGE;
	}
}

void Skeletons::RageMode()
{
	if (hp > 0)
	{
		if (actual_time >= timer + at_delay)
		{
			timer = actual_time;
			int damage = attack / 2;
			printf("\n%s hit you for %i points of damage with their big swords.\n", this->name.c_str(), damage);
			enemy->hp -= damage;
			if (enemy->hp < 0)
			{
				enemy->hp = 0;
			}
			printf("You have %i hp now.\n", enemy->hp);
			actual_state = RAGE;
		}
	}
	else
	{
		actual_state = S_DIE;
	}
}


void Skeletons::Update()
{
	actual_time = GetTickCount();

	switch (actual_state)
	{
	case S_IDLE:
	{
		SIdle();
		break;
	}
	case N_ATTACK:
	{
		NormalAttack();
		break;
	}
	case RAGE:
	{
		RageMode();
		break;
	}

	case S_DIE:
	{
		Die();
		break;
	}
	}
}