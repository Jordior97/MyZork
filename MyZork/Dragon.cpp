#include "Dragon.h"
#include "stdlib.h"
#include "world.h"
#include <time.h>

void Dragon::Sleep()
{
	if (world->player->enemy == this)
	{
		enemy = world->player;
		actual_state = D_ATTACK;
	}
	else
	{
		actual_state = SLEEP;
	}
}

void Dragon::ClawsAttack()
{
	if (hp > 0)
	{
		if (actual_time >= timer + at_delay)
		{
			timer = actual_time;
			int damage = attack / 2 - enemy->armor / 10;
			printf("\n%s hit you with his claws for %i points of damage.\n", this->name.c_str(), damage);
			enemy->hp -= damage;
			printf("You have %i hp now.\n", enemy->hp);
			actual_state = D_ATTACK;
		}

		else if(actual_time >= FBall_count + FBALL_DELAY)
		{
			FBall_count = actual_time;
			actual_state = FIRE_BALL;
		}
		
	}
	else
	{
		actual_state = D_DIE;
	}
}

void Dragon::FireBall()
{
	if (hp > 0)
	{
		printf("\n%s throwed you a huge FIRE BALL,\ndealing you %i points of damage.\n", this->name.c_str(), attack);
		enemy->hp -= attack;
		printf("You have %i hp now.\n", enemy->hp);
		actual_state = D_ATTACK;
	}
	else
	{
		actual_state = D_DIE;
	}
}



void Dragon::Update()
{
	actual_time = GetTickCount();

	switch (actual_state)
	{
	case SLEEP:
	{
		Sleep();
		break;
	}
	case D_ATTACK:
	{
		ClawsAttack();
		break;
	}
	case FIRE_BALL:
	{
		FireBall();
		break;
	}

	case D_DIE:
	{
		Die();
		break;
	}
	}
}