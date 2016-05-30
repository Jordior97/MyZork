#include "Totem.h"
#include "stdlib.h"
#include "world.h"
#include <time.h>


void Totem::Passive()
{
	if (world->player->location == location)
	{
		enemy = world->player;
		world->player->enemy = this;
		countdown = GetTickCount();
		actual_state = ACTIVATION;
	}
	else
	{
		actual_state = IDLE;
	}
}

void Totem::Activation()
{
	if (hp > 0)
	{
		if (actual_time >= timer + at_delay)
		{
			timer = actual_time;
			printf("%i seconds left.\n", COUNTDOWN / 1000 - (actual_time - countdown) / 1000);
			if (COUNTDOWN / 1000 - (actual_time - countdown) / 1000 == 0)
			{
				actual_state = EXPLOSION;
			}
			else
			{
				actual_state = ACTIVATION;
			}
		}
	}
	else
	{
		actual_state = EVAPORATION;
	}
}

void Totem::Explosion()
{
	printf("%s made a huge explosion.\n", this->name.c_str());
	enemy->hp = 0;
	actual_state = EVAPORATION;
}




void Totem::Update()
{
	actual_time = GetTickCount();

	switch (actual_state)
	{
	case IDLE:
	{
		Passive();
		break;
	}
	case ACTIVATION:
	{
		Activation();
		break;
	}
	case EXPLOSION:
	{
		Explosion();
		break;
	}
	case EVAPORATION:
	{
		Die();
		break;
	}
		
	}
}