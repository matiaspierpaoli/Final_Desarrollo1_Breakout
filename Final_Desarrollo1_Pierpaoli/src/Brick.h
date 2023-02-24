#pragma once

#include "raylib.h"

class Brick
{
private:
	Vector2 pos;
	Vector2 size;
	bool active;
	int color;

	Texture2D texture;

public:
	Brick();
	~Brick();
	
	void setPos(int x, int y);
	void setSize(int x, int y);
	void setColor(int color);
	void setActive(bool active);
	void setTexture(Texture2D texture);

	Vector2 getPos();
	int getColor();
	Vector2 getSize();
	bool getActive();

	void Draw();
};


