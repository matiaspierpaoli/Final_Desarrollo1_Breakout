#pragma once

#include "raylib.h"

class Brick
{
private:
	Vector2 pos;
	Vector2 size;
	bool active;
	int color;

public:
	Brick();
	~Brick();
	void locate(int x, int y);
};


