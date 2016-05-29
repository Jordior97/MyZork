#include "Totem.h"
#include "stdlib.h"
#include "world.h"
#include <time.h>


void Totem::Passive()
{
	if (world->player->enemy == this)
	{
		enemy = world->player;
		actual_state = QUEST_1;
	}
	actual_state = IDLE;
}

void Totem::Q1()
{

}

void Totem::Q2()
{

}

void Totem::Q3()
{

}

void Totem::Complete()
{

}

void Totem::Update()
{
	actual_time = GetTickCount();

	switch (actual_state)
	{
	case IDLE:
	{
		void Passive();
		break;
	}
	case QUEST_1:
	{
		void Q1();
		break;
	}
	case QUEST2:
	{
		void Q2();
		break;
	}

	case QUEST3:
	{
		void Q3();
		break;
	}
	case COMPLETE:
	{
		void Complete();
		break;
	}
		
	}
}