#pragma once

#include "raylib.h"

class Brick
{
private:
	Vector2 pos;
	Vector2 size;
	int radius;
	int color;

public:
	Brick();
	~Brick();
};


