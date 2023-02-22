#include "Ball.h"

Ball::Ball()
{
	radius = 20;
	pos = { static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 2) };
	active = false;
	speed = { 0,0 };
}

Ball::~Ball()
{

}
