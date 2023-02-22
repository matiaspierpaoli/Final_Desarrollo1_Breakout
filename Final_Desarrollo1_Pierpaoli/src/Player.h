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
};
