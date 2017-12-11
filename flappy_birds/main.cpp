#include <iostream>
#include <sdl_cpp/widgets/widgets.h>
#include <vector>
#include "flappy_bird.h"
#include "pipes.h"

using namespace sdl::widgets;

class collision_detection
{
private:
	flappy_bird& bird;
	pipes& obstacle;

public:
	collision_detection(flappy_bird& inBird, pipes& inObstacle)
		: bird{inBird}
		, obstacle{inObstacle}
	{
	}
	
	bool collision_happened()
	{
		if(obstacle.pipes_x() < bird.face_x())
		{
			if(bird.top_y() < obstacle.bottom_of_top_pipe_y())
			{
				return true;
			}

			if(bird.bottom_y() > obstacle.top_of_bottom_pipe_y())
			{
				return true;
			}
		}
		return false;
	}
};

int main(int argc, char** argv)
{
	window_application application{argc, argv, "Flappy birds", 10, 10, 800, 600};
	flappy_bird player1{SDLK_SPACE};
	pipes obstacle[3]{{700}, {800}, {900}};
	
	std::vector<game_object*> objects;
	objects.push_back(&player1);
	for(auto&& o : obstacle)
	{
		objects.push_back(&o);
	}
	
	collision_detection collision{player1, obstacle[0]};
		
	while(!application.quit)
	{
		application.events.poll();
		
		if(!collision.collision_happened())
		{
			for(auto o : objects)
			{
				o->update_position();
			}
		}
		
		application.draw();
	}

	return 0;
}
