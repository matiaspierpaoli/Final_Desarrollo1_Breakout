#include "Brick.h"

Brick::Brick(Vector2 pos, Vector2 size, bool active, Texture2D texture)
{
	this->pos = pos;
	this->size = size;
	this->active = active;
	this->texture = texture;
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

void Brick::setActive(bool active)
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
	DrawTexture(texture, pos.x, pos.y, WHITE);
}