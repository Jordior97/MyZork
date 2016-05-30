#include "Totem.h"
#include "stdlib.h"
#include "world.h"
#include <time.h>


void Totem::Passive()
{
	if (world->player->location == location)
	{
		enemy = world->player;
		actual_state = ACTIVATION;
	}
	actual_state = IDLE;
}

void Totem::Activation()
{
}




/*void Totem::Update()
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
}*/