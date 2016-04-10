#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"world.h"



int GetCommand(MyString &option)
{
	//'GO' COMMANDS
	if (option == "go")
	{
		return go;
	}
	else if ((option == "n") || (option == "north") || (option == "go north") || (option == "go n"))
	{
		return go_north;
	}
	else if ((option == "s") || (option == "south") || (option == "go south") || (option == "go s"))
	{
		return go_south;
	}
	else if ((option == "e") || (option == "east") || (option == "go east") || (option == "go e"))
	{
		return go_east;
	}
	else if ((option == "w") || (option == "west") || (option == "go west") || (option == "go w"))
	{
		return go_west;
	}
	else if ((option == "u") || (option == "up") || (option == "go up") || (option == "go u"))
	{
		return go_up;
	}
	else if ((option == "d") || (option == "down") || (option == "go down") || (option == "go d"))
	{
		return go_down;
	}

	//'LOOK' COMMANDS
	else if (option == "look")
	{
		return look;
	}
	else if (option == "look n" || option == "look north")
	{
		return look_north;
	}
	else if (option == "look s" || option == "look south")
	{
		return look_south;
	}
	else if (option == "look e" || option == "look east")
	{
		return look_east;
	}
	else if (option == "look w" || option == "look west")
	{
		return look_west;
	}
	else if (option == "look u" || option == "look up")
	{
		return look_up;
	}
	else if (option == "look d" || option == "look down")
	{
		return look_down;
	}

	//'OPEN' COMMANDS
	else if (option == "open door")
	{
		return open_door;
	}
	else if (option == "open n door"|| option == "open north door")
	{
		return open_north;
	}
	else if (option == "open s door" || option == "open south door")
	{
		return open_south;
	}
	else if (option == "open e door" || option == "open east door")
	{
		return open_east;
	}
	else if (option == "open w door" || option == "open west door")
	{
		return open_west;
	}
	else if (option == "open u door" || option == "open up door")
	{
		return open_up;
	}
	else if (option == "open d door" || option == "open down door")
	{
		return open_down;
	}

	//'CLOSE' COMMANDS
	else if (option == "close door")
	{
		return close_door;
	}
	else if (option == "close n door" || option == "close north door")
	{
		return close_north;
	}
	else if (option == "close s door" || option == "close south door")
	{
		return close_south;
	}
	else if (option == "close e door" || option == "close east door")
	{
		return close_east;
	}
	else if (option == "close w door" || option == "close west door")
	{
		return close_west;
	}
	else if (option == "close u door" || option == "close up door")
	{
		return close_up;
	}
	else if (option == "close d door" || option == "close down door")
	{
		return close_down;
	}

	//'QUIT' COMMANDS
	else if (option == "quit" || option == "q")
	{
		return EXIT;
	}

	//'INCORRECT' COMMANDS
	else
	{
		return INVALID_COMMAND;
	}
}