#include "Brick.h"

namespace BreakoutGame
{
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
		this->pos.x = static_cast<float>(x);
		this->pos.y = static_cast<float>(y);
	}

	void Brick::setSize(int x, int y)
	{
		this->size.x = static_cast<float>(x);
		this->size.y = static_cast<float>(y);
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
		DrawTexture(texture, static_cast<int>(pos.x), static_cast<int>(pos.y), WHITE);
	}
}