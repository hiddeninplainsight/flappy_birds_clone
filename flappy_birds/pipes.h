#ifndef PIPES_H
#define PIPES_H

#include <sdl_cpp/widgets/widgets.h>
#include "game_object.h"

class pipes : public game_object
{
private:
	sdl::widgets::image top_pipe_image;
	sdl::widgets::image bottom_pipe_image;
public:

	pipes(int x);
	void update_position() override;
	int bottom_of_top_pipe_y();
	int top_of_bottom_pipe_y();
	int pipes_x();
};

#endif

