#include "PowerUp.h"

namespace BreakoutGame
{
	PowerUp::PowerUp(Vector2 _pos, Vector2 _size, bool _active, TypeOfPowerUp _typeOfPowerUp, Texture2D _texture)
	{
		pos = _pos;
		size = _size;
		active = _active;
		typeOfPowerUp = _typeOfPowerUp;
		texture = _texture;

		activationCondition = false;
		newPos = { 0,0 };
	}

	PowerUp::~PowerUp()
	{

	}

	void PowerUp::setPos(Vector2 _pos)
	{
		pos = _pos;
	}

	void PowerUp::setSize(Vector2 _size)
	{
		size = _size;
	}

	void PowerUp::setActive(bool _active)
	{
		active = _active;
	}

	void PowerUp::setTexture(Texture2D _texture)
	{
		texture = _texture;
	}

	void PowerUp::setTypeOfPowerUp(TypeOfPowerUp _typeOfPowerUp)
	{
		typeOfPowerUp = _typeOfPowerUp;
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
			activationCondition = false;

			newPos.x = static_cast<float>(GetRandomValue(1, GetScreenWidth() - 32));
			newPos.y = static_cast<float>(GetRandomValue(static_cast<int>(topLine + size.y + 50), static_cast<int>(botLine - size.y - 50)));

			// Bola - PowerUp
			if (CheckCollisionCircleRec(ballCenter, ballRadius, { newPos.x, newPos.y, size.x, size.y }))
				activationCondition = true;

			// Jugador - PowerUp
			if (CheckCollisionRecs({ playerPos.x, playerPos.y, playerSize.x, playerSize.y }, { newPos.x, newPos.y, size.x, size.y }))
				activationCondition = true;

		} while (activationCondition);

		setPos({ newPos.x, newPos.y });
	}

	void PowerUp::Draw()
	{
		DrawTexture(texture, static_cast<int>(pos.x), static_cast<int>(pos.y), WHITE);
	}
}