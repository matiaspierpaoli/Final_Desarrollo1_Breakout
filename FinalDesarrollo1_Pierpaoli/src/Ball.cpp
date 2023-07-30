#include "Ball.h"

namespace BreakoutGame
{
	Ball::Ball(Vector2 pos, Vector2 speed, int radius, bool active, Texture2D texture)
	{
		this->pos = pos;
		this->speed = speed;
		this->radius = radius;
		this->active = active;
		this->texture = texture;
	}

	Ball::~Ball()
	{

	}

	void Ball::setPos(int x, int y)
	{
		this->pos.x = static_cast<float>(x);
		this->pos.y = static_cast<float>(y);
	}

	void Ball::setSpeed(Vector2 speed)
	{
		this->speed = speed;
	}

	void Ball::setActive(bool active)
	{
		this->active = active;
	}

	void Ball::setTexture(Texture2D texture)
	{
		this->texture = texture;
	}

	int Ball::getRadius()
	{
		return radius;
	}

	Vector2 Ball::getPos()
	{
		return pos;
	}

	bool Ball::getActive()
	{
		return active;
	}

	Vector2 Ball::getSpeed()
	{
		return speed;
	}

	Texture2D Ball::getTexture()
	{
		return texture;
	}

	void Ball::move()
	{
		pos.x += speed.x * GetFrameTime();
		pos.y += speed.y * GetFrameTime();
	}

	void Ball::changeYDirection()
	{
		speed.y *= -1;
	}

	void Ball::changeXDirection()
	{
		speed.x *= -1;
	}

	bool Ball::checkCollisionWithWalls(int linePosY)
	{
		if (pos.x - radius <= 0) // Pared izquierda	
			changeXDirection();

		if (pos.x + radius >= GetScreenWidth())	// Pared derecha
			changeXDirection();

		if (pos.y - radius <= 0) // Pared superior	
			changeYDirection();

		if (pos.y + radius >= linePosY) // Pared inferior	
			return true;

		return false;
	}

	void Ball::checkCollisionWithPlayer(Vector2 playerPos, Vector2 playerSize, Sound ballSound)
	{
		// Circle - Rec de raylib
		if (CheckCollisionCircleRec(pos, static_cast<float>(radius), { playerPos.x, playerPos.y, playerSize.x, playerSize.y }))
		{
			if (speed.y > 0)
			{
				changeYDirection(); // Cambia la direccion en y, es decir, de abajo a arriba

				// Calcular el punto de colision
				float ballCollisionX = pos.x - (playerPos.x + playerSize.x / 2);

				// Modificar la velocidad en x de la bola en base al punto de colision
				if (ballCollisionX < 0)
				{
					// Al golpear en la zona izquierda de la plataforma se niega la velocidad en x
					if (speed.x > 0)
						speed.x = -speed.x;

				}
				else if (ballCollisionX > 0)
				{
					// Al golpear en la zona derecha de la plataforma la velocidad en x se mantiene
					if (speed.x < 0)
						speed.x = -speed.x;
				}
				else
				{
					// Al golpear en el medio de la plataforma la velocidad en x se mantiene				
				}

				speed.x *= 1.1f; // Se multiplica de a poco la velocidad para agregar dificultad

				PlaySound(ballSound);
			}
		}
	}

	void Ball::reset()
	{
		speed = { 0,0 };
		pos.x = static_cast<float>(GetScreenWidth() / 2);
		pos.y = static_cast<float>(GetScreenHeight() / 2);
		active = false;
	}

	void Ball::Draw()
	{
		DrawTexture(texture, static_cast<int>(pos.x) - 16, static_cast<int>(pos.y) - 16, WHITE);
	}
}