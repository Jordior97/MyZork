#ifndef _ROOMS_
#define  _ROOMS_


class Room
{
public:

	char name[20];
	char description[200];
	char north[20];
	char south[20];
	char east[20];
	char west[20];
	char up[20];
	char down[20];

	//Room* src; //source Room
	//Room* dst; //destination Room
};

#endif