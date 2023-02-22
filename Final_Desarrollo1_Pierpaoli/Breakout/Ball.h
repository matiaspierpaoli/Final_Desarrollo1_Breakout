#pragma once

#include "raylib.h"

class Ball
{
private:
	Vector2 pos;
	Vector2 size;
	int radius;
	bool active;

public:
	Ball();
	~Ball();
};

