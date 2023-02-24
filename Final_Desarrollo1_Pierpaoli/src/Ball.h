#pragma once

#include "raylib.h"

class Ball
{
private:
	Vector2 pos;
	Vector2 speed;
	int radius;
	bool active;

	Texture2D texture;

public:
	Ball(Vector2 pos, Vector2 speed, int radius, bool active, Texture2D texture);
	~Ball();

	void setPos(int x, int y);
	void setSpeed(Vector2 speed);
	void setActive(bool active);
	void setTexture(Texture2D texture);

	int getRadius();
	Vector2 getPos();
	bool getActive();
	Vector2 getSpeed();
	Texture2D getTexture();

	void move();

	void changeYDirection();
	void changeXDirection();

	bool checkCollisionWithWalls(int linePosY);
	void checkCollisionWithPlayer(Vector2 playerPos, Vector2 playerSize, Sound ballSound);

	void reset();

	void Draw();
};

