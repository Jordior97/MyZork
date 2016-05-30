#include"creature.h"
#include"world.h"

Creature::Creature(const char* name, const char* desc, Type type, int at, int hp, int m, int ar, CType c_type, int money, int at_delay) :Entity(name, desc, type), attack(at), hp(hp), mana(m), armor(ar), money(money), c_type(c_type),at_delay(at_delay){}

void Creature::Look() const
{
	printf("%s\n%s\n", name.c_str(), description.c_str());
}

void Creature::Die()
{
	world->player->enemy = nullptr;
	if (list.first != nullptr)
	{
		printf("\n%s died and dropped:\n", this->name.c_str());
		DList<Entity*>::DNode* it = list.first;
		for (int i = 0; i < list.size(); i++)
		{
			printf("- %s\n", it->data->name.c_str());
			location->list.push_back(it->data);
			it = it->next;
		}
		list.clear();
	}
	else
	{
		printf("\n%s died.\n", this->name.c_str());
	}
	printf("You earned %i coins! Good job!\n", money);
	world->player->money += money;
	DList<Entity*>::DNode* to_erase = location->list.first;
	for (; to_erase != nullptr; to_erase = to_erase->next)
	{
		if (to_erase->data == this)
		{
			location->list.erase(to_erase);
			break;
		}
	}
	int i;
	for (i = 0; i < world->entities.size(); i++)
	{
		if (world->entities[i] == this)
		{
			break;
		}
	}
	world->entities.erase(i);

}