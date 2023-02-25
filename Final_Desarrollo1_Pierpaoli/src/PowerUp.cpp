#include "PowerUp.h"

PowerUp::PowerUp(Vector2 pos, Vector2 size, bool active, TypeOfPowerUp typeOfPowerUp, Texture2D texture)
{
	this->pos = pos;
	this->size = size;
	this->active = active;
	this->typeOfPowerUp = typeOfPowerUp;
	this->texture = texture;

	activationCondition = false;
	newPos = { 0,0 };
}

PowerUp::~PowerUp()
{

}

void PowerUp::setPos(Vector2 pos)
{
	this->pos = pos;
}

void PowerUp::setSize(Vector2 size)
{
	this->size = size;
}

void PowerUp::setActive(bool active)
{
	this->active = active;
}

void PowerUp::setTexture(Texture2D texture)
{
	this->texture = texture;
}

void PowerUp::setTypeOfPowerUp(TypeOfPowerUp typeOfPowerUp)
{
	this->typeOfPowerUp = typeOfPowerUp;
}

Vector2 PowerUp::getPos()
{
	return pos;
}

Vector2 PowerUp::getSize()
{
	return size;
}

bool PowerUp::getActive()
{
	return active;
}

Texture2D PowerUp::getTexture()
{
	return texture;
}

TypeOfPowerUp PowerUp::getTypeOfPowerUp()
{
	return typeOfPowerUp;
}

void PowerUp::setNewRndPos(Vector2 playerPos, Vector2 playerSize, Vector2 ballCenter, float ballRadius, int topLine, int botLine)
{
	do // Sale unicamente cuando no colisiona la nueva posicion con jugador y bola
	{
		newPos.x = GetRandomValue(1, GetScreenWidth() - 1);
		newPos.y = GetRandomValue(topLine + size.y + 50, botLine - size.y - 50);

		// Bola - PowerUp
		if (CheckCollisionCircleRec(ballCenter, ballRadius, {newPos.x, newPos.y, size.x, size.y}))
			activationCondition = true;

		// Jugador - PowerUp
		if (CheckCollisionRecs({ playerPos.x, playerPos.y, playerSize.x, playerSize.y }, { newPos.x, newPos.y, size.x, size.y }))
			activationCondition = true;

	} while (activationCondition);

	setPos({newPos.x, newPos.y});
}

void PowerUp::Draw()
{
	DrawTexture(texture, pos.x, pos.y, WHITE);
}