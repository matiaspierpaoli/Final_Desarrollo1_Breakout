#pragma once
#include "Brick.h"

class Level
{
private:

public:
	Level();
	~Level();

	void setMapLevel1(int rows, int columns, Brick* bricks[][6]);
};
