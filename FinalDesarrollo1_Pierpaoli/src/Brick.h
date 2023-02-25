#pragma once

#include "raylib.h"

class Brick
{
private:
	Vector2 pos;
	Vector2 size;
	bool active;

	Texture2D texture;

public:
	Brick(Vector2 pos, Vector2 size, bool active, Texture2D texture);
	~Brick();

	void setPos(int x, int y);
	void setSize(int x, int y);
	void setActive(bool active);
	void setTexture(Texture2D texture);

	Vector2 getPos();
	Vector2 getSize();
	bool getActive();

	void Draw();
};



