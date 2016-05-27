#include "NPC.h"

void Npc::Look()const
{
	printf("%s\n%s\n", name.c_str(), description.c_str());
}