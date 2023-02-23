#include "Brick.h"

Brick::Brick()
{
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

void Brick::setSize(int x, int y)
{
	this->size.x = x;
	this->size.y = y;
}

void Brick::setColor(int color)
{
	this->color = color;
}

void Brick::setState(bool active)
{
	this->active = active;
}

Vector2 Brick::getPos()
{
	return pos;
}

int Brick::getColor()
{
	return color;
}

Vector2 Brick::getSize()
{
	return size;
}

bool Brick::getActive()
{
	return active;
}


