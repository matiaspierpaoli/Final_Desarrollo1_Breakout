#pragma once

#include "raylib.h"

class Ball
{
private:
	Vector2 pos;
	Vector2 speed;
	int radius;
	bool active;

public:
	Ball();
	~Ball();

	void setPos(int x, int y);
	void setSpeed(Vector2 speed);
	
	int getRadius();
	Vector2 getPos();
	void move();
	bool checkCollisionWithWalls();
	void reset(Vector2 playerPos, Vector2 playerSize);
};
