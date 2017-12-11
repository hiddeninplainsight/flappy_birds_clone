#include "pipes.h"

pipes::pipes(int x)
	: top_pipe_image{x, 0, "top_pipe.png"}
	, bottom_pipe_image{x, 0, "bottom_pipe.png"}
{
	bottom_pipe_image.location.y = 600 - bottom_pipe_image.height();
}

void pipes::update_position()
{
	top_pipe_image.location.x -= 4;
	bottom_pipe_image.location.x -= 4;
	
	if(top_pipe_image.location.x + top_pipe_image.width() < 0)
	{
		top_pipe_image.location.x = 800;
		bottom_pipe_image.location.x = 800;
	}
}

int pipes::bottom_of_top_pipe_y()
{
	return top_pipe_image.height();
}

int pipes::top_of_bottom_pipe_y()
{
	return bottom_pipe_image.location.y;
}

int pipes::pipes_x()
{
	return top_pipe_image.location.x;
}

