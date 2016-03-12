#include"rooms.h"
#include"player.h"
#include"exits.h"

class World
{
public:
	
	Room* rooms = nullptr;
	Player* player = nullptr;
	Exit* exits = nullptr;

	World();

	void CreateWorld() const;

	~World();
};