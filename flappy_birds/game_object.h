#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

class game_object
{
public:
	virtual ~game_object() = default;
	virtual void update_position() = 0;
};

#endif
