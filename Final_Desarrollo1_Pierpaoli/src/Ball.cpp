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
