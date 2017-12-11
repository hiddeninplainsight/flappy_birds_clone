#include "flappy_bird.h"

flappy_bird::flappy_bird(int key)
	: space_key(key)
{
}

void flappy_bird::update_position()
{
	if(space_key)
	{
		bird_image.location.y-=10;
	}
	else
	{
		bird_image.location.y+=2;
	}
}

int flappy_bird::top_y()
{
	return bird_image.location.y;
}

int flappy_bird::bottom_y()
{
	return bird_image.location.y + bird_image.height();
}

int flappy_bird::face_x()
{
	return bird_image.location.x + bird_image.width();
}
	
