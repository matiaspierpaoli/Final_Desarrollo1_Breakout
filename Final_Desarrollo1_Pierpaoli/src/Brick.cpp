#include "Brick.h"

Brick::Brick()
{

	color = GetRandomValue(0, 4);
	size = { static_cast<float>(GetScreenWidth()) / 10 ,
			static_cast<float>(GetScreenHeight()) / 10 };
	active = true;

}

Brick::~Brick()
{
}

void Brick::setPos(int x, int y)
{
	this->pos.x = x;
	this->pos.y = y;
}

Vector2 Brick::getPos()
{
	return pos;
}
