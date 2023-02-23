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
	
	void setPos(int x, int y);
	void setSize(int x, int y);
	void setColor(int color);
	void setState(bool active);

	Vector2 getPos();
	int getColor();
	Vector2 getSize();
	bool getState();

	
};


