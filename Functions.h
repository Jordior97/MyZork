#ifndef _FUNCTIONS_
#define _FUNCTIONS_

enum option_go { go, go_north, go_south, go_east, go_west, go_up, go_down };
enum option_look { look = 7, look_north, look_south, look_east, look_west, look_up, look_down };
enum option_open { open_door = 14, open_north, open_south, open_east, open_west, open_up, open_down };
enum option_close { close_door = 21, close_north, close_south, close_east, close_west, close_up, close_down };

//I have to set different values to the inital elements of each enum to differentiate them.

int GetCommand(char[]);

#endif