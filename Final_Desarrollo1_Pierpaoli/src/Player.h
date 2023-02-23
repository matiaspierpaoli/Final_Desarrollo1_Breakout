#pragma once

#include "raylib.h"

class Player
{
private:
	Vector2 pos;
	Vector2 size;
	int speed;
	int lives;

public:
	Player();
	~Player();

	void setPos(int x, int y);
	void setSize(int x, int y);
	void setSpeed(int speed);
	void setLives(int lives);

	Vector2 getPos();
	Vector2 getSize();
	int getLives();


	void moveLeft();
	void moveRight();
};
