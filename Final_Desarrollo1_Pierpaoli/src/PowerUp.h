#pragma once

#include "raylib.h"

class PowerUp
{
private:
	Vector2 pos;
	Vector2 size;
	bool active;

	Texture2D texture;

public:
	PowerUp();
	~PowerUp();

	void setPos(Vector2 pos);
	void setSize(Vector2 size);
	void setActive(bool active);
	void setTexture(Texture2D texture);

	Vector2 getPos();
	Vector2 getSize();
	bool getActive();
	Texture2D getTexture();

	void Draw();
};
