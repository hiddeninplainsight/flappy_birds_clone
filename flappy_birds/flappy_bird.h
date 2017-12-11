#ifndef FLAPPY_BIRD_H
#define FLAPPY_BIRD_H

#include "game_object.h"
#include <sdl_cpp/widgets/widgets.h>

class flappy_bird : public game_object
{
private:
	sdl::widgets::image bird_image{10, 0, "bird.png"};
	sdl::widgets::key space_key;
	
public:
	flappy_bird(int key);
	void update_position() override;
	int top_y();
	int bottom_y();
	int face_x();
};

#endif
