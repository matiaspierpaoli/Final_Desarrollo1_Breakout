#pragma once

#include "raylib.h"

enum class TypeOfPowerUp
{
	AddLife,
	SubstractLife,
	MultiplyBall,
	SLowPlayerDown
};

class PowerUp
{
private:
	Vector2 pos;
	Vector2 size;
	bool active;
	TypeOfPowerUp typeOfPowerUp;


	Texture2D texture;

public:
	PowerUp(Vector2 pos, Vector2 size, bool active, TypeOfPowerUp typeOfPowerUp);
	~PowerUp();

	void setPos(Vector2 pos);
	void setSize(Vector2 size);
	void setActive(bool active);
	void setTexture(Texture2D texture);
	void setTypeOfPowerUp(TypeOfPowerUp typeOfPowerUp);

	Vector2 getPos();
	Vector2 getSize();
	bool getActive();
	Texture2D getTexture();
	TypeOfPowerUp getTypeOfPowerUp();

	void setNewRndPos(Vector2 playerPos, Vector2 playerSize, Vector2 ballCenter, float ballRadius, int topLine, int botLine);

	void Draw();
};
