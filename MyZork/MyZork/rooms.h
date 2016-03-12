class Room
{
public:

	char name[20];
	char description[200];
	char direction; //north,south,west,east
	Room* src; //source Room
	Room* dst; //destination Room
};