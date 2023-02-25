#pragma once

#include "raylib.h"

class Player
{
private:
	Vector2 pos;
	Vector2 size;
	int normalSpeed;
	int speed;
	int lives;
	int points;

	Texture2D texture;

public:
	Player();
	~Player();

	void setPos(int x, int y);
	void setSize(int x, int y);
	void setSpeed(int speed);
	void setLives(int lives);
	void setTexture(Texture2D texture);
	void setPoints(int points);

	void reduceLive();
	void addLife();

	Vector2 getPos();
	Vector2 getSize();
	int getLives();
	int getNormalSpeed();
	int getPoints();


	void moveLeft();
	void moveRight();

	void Draw();
};
