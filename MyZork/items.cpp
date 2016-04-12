#include"world.h"
#include<stdio.h>

void Item::Look()const
{
	printf("%s\n%s\n",name.c_str(),description.c_str());
}