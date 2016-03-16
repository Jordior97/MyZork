#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"world.h"



int GetCommand(char option[])
{
	//'GO' COMMANDS
	if (strcmp(option, "go") == 0 )
	{
		return go;
	}
	else if (strcmp(option, "n") == 0 || strcmp(option, "north") == 0 || strcmp(option, "go north") == 0 || strcmp(option, "go n") == 0)
	{
		return go_north;
	}
	else if (strcmp(option, "s") == 0 || strcmp(option, "south") == 0 || strcmp(option, "go south") == 0 || strcmp(option, "go s") == 0)
	{
		return go_south;
	}
	else if (strcmp(option, "e") == 0 || strcmp(option, "east") == 0 || strcmp(option, "go east") == 0 || strcmp(option, "go e") == 0)
	{
		return go_east;
	}
	else if (strcmp(option, "w") == 0 || strcmp(option, "west") == 0 || strcmp(option, "go west") == 0  || strcmp(option, "go w") == 0)
	{
		return go_west;
	}
	else if (strcmp(option, "u") == 0 || strcmp(option, "up") == 0 || strcmp(option, "go up") == 0 || strcmp(option, "go u") == 0)
	{
		return go_up;
	}
	else if (strcmp(option, "d") == 0 || strcmp(option, "down") == 0 || strcmp(option, "go down") == 0 || strcmp(option, "go d") == 0)
	{
		return go_down;
	}

	//'LOOK' COMMANDS
	else if (strcmp(option, "look") == 0)
	{
		return look;
	}
	else if (strcmp(option, "look n") == 0 || strcmp(option, "look north") == 0)
	{
		return look_north;
	}
	else if (strcmp(option, "look s") == 0 || strcmp(option, "look south") == 0)
	{
		return look_south;
	}
	else if (strcmp(option, "look e") == 0 || strcmp(option, "look east") == 0)
	{
		return look_east;
	}
	else if (strcmp(option, "look w") == 0 || strcmp(option, "look west") == 0)
	{
		return look_west;
	}
	else if (strcmp(option, "look u") == 0 || strcmp(option, "look up") == 0)
	{
		return look_up;
	}
	else if (strcmp(option, "look d") == 0 || strcmp(option, "look down") == 0)
	{
		return look_down;
	}

	//'OPEN' COMMANDS
	else if (strcmp(option, "open door") == 0)
	{
		return open_door;
	}
	else if (strcmp(option, "open n door") == 0 || strcmp(option, "open north door") == 0)
	{
		return open_north;
	}
	else if (strcmp(option, "open s door") == 0 || strcmp(option, "open south door") == 0)
	{
		return open_south;
	}
	else if (strcmp(option, "open e door") == 0 || strcmp(option, "open east door") == 0)
	{
		return open_east;
	}
	else if (strcmp(option, "open w door") == 0 || strcmp(option, "open west door") == 0)
	{
		return open_west;
	}
	else if (strcmp(option, "open u door") == 0 || strcmp(option, "open up door") == 0)
	{
		return open_up;
	}
	else if (strcmp(option, "open d door") == 0 || strcmp(option, "open down door") == 0)
	{
		return open_down;
	}

	//'CLOSE' COMMANDS
	else if (strcmp(option, "close door") == 0)
	{
		return close_door;
	}
	else if (strcmp(option, "close n door") == 0 || strcmp(option, "close north door") == 0)
	{
		return close_north;
	}
	else if (strcmp(option, "close s door") == 0 || strcmp(option, "close south door") == 0)
	{
		return close_south;
	}
	else if (strcmp(option, "close e door") == 0 || strcmp(option, "close east door") == 0)
	{
		return close_east;
	}
	else if (strcmp(option, "close w door") == 0 || strcmp(option, "close west door") == 0)
	{
		return close_west;
	}
	else if (strcmp(option, "close u door") == 0 || strcmp(option, "close up door") == 0)
	{
		return close_up;
	}
	else if (strcmp(option, "close d door") == 0 || strcmp(option, "close down door") == 0)
	{
		return close_down;
	}

	//'QUIT' COMMANDS
	else if (strcmp(option, "quit") == 0 || strcmp(option, "q") == 0)
	{
		return EXIT;
	}

	//'INCORRECT' COMMANDS
	else
	{
		return INVALID_COMMAND;
	}
}