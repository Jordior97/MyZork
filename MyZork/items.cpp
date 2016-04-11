#include"world.h"
#include<stdio.h>

void Item::Look()const
{
	printf("\nThe items you can find here:\n%s%s\n",name.c_str(),description.c_str());
}