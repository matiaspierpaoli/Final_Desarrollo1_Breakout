#include "Brick.h"

Brick::Brick()
{
	active = true;
	texture = { NULL };
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

void Brick::setTexture(Texture2D texture)
{
	this->texture = texture;
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

void Brick::Draw()
{
	DrawRectangle(pos.x, pos.y, size.x, size.y, WHITE);
	DrawTexture(texture, pos.x, pos.y, WHITE);
}

