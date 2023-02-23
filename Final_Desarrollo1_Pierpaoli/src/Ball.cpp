#include "Ball.h"

Ball::Ball()
{
	radius = 20;
	setPos(static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 2));
	active = false;
	speed = { 0,0 };
}

Ball::~Ball()
{

}

void Ball::setPos(int x, int y)
{
	this->pos.x = x;
	this->pos.y = y;
}

void Ball::setSpeed(Vector2 speed)
{
	this->speed = speed;
}

int Ball::getRadius()
{
	return radius;
}

Vector2 Ball::getPos()
{
	return pos;
}

void Ball::changeYDirection()
{
	speed.y *= -1;
}

void Ball::changeXDirection()
{
	speed.x *= -1;
}

bool Ball::checkCollisionWithWalls()
{
	if (pos.x - radius <= 0)	
		changeXDirection();
	
	if (pos.x + radius >= GetScreenWidth())	
		changeXDirection();
	
	if (pos.y - radius <= 0)	
		changeYDirection();
	
	if (pos.y + radius >= GetScreenHeight())			
		return true;
	

	return false;
}

void Ball::checkCollisionWithPlayer(Vector2 playerPos, Vector2 playerSize)
{
	if (CheckCollisionCircleRec(pos, static_cast<float>(radius), { playerPos.x, playerPos.y, playerSize.x, playerSize.y }))
	{
		if (speed.y > 0)
		{
			changeYDirection();
			speed.x = (pos.x - playerPos.x) / (playerSize.x / 2) * 500;
		}
	}
}

void Ball::reset(Vector2 playerPos, Vector2 playerSize)
{
	speed = { 0,0 };
	pos.x = playerPos.x + playerSize.x / 2;
	pos.y = playerPos.y - radius;
	active = false;
}


